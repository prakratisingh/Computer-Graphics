#include<GL/glut.h>
#include<stdio.h>
double xa = 6.0,xb = 12.0, ya = 1.0,yb = 10.0;
double xmin = 5.0,xmax = 10.0, ymin = 0.0,ymax = 10.0; 
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_LINE_LOOP);
    glColor3f(0.0,0.75,0.73);
    glVertex2f(5.0,5.0);
    glVertex2f(5.0,10.0);
    glVertex2f(10.0,10.0);
    glVertex2f(10.0,5.0);
glEnd();
glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex2f(0.0,6.0);
    glVertex2f(12.0,10.0);
glEnd();
glFlush();
}
void xupdate()
{
    xmin=xa; 
    ya = 
    xmax=xb;
}
void Cohen()
{
    double m;
    m = (yb-ya)/(xb-xa);
    printf("Slope of line: %f\n",m);
    if(xa<xmin)
    {
    xupdate(xmin);
    }
    if(xb>xmax)
    {
        xupdate(xmax);
    }

}
int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Cohen Sutherland Line clipping");
    gluOrtho2D(0.0,20.0,0.0,20.0);
    glutDisplayFunc(display);
    Cohen();
    glutMainLoop();
    return 0;
}