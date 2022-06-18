#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
float shear;
//value = -0.5
//shearing function for x
void XShearing3D(float *x)
{
    *x = *x+shear;
}
void YShearing3D(float *y)
{
    *y = *y+shear;
}
void ZShearing3D(float *z)
{
    *z = *z+shear;
}
void display(void)
{
    float Fig[12][3] =
        {
            // A1
            {0.2, 0.5, 0.0}, //Fig[0]
                             // G11
            {0.3, 0.6, -0.5}, //[1]
                              // B2
            {0.2, 0.2, 0.0}, //[2]
                             // H22
            {0.3, 0.3, -0.5}, //[3]
                              // C3
            {0.5, 0.2, 0.0}, //[4]
                             // I33
            {0.6, 0.3, -0.5}, //[5]
                              // D4
            {0.5, 0.3, 0.0}, //[6]
                             // J44
            {0.6, 0.4, -0.5}, //[7]
                              // E5
            {0.3, 0.3, 0.0}, //[8]
                             // K55
            {0.4, 0.4, -0.5}, //[9]
                              // F6
            {0.3, 0.5, 0.0}, //[10]
                             // L66
            {0.4, 0.6, -0.5} //[11]
        };
    // bottom
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3fv(Fig[3]);
    glVertex3fv(Fig[5]);
    glVertex3fv(Fig[4]);
    glVertex3fv(Fig[2]);
    glEnd();
    // left
    glBegin(GL_QUADS);
    glColor3f(4.0, 2.0, 0.1);
    glVertex3fv(Fig[8]);
    glVertex3fv(Fig[2]);
    glVertex3fv(Fig[0]);
    glVertex3fv(Fig[1]);
    glEnd();
    // back
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.3, 0.5);
    glVertex3fv(Fig[1]);
    glVertex3fv(Fig[11]);
    glVertex3fv(Fig[9]);
    glVertex3fv(Fig[3]);
    glEnd();
    // top
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.2, 0.6);
    glVertex3fv(Fig[0]);
    glVertex3fv(Fig[1]);
    glVertex3fv(Fig[11]);
    glVertex3fv(Fig[10]);
    glEnd();
    // right
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.5);
    glVertex3fv(Fig[10]);
    glVertex3fv(Fig[11]);
    glVertex3fv(Fig[9]);
    glVertex3fv(Fig[8]);
    glEnd();
    // top2
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.3, 0.4);
    glVertex3fv(Fig[8]);
    glVertex3fv(Fig[9]);
    glVertex3fv(Fig[7]);
    glVertex3fv(Fig[6]);
    glEnd();
    // right2
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3fv(Fig[6]);
    glVertex3fv(Fig[7]);
    glVertex3fv(Fig[5]);
    glVertex3fv(Fig[4]);
    glEnd();
    // face
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.3, 0.3);
    glVertex3fv(Fig[8]);
    glVertex3fv(Fig[10]);
    glVertex3fv(Fig[0]);
    glVertex3fv(Fig[2]);
    glVertex3fv(Fig[4]);
    glVertex3fv(Fig[6]);
    glEnd();
XShearing3D(&Fig[0][0]);
XShearing3D(&Fig[1][0]);
XShearing3D(&Fig[2][0]);
XShearing3D(&Fig[3][0]);
XShearing3D(&Fig[4][0]);
XShearing3D(&Fig[5][0]);
XShearing3D(&Fig[6][0]);
XShearing3D(&Fig[7][0]);
XShearing3D(&Fig[8][0]);
XShearing3D(&Fig[9][0]);
XShearing3D(&Fig[10][0]);
XShearing3D(&Fig[11][0]);
    // bottom
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3fv(Fig[3]);
    glVertex3fv(Fig[5]);
    glVertex3fv(Fig[4]);
    glVertex3fv(Fig[2]);
    glEnd();
    // left
    glBegin(GL_QUADS);
    glColor3f(4.0, 2.0, 0.1);
    glVertex3fv(Fig[8]);
    glVertex3fv(Fig[2]);
    glVertex3fv(Fig[0]);
    glVertex3fv(Fig[1]);
    glEnd();
    // back
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.3, 0.5);
    glVertex3fv(Fig[1]);
    glVertex3fv(Fig[11]);
    glVertex3fv(Fig[9]);
    glVertex3fv(Fig[3]);
    glEnd();
    // top
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.2, 0.6);
    glVertex3fv(Fig[0]);
    glVertex3fv(Fig[1]);
    glVertex3fv(Fig[11]);
    glVertex3fv(Fig[10]);
    glEnd();
    // right
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.5);
    glVertex3fv(Fig[10]);
    glVertex3fv(Fig[11]);
    glVertex3fv(Fig[9]);
    glVertex3fv(Fig[8]);
    glEnd();
    // top2
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.3, 0.4);
    glVertex3fv(Fig[8]);
    glVertex3fv(Fig[9]);
    glVertex3fv(Fig[7]);
    glVertex3fv(Fig[6]);
    glEnd();
    // right2
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3fv(Fig[6]);
    glVertex3fv(Fig[7]);
    glVertex3fv(Fig[5]);
    glVertex3fv(Fig[4]);
    glEnd();
    // face
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.3, 0.3);
    glVertex3fv(Fig[8]);
    glVertex3fv(Fig[10]);
    glVertex3fv(Fig[0]);
    glVertex3fv(Fig[2]);
    glVertex3fv(Fig[4]);
    glVertex3fv(Fig[6]);
    glEnd();
glFlush();
}
int main(int argc,char** argv)
{
    printf("PRAKRATI SINGH - 500082638\n");
    printf("Enter shearing factor: ");
    scanf("%f",&shear);
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(900, 900);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Shearing");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}