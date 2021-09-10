#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define carbon 51, 51, 51
#define kuning 251, 219, 20
#define anemo_white 249, 239, 229
#define a_white 249, 239, 229
#define golder 251, 188, 88
#define blue_light 166, 235, 231
#define neon 250, 55, 108
#define green 141, 191, 139


using namespace std;

const double PI = 3.14159265359;
double i = 0;
double i_kiri = 0;
double i_kanan = 0;
double i_bird1 = 0;
double i_bird2 = 0;
double i_bird3 = 0;
double i_scale1 = 1;
double i_scale2 = 1;
bool clicked = false;

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
    glOrtho(0, 1000, 600, 0, 1.f, -1.f);
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
        glVertex2d(1000, 0);
        glVertex2d(1000, 600);
        glVertex2d(0, 600);
    glEnd();
}
void bg_2(){
    glBegin(GL_POLYGON);
        glColor3ub(blue_light);
        glVertex2d(0, 0);
        glVertex2d(1000, 0);
        glVertex2d(1000, 600);
        glVertex2d(0, 600);
    glEnd();
}
void huruf_t(){
    glBegin(GL_POLYGON);
        glColor3ub(carbon);
        glVertex2d(240, 200);
        glVertex2d(340, 200);
        glVertex2d(340, 220);
        glVertex2d(240, 220);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(carbon);
        glVertex2d(280, 200);
        glVertex2d(300, 200);
        glVertex2d(300, 300);
        glVertex2d(280, 300);
    glEnd();
}
void huruf_o(){
    glBegin(GL_POLYGON);
        glColor3ub(carbon);
        glVertex2d(360, 220);
        glVertex2d(380, 200);
        glVertex2d(380, 300);
        glVertex2d(360, 280);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(carbon);
        glVertex2d(380, 280);
        glVertex2d(440, 280);
        glVertex2d(440, 300);
        glVertex2d(380, 300);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(carbon);
        glVertex2d(440, 200);
        glVertex2d(460, 220);
        glVertex2d(460, 280);
        glVertex2d(440, 300);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(carbon);
        glVertex2d(380, 200);
        glVertex2d(440, 200);
        glVertex2d(440, 220);
        glVertex2d(380, 220);
    glEnd();
}
void huruf_b(){
    glBegin(GL_POLYGON);
        glColor3ub(carbon);
        glVertex2d(480, 200);
        glVertex2d(500, 200);
        glVertex2d(500, 300);
        glVertex2d(480, 280);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(carbon);
        glVertex2d(500, 240);
        glVertex2d(540, 240);
        glVertex2d(540, 260);
        glVertex2d(500, 260);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(carbon);
        glVertex2d(540, 240);
        glVertex2d(560, 260);
        glVertex2d(560, 280);
        glVertex2d(540, 300);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(carbon);
        glVertex2d(500, 280);
        glVertex2d(540, 280);
        glVertex2d(540, 300);
        glVertex2d(500, 300);
    glEnd();
}
void huruf_i(){
    glBegin(GL_POLYGON);
        glColor3ub(carbon);
        glVertex2d(580, 200);
        glVertex2d(600, 200);
        glVertex2d(600, 220);
        glVertex2d(580, 220);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(carbon);
        glVertex2d(580, 240);
        glVertex2d(600, 240);
        glVertex2d(600, 300);
        glVertex2d(580, 300);
    glEnd();
}
void dot(){
    glBegin(GL_POLYGON);
        glColor3ub(carbon);
        glVertex2d(620, 290);
        glVertex2d(630, 290);
        glVertex2d(630, 300);
        glVertex2d(620, 300);
    glEnd();
}
void huruf_a(){
    glBegin(GL_POLYGON);
        glColor3ub(carbon);
        glVertex2d(650, 300);
        glVertex2d(670, 300);
        glVertex2d(706, 202);
        glVertex2d(690, 202);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(carbon);
        glVertex2d(691, 202);
        glVertex2d(711, 202);
        glVertex2d(747.5, 300);
        glVertex2d(731, 300);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(carbon);
        glVertex2d(660, 275);
        glVertex2d(672, 261);
        glVertex2d(725.5, 261);
        glVertex2d(737, 275);
    glEnd();
}
void kotak(){
    glBegin(GL_POLYGON);
        glColor3ub(carbon);
        glVertex2d(209, 367);
        glVertex2d(778, 367);
        glVertex2d(778, 377);
        glVertex2d(209, 377);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(carbon);
        glVertex2d(209, 125);
        glVertex2d(778, 125);
        glVertex2d(778, 135);
        glVertex2d(209, 135);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(carbon);
        glVertex2d(209, 125);
        glVertex2d(219, 125);
        glVertex2d(219, 377);
        glVertex2d(209, 377);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(carbon);
        glVertex2d(768, 125);
        glVertex2d(778, 125);
        glVertex2d(778, 377);
        glVertex2d(768, 377);
    glEnd();
}
void hiasan_1(){
    glBegin(GL_POLYGON);
        glColor3ub(carbon);
        glVertex2d(30, 245);
        glVertex2d(170, 245);
        glVertex2d(170, 255);
        glVertex2d(30, 255);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(carbon);
        glVertex2d(95, 180);
        glVertex2d(105, 180);
        glVertex2d(105, 320);
        glVertex2d(95, 320);
    glEnd();
}
void hiasan_2(){
    glBegin(GL_POLYGON);
        glColor3ub(carbon);
        glVertex2d(817, 245);
        glVertex2d(957, 245);
        glVertex2d(957, 255);
        glVertex2d(817, 255);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(carbon);
        glVertex2d(882, 180);
        glVertex2d(892, 180);
        glVertex2d(892, 320);
        glVertex2d(882, 320);
    glEnd();
}
void bird1(){
    glBegin(GL_TRIANGLES);
        glColor3ub(kuning);
        glVertex2d(1, 1);
        glVertex2d(1, 27);
        glVertex2d(25, 14);
    glEnd();
}
void bird2(){
    glBegin(GL_TRIANGLES);
        glColor3ub(kuning);
        glVertex2d(1, 42);
        glVertex2d(1, 68);
        glVertex2d(25, 55);
    glEnd();
}
void bird3(){
    glBegin(GL_TRIANGLES);
        glColor3ub(kuning);
        glVertex2d(1, 82);
        glVertex2d(1, 108);
        glVertex2d(25, 95);
    glEnd();
}
double rling = 50;
int segment = 100;
GLfloat angel;
void lingkaran_1(){
    glPushMatrix();
        glTranslatef(100 ,516, 0); // Bergeser
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(neon);
        // glVertex2d(100,516);
        glVertex2d(0,0);
        for(int i =0; i<= segment; i++){
            angel = i * 2.f * PI / segment;
            glVertex2f(cos(angel) * rling, sin(angel) * rling);
        }
    glEnd();
    glPopMatrix();
}
void lingkaran_2(){
    glPushMatrix();
        glTranslatef(900 ,516, 0); // Bergeser
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(green);
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
    glPushMatrix();
        glTranslatef(0, i+=0.02, 0); // Bergeser
        if (i > 60) i=-60;
        huruf_t();
        huruf_o();
        huruf_b();
        huruf_i();
        dot();
        huruf_a();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(100, 250, 0); // Bergeser ke kanan 100
        // glRotatef((double)glfwGetTime()*30, 0, 0, 1); // Berputar 30 derajat anticlockwise pada titik pusat (0,0)
        glRotatef(i_kiri+=0.1, 0, 0, 1); // Berputar 30 derajat anticlockwise pada titik pusat (0,0)
        glTranslatef(-100, -250, 0); // Bergeser ke kanan 100
        hiasan_1();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(897, 250, 0); // Bergeser ke kanan 897
        // glRotatef((double)glfwGetTime()*30, 0, 0, 1); // Berputar 30 derajat anticlockwise pada titik pusat (0,0)
        glRotatef(i_kanan-=0.1, 0, 0, 1); // Berputar 30 derajat anticlockwise pada titik pusat (0,0)
        glTranslatef(-897, -250, 0); // Bergeser ke kanan 100
        hiasan_2();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(i_bird1+=0.5, 0, 0); // Bergeser ke kanan 897
        if (i_bird1 > 1000) i_bird1=-10;
        bird1();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(i_bird2+=0.4, 0, 0); // Bergeser ke kanan 897
        if (i_bird2 > 1000) i_bird2=0;
        bird2();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(i_bird3+=0.45, 0, 0); // Bergeser ke kanan 897
        if (i_bird3 > 1000) i_bird3=0;
        bird3();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(100 ,516, 0);
        i_scale1 += 0.0005;
        glScalef(i_scale1,i_scale1,1);
        if (i_scale1 > 1.8) i_scale1=1;
        glTranslatef(-100 ,-516, 0);
        lingkaran_1();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(900 ,516, 0);
        i_scale2 += 0.0005;
        glScalef(i_scale2,i_scale2,1);
        if (i_scale2 > 2) i_scale2=1;
        glTranslatef(-900 ,-516, 0);
        lingkaran_2();
    glPopMatrix();
}

int main(void){
    //Window
    GLFWwindow *window;
    glfwSetErrorCallback(error_callback);

    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(1000, 600, "NAMA - G64180065", NULL, NULL);

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

        kotak();
        show();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    //Fungsi Exit
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
