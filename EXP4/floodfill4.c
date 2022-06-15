#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
void init()
{
    glViewport(0, 0, 600, 600);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 600.0, 0.0, 600.0);
    glMatrixMode(GL_MODELVIEW);
}
void Setpixel(int x, int y, float col[3])
{
    glBegin(GL_POINTS);
    glColor3fv(col);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}
void floodfill(int x, int y, float oldcol[3], float newcol[3])
{
    float pixel[3];
    glReadPixels(x,y,1,1,GL_RGB,GL_FLOAT,pixel);
    if (pixel[0] == oldcol[0] && pixel[1] == oldcol[1] && pixel[2] == oldcol[2])
    {
        Setpixel(x, y, newcol);
        floodfill(x + 1, y, oldcol, newcol);
        floodfill(x - 1, y, oldcol, newcol);
        floodfill(x, y + 1, oldcol, newcol);
        floodfill(x, y - 1, oldcol, newcol);
    }
    return;
}
void display(void)
{
    float oldcol[3] = {1.0, 0.0, 0.0};
    float newcol[3] = {0.4, 0.7, 0.0};
    int fig[4][2] =
        {
            {200, 350},
            {200, 440},
            {270, 440},
            {270, 350},
        };
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glColor3fv(oldcol);
        glVertex2iv(fig[0]);
        glVertex2iv(fig[1]);
        glVertex2iv(fig[2]);
        glVertex2iv(fig[3]);
    glEnd();
    floodfill(fig[0][0],fig[0][1], oldcol, newcol);
    glFlush();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Flood Fill Algorithm");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}