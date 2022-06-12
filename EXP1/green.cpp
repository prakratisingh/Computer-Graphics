#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
void display() //user defined display function 
{
   glClear(GL_COLOR_BUFFER_BIT);
   glFlush(); //Empties all the buffers 
}
void init() //It allows application to get Command line input. 
            //It also sets the state variables.
            //It sets OpenGL state.
{
   glClearColor(0.0, 1.0, 0.0, 1.0); //glClearColor(red,green,blue,alpha)
}
int main(int argc, char** argv) //We define the callback function in main
                               // We open one or more windows with the 
                               //required properties
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_RGB); //This requests properties for the window. 
                                 //(RGB color,Single buffering)
   glutInitWindowPosition(200, 100); //defining window properties
   glutInitWindowSize(500, 500); //This is the window size in pixels.
                                // This makes the window in the mentioned size.
   glutCreateWindow("green window"); //This creates window with the given title 
   glutDisplayFunc(display); //This is the display callback statement
   init(); 
   glutMainLoop(); //required to enter the infinite event loop
   return 0;
}