#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
// reflection function along x axis
void XReflection(float *x, float *y)
{
    *x = -(*x);
}
// reflection function along origin
void OReflection(float *x, float *y)
{
    *x = -(*x);
    *y = -(*y);
}
// reflection function along y axis
void YReflection(float *x, float *y)
{
    *y = -(*y);
}
void display(void)
{
    float X1,Y1,X2,Y2,X3,Y3,X4,Y4;
    X1 = 0.1;
    Y1 = 0.1;
    X2 = 0.5;
    Y2 = 0.1;
    X3 = 0.4;
    Y3 = 0.2;
    X4 = 0.2;
    Y4 = 0.2;
    glBegin(GL_POLYGON);
    glVertex2f(X1, Y1);
    glVertex2f(X2, Y2);
    glVertex2f(X3, Y3);
    glVertex2f(X4, Y4);
    glEnd();
    glFlush();
    OReflection(&X1, &Y1);
    OReflection(&X2, &Y2);
    OReflection(&X3, &Y3);
    OReflection(&X4, &Y4);
    glBegin(GL_POLYGON);
    glVertex2f(X1, Y1);
    glVertex2f(X2, Y2);
    glVertex2f(X3, Y3);
    glVertex2f(X4, Y4);
    glEnd();
    glFlush();
}
int main(int argc, char **argv)
{
    printf("PRAKRATI SINGH - 500082638\n");
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 700);
    glutCreateWindow("Reflection");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
