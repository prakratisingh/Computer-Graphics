#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int rad;
int Xc = 500,Yc = 500;
void display(void)
{
    float theta = 0;
    float Etheta = 360;
    float x = 0 , y=0;
    glBegin(GL_POINTS);
    while(theta<=Etheta)
    {
        x = Xc + (rad*cos(theta));
        y = Yc + (rad*sin(theta));
        glVertex2f(x,y);
        theta = theta + 0.001;
    }
    glEnd();
    glFlush();
}
int main(int argc, char **argv)
{
    printf("PRAKRATI SINGH - 500082638\n");
    printf("Enter radius of the circle: \n");
    scanf("%d", &rad);
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