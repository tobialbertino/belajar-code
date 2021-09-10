#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>

static void error_callback(int error, const char *description){
    fputs(description, stderr);
}
static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods){
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
void setup_viewport(GLFWwindow *window){
    // setting viewports size, projection etc
    float ratio;
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    ratio = width / (float)height;
    glViewport(0, 0, width, height);

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 800, 800, 0, 1.f, -1.f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void display(){
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f); //warna background
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
    glBegin(GL_TRIANGLES);
    glColor3d(0, 255, 0);
    glVertex2d(300, 100);
    glVertex2d(500, 400);
    glVertex2d(100, 400);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3d(255, 255, 255);
    glVertex2d(700, 400);
    glVertex2d(700, 700);
    glVertex2d(300, 700);
    glEnd();
}

int main(void){
    //Window
    GLFWwindow *window;
    glfwSetErrorCallback(error_callback);

    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(800, 800, "Pertemuan 2", NULL, NULL);

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
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    //Fungsi Exit
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
