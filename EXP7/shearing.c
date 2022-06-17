#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
float shear;
//shearing function for x
void XShearing(float *x)
{
    *x = *x+shear;
}
void YShearing(float *y)
{
    *y = *y+shear;
}
void display(void)
{
    float X1,Y1,X2,Y2,X3,Y3,X4,Y4,X5,Y5;
    X1 = 0.3;
    Y1 = 0.1;
    X2 = 0.1;
    Y2 = 0.3;
    X3 = 0.2;
    Y3 = 0.4;
    X4 = 0.5;
    Y4 = 0.4;
    X5 = 0.6;
    Y5 = 0.3;
    glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_POLYGON);
    glVertex2f(X1,Y1);
    glVertex2f(X2,Y2);
    glVertex2f(X3,Y3);
    glVertex2f(X4,Y4);
    glVertex2f(X5,Y5);
    glEnd();
XShearing(&X1);
XShearing(&X2);
XShearing(&X3);
XShearing(&X4);
XShearing(&X5);
glBegin(GL_POLYGON);
    glVertex2f(X1,Y1);
    glVertex2f(X2,Y2);
    glVertex2f(X3,Y3);
    glVertex2f(X4,Y4);
    glVertex2f(X5,Y5);
    glEnd();
YShearing(&Y1);
YShearing(&Y2);
YShearing(&Y3);
YShearing(&Y4);
YShearing(&Y5);
glBegin(GL_POLYGON);
    glVertex2f(X1,Y1);
    glVertex2f(X2,Y2);
    glVertex2f(X3,Y3);
    glVertex2f(X4,Y4);
    glVertex2f(X5,Y5);
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

