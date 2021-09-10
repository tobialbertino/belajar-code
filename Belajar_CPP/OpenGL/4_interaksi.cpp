#include <GLFW/glfw3.h>
#include <iostream>
#include <list>
#include <iterator>

using namespace std;

/*
 * CLASSES DECLARATION
 */

// Rectangle class
class Rectangle{
public:
    double x=200, y=200;
    double prevY = 0;
    int red = 255, green = 255, blue = 255;
    int size = 20;

    void display()
    {
        glBegin(GL_POLYGON);
            glColor3ub(red, green, blue);
            glVertex2f(-size + x,  size + y);
            glVertex2f( size + x,  size + y);
            glVertex2f( size + x, -size + y);
            glVertex2f(-size + x, -size + y);
        glEnd();
    }
    GLboolean isRectangleSelected(double xpos, double ypos){
        double left = x - size;
        double right = x + size;
        double top = y + size;
        double bottom = y - size;

        if((xpos > left) && (xpos < right) && (ypos < top) && (ypos > bottom))
            return GL_TRUE;
        else
            return GL_FALSE;
    }
    void doIfSelected(double xpos, double ypos){
        if(isRectangleSelected(xpos, ypos) == GL_TRUE)
            red = blue = 0;
        else
            red = blue = 255;
    }
    void doIfKeyPressed(int key, int action){
        if (key == GLFW_KEY_UP && action == GLFW_PRESS)
            y-=10;
        if (key == GLFW_KEY_DOWN && action == GLFW_PRESS)
            y+=10;
        if (key == GLFW_KEY_LEFT && action == GLFW_PRESS)
            x-=10;
        if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
            x+=10;
    }
    void doIfClicked(int button, int action, double xpos, double ypos){
        if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS){
            x = xpos;
            y = ypos;
        }
    }
};
Rectangle rect;

/*
 * CALLBACKS FUNCTIONS
 */
static void error_callback(int error, const char* description) {
    //fputs(description);
}

// Callback untuk merespons penekanan kunci pada keyboard
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
    rect.doIfKeyPressed(key, action);
}

// Callback untuk merespons perubahan posisi kursor
static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos){
    rect.doIfSelected(xpos, ypos);
}

// Callback untuk merespons penekanan tombol pada mouse
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods){
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    rect.doIfClicked(button, action, xpos, ypos);
}

/*
 * MAIN FUNCTION
 */
int main(void) {
    /* Creating Windows */
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit());
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    window = glfwCreateWindow(400, 400, "Interaction", NULL, NULL);
    if (!window){
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    /* Registering Callbacks */
    glfwSetKeyCallback(window, key_callback);
    glfwSetCursorPosCallback(window, cursor_position_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);


    /* MAIN LOOP */
    while (!glfwWindowShouldClose(window)){
        /* Preparing Frame Creation */
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float) height;
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, 400, 400 , 0 , 1.f, -1.f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        
        /* Object Drawing*/
        rect.display();
        
        /* Handling Frame Changes */
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    /* Destroying Windows */
    glfwDestroyWindow(window);
    glfwTerminate();
    //exit(EXIT_SUCCESS);
}