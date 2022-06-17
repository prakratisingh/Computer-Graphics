#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
float xtranslation,ytranslation;
//rotation function
void Translation(float *x,float *y)
{
    float a = *x;
    float b = *y;
    *x = a+ xtranslation;
    *y = b+ ytranslation;
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
    glVertex2f(X1,Y1);
    glVertex2f(X2,Y2);
    glVertex2f(X3,Y3);
    glVertex2f(X4,Y4);
    glEnd();
glFlush();
Translation(&X1,&Y1);
Translation(&X2,&Y2);
Translation(&X3,&Y3);
Translation(&X4,&Y4);
glBegin(GL_POLYGON);
    glVertex2f(X1,Y1);
    glVertex2f(X2,Y2);
    glVertex2f(X3,Y3);
    glVertex2f(X4,Y4);
    glEnd();
glFlush();
}
int main(int argc,char** argv)
{
    printf("PRAKRATI SINGH - 500082638\n");
    printf("Enter translation factor for x ");
    scanf("%f",&xtranslation);
    printf("Enter translation factor for y ");
    scanf("%f",&ytranslation);
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 700);
    glutCreateWindow("Translation");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

