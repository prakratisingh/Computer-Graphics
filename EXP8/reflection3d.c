#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
// reflection function along xy plane
void XYReflection(float *z)
{
    *z = -(*z);
}
// reflection function along xz plane
void XZReflection(float *y)
{
    *y = -(*y);
}
// reflection function along yz plane
void YZReflection(float *x)
{
    *x = -(*x);
}
void display(void)
{
    float Fig[12][3] =
        {
            // A1
            {0.2, 0.5, 0.0}, //[0]
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

    YZReflection(&Fig[0][0]);
    YZReflection(&Fig[1][0]);
    YZReflection(&Fig[2][0]);
    YZReflection(&Fig[3][0]);
    YZReflection(&Fig[4][0]);
    YZReflection(&Fig[5][0]);
    YZReflection(&Fig[6][0]);
    YZReflection(&Fig[7][0]);
    YZReflection(&Fig[8][0]);
    YZReflection(&Fig[9][0]);
    YZReflection(&Fig[10][0]);
    YZReflection(&Fig[11][0]);

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
int main(int argc, char **argv)
{
    printf("PRAKRATI SINGH - 500082638\n");
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Reflection in 3D");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}