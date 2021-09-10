#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>

static void error_callback(int error, const char* description) {
    fputs(description, stderr);
    }
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, GL_TRUE);
    }

void setup_viewport(GLFWwindow* window)
{
    // setting viewports size, projection etc
    float ratio;
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    ratio = width / (float) height;
    glViewport(0, 0, width, height);

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 800, 800, 0, 1.f, -1.f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display()  {
    glClear(GL_COLOR_BUFFER_BIT);

    glFlush();
}

int main(void) {
    //Window
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);

    if (!glfwInit())exit(EXIT_FAILURE);
    window = glfwCreateWindow(800, 800, "Praktikum 3", NULL, NULL);

    if (!window){
        glfwTerminate();
        exit(EXIT_FAILURE);
        }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glfwSetKeyCallback(window, key_callback);

    while (!glfwWindowShouldClose(window)){
        setup_viewport(window);
        display();

        glPushMatrix();
        glTranslatef(100,0,0); // Bergeser ke kanan 100
        glBegin(GL_TRIANGLES);
            glColor3d(0, 255, 0);
            glVertex2d(400, 0);
            glVertex2d(350, 100);
            glVertex2d(450, 100);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glRotatef(30, 0, 0, 1); // Berputar 30 derajat (-anti)clockwise pada titik pusat (0,0)
        glTranslatef(100,0,0); // Bergeser ke kanan 100
        glTranslatef(0,200,0); // Bergeser ke bawah 200
        glBegin(GL_TRIANGLES);
            glColor3d(255, 0, 0);
            glVertex2d(400, 0);
            glVertex2d(350, 100);
            glVertex2d(450, 100);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glScalef(0.75,0.25,1); // Sumbu X diperkecil menjadi 0.75 dan sumbu Y diperkecil menjadi 0.25
        glRotatef(30, 0, 0, 1); // Berputar 30 derajat (-anti)clockwise pada titik pusat (0,0)
        glTranslatef(10,0,0); // Bergeser ke kanan 10
        glTranslatef(0,100,0); // Bergeser ke bawah 100
        glBegin(GL_TRIANGLES);
            glColor3d(0, 0, 255);
            glVertex2d(400, 0);
            glVertex2d(350, 100);
            glVertex2d(450, 100);
        glEnd();
        glPopMatrix();

        glfwSwapBuffers(window);
        glfwPollEvents();
        }

    //Fungsi Exit
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
