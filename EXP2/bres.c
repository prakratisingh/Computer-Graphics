#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int X1, Y1, X2, Y2, m;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    int x = X1;
    int y = Y1;
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    int dx = X2 - X1;
    int dy = Y2 - Y1;
    int P = (2 * dy) - dx;
    for(int i =0;i<dx;i++)
    {
        x++;
        if (P < 0)
        {
            P = P + 2 * dy;
        }
        else
        {
            P = P + (2 * dy) - (2 * dx);
            y++;
        }
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    }
    glFlush();
}
int main(int argc, char **argv)
{
    printf("PRAKRATI SINGH - 500082638\n");
    printf("Enter X1: \n");
    scanf("%d", &X1);
    printf("Enter Y1: \n");
    scanf("%d", &Y1);
    printf("Enter X2: \n");
    scanf("%d", &X2);
    printf("Enter Y2: \n");
    scanf("%d", &Y2);
    m = (Y2 - Y1) / (X2 - X1);
    if (m < 1)
    {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE);
        glutInitWindowSize(500, 400);
        glutInitWindowPosition(180, 154);
        glutCreateWindow("Bresenham's Algorithm");
        gluOrtho2D(0, 500, 0, 400);
        glutDisplayFunc(display);
        glutMainLoop();
    }
    else
    {
        printf("ALGO DOESN'T WORK FOR M>1");
    }
    return 0;
}