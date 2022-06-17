#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
float xscale,yscale;
//scaling function
void Scaling(float *x,float *y)
{
    float a = *x;
    float b = *y;
    *x = a*xscale;
    *y = b*yscale;
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
Scaling(&X1,&Y1);
Scaling(&X2,&Y2);
Scaling(&X3,&Y3);
Scaling(&X4,&Y4);
Scaling(&X5,&Y5);
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
    printf("Enter scaling factor for x: ");
    scanf("%f",&xscale);
    printf("Enter scaling factor for y: ");
    scanf("%f",&yscale);
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(600, 700);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Scaling");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

