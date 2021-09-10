#include <stdio.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>

static void grid(int x, int y)
{
    int i;
    glColor3ub(237, 29, 36);
    glBegin(GL_LINES);
    for(i=-x; i<=x; i++)
    {
        glVertex2f(i,-y);
        glVertex2f(i,y);
    }
    for(i=-y; i<=y; i++)
    {
        glVertex2f(-x,i);
        glVertex2f(x,i);
    }
    /*glColor3f(0.7,1,0.7);
     glVertex2f(-x,0);
     glVertex2f(x,0);
     glVertex2f(0,-y);
     glVertex2f(0,y);*/
    glEnd();
    
}

void display()
{
    grid(10,10);
}

int main(void) {
    //Window
    GLFWwindow* window;
//    glfwSetErrorCallback(error_callback);
    
    if (!glfwInit())exit(EXIT_FAILURE);
    window = glfwCreateWindow(640, 480, "Grafika Komputer", NULL, NULL);
    
    if (!window){
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
//    glfwSetKeyCallback(window, key_callback);
    
    while (!glfwWindowShouldClose(window)){
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);
        display();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    //Fungsi Exit
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}