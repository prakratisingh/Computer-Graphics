#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int x, y, r, xcen=500, ycen=450;
float p;
void putPixel(int x, int y)
{
    glBegin(GL_POINTS); //define the type of primitive which is passed as a parameter
    glVertex2i(x, y); 
    //gl-> library prefix , Vertex-> Root command, 2-> number of components , i-> data type
    glEnd();
    glFlush();
}
void display()
{
    x = 0;
    y = r;
    p = ((float) (5/4))-r;
    while(x<y)
    {
        x++;
        if(p<0)
        {
            p = p+(2*x)+1;
        }
        else
        {
            y--;
            p = p+(2*x)-(2*y)+1;
        }
        putPixel(xcen + x, ycen + y);
        putPixel(xcen + x, ycen - y);
        putPixel(xcen + y, ycen + x);
        putPixel(xcen + y, ycen - x);
        putPixel(xcen - x, ycen - y);
        putPixel(xcen - y, ycen - x);
        putPixel(xcen - x, ycen + y);
        putPixel(xcen - y, ycen + x);
    }
    glFlush(); //clears the buffer
}
int main(int argc, char **argv)
{
    printf("PRAKRATI SINGH - 500082638\n");
    printf("Enter radius of the circle: \n");
    scanf("%d", &r);
    glutInit(&argc, argv);             //initialises the glut library 
    glutInitDisplayMode(GLUT_SINGLE); //initialises mode of display
    glutInitWindowSize(1000, 1000); //initialises window size
    glutInitWindowPosition(0, 0);  //initialises window position
    glutCreateWindow("Mid Point Circle Drawing Algorithm"); //creating and naming the window by passing name of window
    gluOrtho2D(0, 1000, 0, 1000); //sets up 2D orthographic viewing region (L,R,T,B)
    glutDisplayFunc(display);    //calls the display function. Sets the callback function for display window
    glutMainLoop();             //infinite event loop
    return 0;
}