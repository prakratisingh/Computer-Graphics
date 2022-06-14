#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int x, y, rx, ry, dx, dy, xcen = 500, ycen = 400;
float p1, p2;
void putPixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}
void display()
{
    x = 0;
    y = ry;
    p1 = ((ry * ry) + ((rx * rx* 0.25)) - (ry * (rx * rx)));
    dx = (2 * ry * ry * x);
    dy = (2 * rx * rx * y);
    // region 1
    while (dx < dy)
    {
        putPixel(xcen + x, ycen + y);
        putPixel(xcen + x, ycen - y);
        putPixel(xcen - x, ycen + y);
        putPixel(xcen - x, ycen - y);
        if (p1 < 0)
        {
            x++;
            dx = dx + (2 * ry * ry);
            p1 = p1 + dx + (ry * ry);
        }
        else
        {
            x++;
            y--;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            p1 = p1 + dx + (ry * ry) - dy;
        }
    }
    // region 2
    p2 = (pow(ry,2)*pow((x+0.5),2)) + (pow(rx,2)*pow((y-1),2)) - (pow(rx,2)*pow(ry,2));
    while (y >= 0)
    {
        putPixel(xcen + x, ycen + y);
        putPixel(xcen + x, ycen - y);
        putPixel(xcen - x, ycen + y);
        putPixel(xcen - x, ycen - y);
        if (p2 > 0)
        {
            y--;
            dy = dy - (2 * (pow(rx, 2)));
            p2 = p2 - (dy + pow(rx, 2));
        }
        else
        {
            x++;
            y--;
            dy = dy - (2 * (pow(rx, 2)));
            dx = dx + (2 * (pow(ry, 2)));
            p2 = p2 + (dx - (dy + pow(rx, 2)));
        }
    }
    glFlush();
}
int main(int argc, char **argv)
{
    printf("PRAKRATI SINGH - 500082638\n");
    printf("Enter radius of major axis of the ellipse: \n");
    scanf("%d", &rx);
    printf("Enter radius of minor axis of the ellipse: \n");
    scanf("%d", &ry);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Mid Point Ellipse Drawing Algorithm");
    gluOrtho2D(0, 1000, 0, 1000);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}