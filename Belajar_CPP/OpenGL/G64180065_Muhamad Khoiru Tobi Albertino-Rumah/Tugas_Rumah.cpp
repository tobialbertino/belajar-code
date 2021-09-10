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
double i_scale = 0;
double i_mid = 0;

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
    glOrtho(0, 700, 500, 0, 1.f, -1.f);
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
        glColor3ub(golder);
        glVertex2d(0, 0);
        glVertex2d(700, 0);
        glVertex2d(700, 500);
        glVertex2d(0, 500);
    glEnd();
}
void bg_2(){
    glBegin(GL_POLYGON);
        glColor3ub(blue_light);
        glVertex2d(0, 0);
        glVertex2d(700, 0);
        glVertex2d(700, 500);
        glVertex2d(0, 500);
    glEnd();
}
void jalan1(){
    glBegin(GL_POLYGON);
        glColor3ub(86, 86, 86);
        glVertex2d(336.2, 441.8);
        glVertex2d(395.6, 408.2);
        glVertex2d(118.1, 247.1);
        glVertex2d(59, 280.4);
    glEnd();
}
void jalan2(){
    glBegin(GL_POLYGON);
        glColor3ub(86, 86, 86);
        glVertex2d(299, 420.2);
        glVertex2d(336.2, 441.8);
        glVertex2d(640.1, 266.3);
        glVertex2d(602.3, 244.4);
    glEnd();
}
void jalan1bg(){
    glBegin(GL_POLYGON);
        glColor3ub(63, 63, 63);
        glVertex2d(59, 280.4);
        glVertex2d(59, 285.2);
        glVertex2d(336.2, 446.6);
        glVertex2d(336.2, 441.8);
    glEnd();
}
void jalan2bg(){
    glBegin(GL_POLYGON);
        glColor3ub(89, 89, 92);
        glVertex2d(336.2, 441.8);
        glVertex2d(336.2, 446.6);
        glVertex2d(640.1, 271.1);
        glVertex2d(640.1, 266.3);
    glEnd();
}
void jalan1Soil(){
    glBegin(GL_POLYGON);
        glColor3ub(94, 70, 53);
        glVertex2d(59, 280.3);
        glVertex2d(59, 289.1);
        glVertex2d(336.2, 450.5);
        glVertex2d(336.2, 445.7);
    glEnd();
}
void jalan2Soil(){
    glBegin(GL_POLYGON);
        glColor3ub(80, 59, 44);
        glVertex2d(336.2, 445.7);
        glVertex2d(336.2, 450.5);
        glVertex2d(640.1, 275);
        glVertex2d(640.1, 270.2);
    glEnd();
}
void dasar1(){
    glBegin(GL_POLYGON);
        glColor3ub(230, 230, 230);
        glVertex2d(118.1, 247.1);
        glVertex2d(358.4, 386.6);
        glVertex2d(602.3, 244.4);
        glVertex2d(362.9, 104.9);
    glEnd();
}
void dasar3(){
    glBegin(GL_POLYGON);
        glColor3ub(164, 150, 119);
        glVertex2d(186.8, 250.1);
        glVertex2d(259.7, 292.1);
        glVertex2d(298.1, 270.8);
        glVertex2d(222.2, 229.7);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(164, 150, 119);
        glVertex2d(198.8, 215.6);
        glVertex2d(415.7, 338.6);
        glVertex2d(580.4, 242.6);
        glVertex2d(366.5, 118.4);
    glEnd();
}
void dasar2(){
    glBegin(GL_POLYGON);
        glColor3ub(157, 199, 87);
        glVertex2d(151.4, 229.4);
        glVertex2d(387.5, 366.5);
        glVertex2d(598.1, 244.4);
        glVertex2d(362.9, 107.3);
    glEnd();
}
void front1(){
    glBegin(GL_POLYGON);
        glColor3ub(223, 219, 197);
        glVertex2d(280.4, 236);
        glVertex2d(324.2, 261.5);
        glVertex2d(323.9, 172.7);
        glVertex2d(280.1, 147.5);
    glEnd();
}
void front2(){
    glBegin(GL_POLYGON);
        glColor3ub(223, 219, 197);
        glVertex2d(242, 213.8);
        glVertex2d(280.4, 236);
        glVertex2d(280.1, 233);
        glVertex2d(244.4, 212.3);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(223, 219, 197);
        glVertex2d(242, 213.8);
        glVertex2d(244.4, 212.3);
        glVertex2d(244.7, 130.1);
        glVertex2d(242, 125.6);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(223, 219, 197);
        glVertex2d(244.7, 130.1);
        glVertex2d(242, 125.6);
        glVertex2d(280.1, 147.5);
        glVertex2d(280.1, 150.5);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(223, 219, 197);
        glVertex2d(244.4, 169.7);
        glVertex2d(244.4, 173);
        glVertex2d(280.1, 193.4);
        glVertex2d(280.1, 190.1);
    glEnd();
}
void floor1() {
    glBegin(GL_POLYGON);
        glColor3ub(193, 189, 167);
        glVertex2d(244.4, 212.3);
        glVertex2d(280.4, 233);
        glVertex2d(290, 227.3);
        glVertex2d(254.3, 206.6);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(193, 189, 167);
        glVertex2d(244.4, 169.7);
        glVertex2d(280.4, 190.1);
        glVertex2d(290, 184.4);
        glVertex2d(254.3, 163.7);
    glEnd();
}
void floor2(){
    glBegin(GL_POLYGON);
        glColor3ub(193, 189, 167);
        glVertex2d(367.4, 191.6);
        glVertex2d(405.5, 213.5);
        glVertex2d(414.2, 206.9);
        glVertex2d(377.3, 185.9);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(244, 242, 233);
        glVertex2d(406.1, 213.8);
        glVertex2d(455, 241.1);
        glVertex2d(540.8, 191.6);
        glVertex2d(492.2, 163.4);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(193, 189, 167);
        glVertex2d(405.8, 255.2);
        glVertex2d(455.3, 282.8);
        glVertex2d(455, 271.1);
        glVertex2d(415.7, 249.5);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(193, 189, 167);
        glVertex2d(455.3, 282.8);
        glVertex2d(455, 271.1);
        glVertex2d(528.2, 228.8);
        glVertex2d(538.4, 234.8);
    glEnd();
}
void first_floor(){
    glBegin(GL_POLYGON);
        glColor3ub(193, 189, 167);
        glVertex2d(379.7, 228.5);
        glVertex2d(403.7, 242.6);
        glVertex2d(407.3, 240.5);
        glVertex2d(383, 226.7);
    glEnd();
}
void wall_small(){
    glBegin(GL_POLYGON);
        glColor3ub(179, 175, 150);
        glVertex2d(244.4, 212.3);
        glVertex2d(254.3, 206.6);
        glVertex2d(254.3, 167);
        glVertex2d(244.4, 173);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(179, 175, 150);
        glVertex2d(244.4, 169.7);
        glVertex2d(254.3, 163.7);
        glVertex2d(254.3, 124.1);
        glVertex2d(244.7, 129.8);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(179, 175, 150);
        glVertex2d(405.8, 255.2);
        glVertex2d(415.7, 249.5);
        glVertex2d(415.7, 210.8);
        glVertex2d(405.8, 216.5);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(158, 150, 134);
        glVertex2d(528.2, 228.8);
        glVertex2d(538.4, 234.8);
        glVertex2d(538.1, 196.1);
        glVertex2d(527.9, 190.1);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(112, 102, 91);
        glVertex2d(379.7, 228.5);
        glVertex2d(383, 226.7);
        glVertex2d(382.7, 191.9);
        glVertex2d(379.4, 193.7);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(158, 150, 134);
        glVertex2d(377.9, 227.6);
        glVertex2d(379.7, 228.5);
        glVertex2d(379.7, 193.4);
        glVertex2d(377.6, 191);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(179, 175, 150);
        glVertex2d(406.1, 169.4);
        glVertex2d(406.1, 213.8);
        glVertex2d(492.2, 163.4);
        glVertex2d(492.5, 119.3);
    glEnd();
}
void wall1() {
    glBegin(GL_POLYGON);
        glColor3ub(179, 175, 150);
        glVertex2d(323.9, 172.7);
        glVertex2d(324.2, 261.2);
        glVertex2d(388.4, 223.4);
        glVertex2d(388.7, 134.9);
    glEnd();
}
void wall2() {
    glBegin(GL_POLYGON);
        glColor3ub(233, 219, 197);
        glVertex2d(367.7, 149.9);
        glVertex2d(403.7, 170.9);
        glVertex2d(406.1, 169.4);
        glVertex2d(367.7, 147.2);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(233, 219, 197);
        glVertex2d(403.7, 170.9);
        glVertex2d(406.1, 169.4);
        glVertex2d(405.5, 216.2);
        glVertex2d(403.7, 212.3);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(233, 219, 197);
        glVertex2d(405.5, 216.2);
        glVertex2d(403.7, 212.3);
        glVertex2d(367.4, 191.3);
        glVertex2d(367.4, 194.3);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(233, 219, 197);
        glVertex2d(405.8, 216.5);
        glVertex2d(403.4, 212.3);
        glVertex2d(403.4, 256.7);
        glVertex2d(405.8, 255.2);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(233, 219, 197);
        glVertex2d(403.4, 212.3);
        glVertex2d(405.8, 216.5);
        glVertex2d(455, 244.1);
        glVertex2d(455, 241.1);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(233, 219, 197);
        glVertex2d(403.4, 256.7);
        glVertex2d(405.8, 255.2);
        glVertex2d(455.3, 282.8);
        glVertex2d(455.3, 285.8);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(179, 175, 150);
        glVertex2d(455.3, 282.8);
        glVertex2d(455.3, 285.8);
        glVertex2d(540.8, 236.3);
        glVertex2d(538.4, 234.8);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(179, 175, 150);
        glVertex2d(540.8, 236.3);
        glVertex2d(538.4, 234.8);
        glVertex2d(538.1, 196.1);
        glVertex2d(540.8, 191.6);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(179, 175, 150);
        glVertex2d(538.1, 196.1);
        glVertex2d(540.8, 191.6);
        glVertex2d(455, 241.1);
        glVertex2d(455, 244.1);
    glEnd();
}
void atap(){
    glBegin(GL_POLYGON);
        glColor3ub(244, 242, 233);
        glVertex2d(242, 125.6);
        glVertex2d(323.9, 172.7);
        glVertex2d(453.8, 97.1);
        glVertex2d(371.9, 50);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(244, 242, 233);
        glVertex2d(367.7, 147.2);
        glVertex2d(406.1, 169.4);
        glVertex2d(492.5, 119.3);
        glVertex2d(453.8, 97.1);
    glEnd();
}
void door_1(){
    glBegin(GL_POLYGON);
        glColor3ub(66, 65, 67);
        glVertex2d(382.7, 227);
        glVertex2d(393.2, 233);
        glVertex2d(393.2, 203.3);
        glVertex2d(382.7, 197.3);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(66, 65, 67);
        glVertex2d(393.2, 233);
        glVertex2d(403.7, 239);
        glVertex2d(403.7, 209.3);
        glVertex2d(393.2, 203.3);
    glEnd();
}
void window_1(){
    glBegin(GL_POLYGON);
        glColor3ub(144, 202, 249);
        glVertex2d(285.5, 191.6);
        glVertex2d(317.3, 209.9);
        glVertex2d(317.3, 174.5);
        glVertex2d(285.5, 155.9);
    glEnd();
}
void window_2(){
    glPushMatrix();
        glTranslatef(0,41.7,0); // Bergeser ke kanan 100
        window_1();
    glPopMatrix();
}
void window_3(){
    glBegin(GL_POLYGON);
        glColor3ub(144, 202, 249);
        glVertex2d(254, 164.1);
        glVertex2d(288.8, 184.5);
        glVertex2d(288.8, 155.6);
        glVertex2d(254, 136.4);
    glEnd();
}
void window_4(){
    glPushMatrix();
        glTranslatef(0,42.8,0); // Bergeser ke kanan 100
        window_3();
    glPopMatrix();
}
void window_5(){
    glBegin(GL_POLYGON);
        glColor3ub(144, 202, 249);
        glVertex2d(377.6, 185.6);
        glVertex2d(411.8, 203.9);
        glVertex2d(410.6, 167.6);
        glVertex2d(377.6, 147.5);
    glEnd();
}
void window_6(){
    glBegin(GL_POLYGON);
        glColor3ub(144, 202, 249);
        glVertex2d(416.9, 206.9);
        glVertex2d(484.1, 167.9);
        glVertex2d(484.1, 129.8);
        glVertex2d(416.9, 169.1);
    glEnd();
}
void window_7(){
    glBegin(GL_POLYGON);
        glColor3ub(144, 202, 249);
        glVertex2d(415.7, 249.8);
        glVertex2d(455, 271.1);
        glVertex2d(455, 241.7);
        glVertex2d(415.7, 221);
    glEnd();
}
void window_8(){
    glBegin(GL_POLYGON);
        glColor3ub(144, 202, 249);
        glVertex2d(455, 271.1);
        glVertex2d(455, 241.7);
        glVertex2d(527.6, 199.7);
        glVertex2d(527.9, 228.8);
    glEnd();
}
void window_9(){
    glBegin(GL_POLYGON);
        glColor3ub(144, 202, 249);
        glVertex2d(336.2, 201.5);
        glVertex2d(345.2, 196.4);
        glVertex2d(345.2, 179.9);
        glVertex2d(336.2, 185);
    glEnd();
}
void window_10(){
    glPushMatrix();
        glTranslatef(18.6, -10.8, 0); // Bergeser ke kanan 100
        window_9();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0, 31.8, 0); // Bergeser ke kanan 100
        window_9();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(18.6, 21, 0); // Bergeser ke kanan 100
        window_9();
    glPopMatrix();
}
double rling = 50;
int segment = 100;
GLfloat angel;
void lingkaran_1(){
    glPushMatrix();
        glTranslatef(100 ,100, 0); // Bergeser
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(yellow);
        // glVertex2d(100,516);
        glVertex2d(0,0);
        for(int i =0; i<= segment; i++){
            angel = i * 2.f * PI / segment;
            glVertex2f(cos(angel) * rling, sin(angel) * rling);
        }
    glEnd();
    glPopMatrix();
}
void matahari(){
    glPushMatrix();
        glTranslatef(100 ,100, 0);
        i_scale += 0.0005;
        glScalef(i_scale,i_scale,1);
        if (i_scale > 1.8) i_scale=0.3;
        glTranslatef(-100 ,-100, 0);
        lingkaran_1();
    glPopMatrix();
}
void show(){
    jalan1();
    jalan2();
    jalan1Soil();
    jalan2Soil();
    jalan1bg();
    jalan2bg();
    dasar1();
    dasar2();
    dasar3();
    first_floor();
    window_3();
    window_4();
    window_5();
    window_7();
    window_8();
    wall1();
    door_1();
    wall_small();
    floor1();
    floor2();
    wall2();
    front1();
    front2();
    window_1();
    window_2();
    window_6();
    window_9();
    window_10();
    atap();
    
    glPushMatrix();
        glTranslatef(80, 80, 0); // Bergeser ke kanan 100
        // glRotatef((double)glfwGetTime()*30, 0, 0, 1); // Berputar 30 derajat anticlockwise pada titik pusat (0,0)
        glRotatef(i_mid -= 0.09, 0, 0, 1); // Berputar 30 derajat anticlockwise pada titik pusat (0,0)
        glTranslatef(-80, -80, 0); // Bergeser ke kanan 100
        matahari();
    glPopMatrix();
}

int main(void){
    //Window
    GLFWwindow *window;
    glfwSetErrorCallback(error_callback);

    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(700, 500, "Tugas_Rumah - G64180065", NULL, NULL);

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
