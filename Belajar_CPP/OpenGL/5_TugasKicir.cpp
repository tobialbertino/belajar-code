#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define a_white 249, 239, 229
#define anemo_white 249, 239, 229
#define blue 46, 190, 236
#define blue_light 166, 235, 231
#define carbon 51, 51, 51
#define golder 251, 188, 88
#define green 101, 204, 53
#define green_light 181, 221, 149
#define neon 250, 55, 108
#define orange 236, 114, 46
#define red 170, 16, 16
#define yellow 251, 219, 20

using namespace std;

const double PI = 3.14159265359;
bool clicked = false;
double i_left = 0;
double i_right = 0;
double i_mid = 0;
double i_scale = 0;

static void error_callback(int error, const char *description){
    fputs(description, stderr);
}
static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods){
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
// change background
//buat lampu
static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods){
    if(button == GLFW_MOUSE_BUTTON_LEFT)
        clicked=true;
    if(button == GLFW_MOUSE_BUTTON_RIGHT)
        clicked=false;
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
    glOrtho(0, 800, 700, 0, 1.f, -1.f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void display(){
    glClearColor(252.0f/255.0f, 255.0f/255.0f, 245.0f/255.0f, 1.0f); //warna background
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}
void bg_1(){
    glBegin(GL_POLYGON);
        glColor3ub(a_white);
        glVertex2d(0, 0);
        glVertex2d(800, 0);
        glVertex2d(800, 700);
        glVertex2d(0, 700);
    glEnd();
}
void bg_2(){
    glBegin(GL_POLYGON);
        glColor3ub(blue_light);
        glVertex2d(0, 0);
        glVertex2d(800, 0);
        glVertex2d(800, 700);
        glVertex2d(0, 700);
    glEnd();
}
void dasar_rumput(){
    glBegin(GL_POLYGON);
        glColor3ub(green);
        glVertex2d(0, 630);
        glVertex2d(800, 630);
        glVertex2d(800, 700);
        glVertex2d(0, 700);
    glEnd();
}
void dasar_segitiga(){
    glBegin(GL_TRIANGLES);
        glColor3ub(red);
        glVertex2d(222, 630);
        glVertex2d(578, 630);
        glVertex2d(400, 521);
    glEnd();
    glBegin(GL_TRIANGLES);
        glColor3ub(red);
        glVertex2d(32, 630);
        glVertex2d(268, 630);
        glVertex2d(150, 573);
    glEnd();
    glBegin(GL_TRIANGLES);
        glColor3ub(red);
        glVertex2d(534, 630);
        glVertex2d(770, 630);
        glVertex2d(652, 573);
    glEnd();
}
void dasar_tiang(){
    glBegin(GL_POLYGON);
        glColor3ub(orange);
        glVertex2d(386, 229);
        glVertex2d(410.5, 229);
        glVertex2d(431, 571);
        glVertex2d(371, 571);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(orange);
        glVertex2d(120, 630);
        glVertex2d(180, 630);
        glVertex2d(159.5, 288);
        glVertex2d(135, 288);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(orange);
        glVertex2d(624, 630);
        glVertex2d(684, 630);
        glVertex2d(663.5, 288);
        glVertex2d(639, 288);
    glEnd();
}
void kicir_left(){
    glBegin(GL_POLYGON);
        glColor3ub(carbon);
        glVertex2d(108, 434);
        glVertex2d(153.71, 434);
        glVertex2d(153.71, 309);
        glVertex2d(146.62, 309);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(carbon);
        glVertex2d(146.62, 309);
        glVertex2d(153.71, 309);
        glVertex2d(198, 184);
        glVertex2d(146.62, 184);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(carbon);
        glVertex2d(25, 264);
        glVertex2d(25, 312.15);
        glVertex2d(150, 312.15);
        glVertex2d(150, 305.12);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(carbon);
        glVertex2d(150, 305.12);
        glVertex2d(150, 312.15);
        glVertex2d(275, 348);
        glVertex2d(275, 305.12);
    glEnd();
}
void kicir_right(){
    glBegin(GL_POLYGON);
        glColor3ub(green_light);
        glVertex2d(612, 428);
        glVertex2d(657.71, 428);
        glVertex2d(657.71, 303);
        glVertex2d(650.62, 303);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(green_light);
        glVertex2d(650.62, 303);
        glVertex2d(657.71, 303);
        glVertex2d(702, 178);
        glVertex2d(650.62, 178);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(green_light);
        glVertex2d(529, 258);
        glVertex2d(529, 306.15);
        glVertex2d(654, 306.15);
        glVertex2d(654, 299.12);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(green_light);
        glVertex2d(654, 299.12);
        glVertex2d(654, 306.15);
        glVertex2d(779, 342);
        glVertex2d(779, 299.12);
    glEnd();
}
void kicir_mid(){
    glBegin(GL_POLYGON);
        glColor3ub(blue);
        glVertex2d(340.5, 428);
        glVertex2d(405, 428);
        glVertex2d(405, 253);
        glVertex2d(395, 253);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(blue);
        glVertex2d(395, 253);
        glVertex2d(405, 253);
        glVertex2d(467.5, 78);
        glVertex2d(395, 78);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(blue);
        glVertex2d(225, 189.5);
        glVertex2d(225, 258);
        glVertex2d(400, 258);
        glVertex2d(400, 248);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(blue);
        glVertex2d(400, 248);
        glVertex2d(400, 258);
        glVertex2d(575, 309);
        glVertex2d(575, 248);
    glEnd();
}
double rling = 50;
int segment = 100;
GLfloat angel;
void lingkaran_1(){
    glPushMatrix();
        glTranslatef(700 ,80, 0); // Bergeser
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(golder);
        // glVertex2d(100,516);
        glVertex2d(0,0);
        for(int i =0; i<= segment; i++){
            angel = i * 2.f * PI / segment;
            glVertex2f(cos(angel) * rling, sin(angel) * rling);
        }
    glEnd();
    glPopMatrix();
}
void show(){
    dasar_rumput();
    dasar_tiang();
    dasar_segitiga();
    glPushMatrix();
        glTranslatef(700 ,80, 0);
        i_scale += 0.0005;
        glScalef(i_scale,i_scale,1);
        if (i_scale > 1.8) i_scale=1;
        glTranslatef(-700 ,-80, 0);
        lingkaran_1();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(150, 309, 0); // Bergeser ke kanan 100
        // glRotatef((double)glfwGetTime()*30, 0, 0, 1); // Berputar 30 derajat anticlockwise pada titik pusat (0,0)
        glRotatef(i_left -= 0.1, 0, 0, 1); // Berputar 30 derajat anticlockwise pada titik pusat (0,0)
        glTranslatef(-150, -309, 0); // Bergeser ke kanan 100
        kicir_left();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(653, 303, 0); // Bergeser ke kanan 100
        // glRotatef((double)glfwGetTime()*30, 0, 0, 1); // Berputar 30 derajat anticlockwise pada titik pusat (0,0)
        glRotatef(i_right -= 0.095, 0, 0, 1); // Berputar 30 derajat anticlockwise pada titik pusat (0,0)
        glTranslatef(-653, -303, 0); // Bergeser ke kanan 100
        kicir_right();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(400, 253, 0); // Bergeser ke kanan 100
        // glRotatef((double)glfwGetTime()*30, 0, 0, 1); // Berputar 30 derajat anticlockwise pada titik pusat (0,0)
        glRotatef(i_mid -= 0.090, 0, 0, 1); // Berputar 30 derajat anticlockwise pada titik pusat (0,0)
        glTranslatef(-400, -253, 0); // Bergeser ke kanan 100
        kicir_mid();
    glPopMatrix();
}

int main(void){
    //Window
    GLFWwindow *window;
    glfwSetErrorCallback(error_callback);

    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(800, 700, "Kicir_Angin - G64180065", NULL, NULL);

    if (!window){
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glfwSetKeyCallback(window, key_callback);

    glfwSetMouseButtonCallback(window, mouse_button_callback);

    while (!glfwWindowShouldClose(window)){
        setup_viewport(window);
        display();
        if(clicked!=true) bg_1();
        if(clicked==true) bg_2();

        show();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    //Fungsi Exit
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
