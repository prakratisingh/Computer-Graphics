#include <GL/glut.h>
#include <stdio.h>
float x_pos = 1.0;  
float y_pos = 7.0;
int step = 0;
void display();
void reshape(int,int);
void timer(int);
//It allows application to get Command line input. 
//It also sets the state variables.
//It sets OpenGL state.
void init()
{
    glClearColor(0.0,0.0,0.0,0.1); //glClearColor(red,green,blue,alpha)
}
//user defined display function 
void display()
{
    glClear(GL_COLOR_BUFFER_BIT); 
    glLoadIdentity(); //ensures that each time we enter the projection mode, the matrix will be reset to identity matrix
                    //so the new viewing parameters are not combined with the previous ones.
//triangle A
glBegin(GL_POLYGON);
glColor3f(0.4, 0.2, 0.6);
    glVertex2f(x_pos+4,y_pos);
    glVertex2f(x_pos,y_pos);
    glVertex2f(x_pos+4,y_pos-4);
glEnd();
//quad B
glBegin(GL_QUADS);
glColor3f(0.4, 0.2, 0.6);
    glVertex2f(x_pos+4,y_pos);
    glVertex2f(x_pos,y_pos);
    glVertex2f(x_pos+3,y_pos+7);
    glVertex2f(x_pos+4,y_pos+5);
glEnd();
//quad C
glBegin(GL_QUADS);
glColor3f(0.4, 0.2, 0.6);
    glVertex2f(x_pos+8,y_pos+5);
    glVertex2f(x_pos+9,y_pos+7);
    glVertex2f(x_pos+12,y_pos);
    glVertex2f(x_pos+8,y_pos-4);
glEnd();
//triangle D
glBegin(GL_POLYGON);
glColor3f(0.4, 0.2, 0.6);
    glVertex2f(x_pos+8,y_pos);
    glVertex2f(x_pos+12,y_pos);
    glVertex2f(x_pos+8,y_pos-4);
glEnd();
//triangle
glBegin(GL_POLYGON);
glColor3f(0.9, 0.9, 0.9);
    glVertex2f(x_pos+4,y_pos+5);
    glVertex2f(x_pos+8,y_pos+5);
    glVertex2f(x_pos+6,y_pos+9);
glEnd();
//small triangle 1
glBegin(GL_POLYGON);
glColor3f(0.9, 0.0, 0.0);
    glVertex2f(x_pos+3,y_pos+7);
    glVertex2f(x_pos+4,y_pos+5);
    glVertex2f(x_pos+5,y_pos+7);
glEnd();
//small triangle 1'
glColor3f(0.9, 0.9, 0.9);
glBegin(GL_POLYGON);
    glVertex2f(x_pos+3,y_pos+7);
    glVertex2f(x_pos+4,y_pos+9);
    glVertex2f(x_pos+5,y_pos+7);
glEnd();
//small triangle 2
glColor3f(0.0, 0.0, 0.9);
glBegin(GL_POLYGON);
    glVertex2f(x_pos+4,y_pos+9);
    glVertex2f(x_pos+6,y_pos+9);
    glVertex2f(x_pos+5,y_pos+7);
glEnd();
//small triangle 2'
glColor3f(0.9, 0.9, 0.9);
glBegin(GL_POLYGON);
    glVertex2f(x_pos+4,y_pos+9);
    glVertex2f(x_pos+6,y_pos+9);
    glVertex2f(x_pos+5,y_pos+11);
glEnd();
//small triangle 3
glColor3f(0.9, 0.0, 0.0);
glBegin(GL_POLYGON);
    glVertex2f(x_pos+5,y_pos+11);
    glVertex2f(x_pos+6,y_pos+9);
    glVertex2f(x_pos+7,y_pos+11);
glEnd();
//small triangle 4
glColor3f(0.9, 0.9, 0.9);
glBegin(GL_POLYGON);
    glVertex2f(x_pos+5,y_pos+11);
    glVertex2f(x_pos+6,y_pos+13);
    glVertex2f(x_pos+7,y_pos+11);
glEnd();
//small triangle 5
glColor3f(0.9, 0.9, 0.9);
glBegin(GL_POLYGON);
    glVertex2f(x_pos+6,y_pos+9);
    glVertex2f(x_pos+7,y_pos+11);
    glVertex2f(x_pos+8,y_pos+9);
glEnd();
//small triangle 6
glColor3f(0.0, 0.0, 0.9);
glBegin(GL_POLYGON);
    glVertex2f(x_pos+6,y_pos+9);
    glVertex2f(x_pos+8,y_pos+9);
    glVertex2f(x_pos+7,y_pos+7);
glEnd();
//small triangle 7
glColor3f(0.9, 0.9, 0.9);
glBegin(GL_POLYGON);
    glVertex2f(x_pos+7,y_pos+7);
    glVertex2f(x_pos+8,y_pos+9);
    glVertex2f(x_pos+9,y_pos+7);
glEnd();
//small triangle 8
glColor3f(0.9, 0.0, 0.0);
glBegin(GL_POLYGON);
    glVertex2f(x_pos+7,y_pos+7);
    glVertex2f(x_pos+8,y_pos+5);
    glVertex2f(x_pos+9,y_pos+7);
glEnd();
//hurdle 1
glColor3f(0.9,0.9,0.9);
glBegin(GL_QUADS);
    glVertex2f(-6,4);
    glVertex2f(-6,10);
    glVertex2f(-10,10);
    glVertex2f(-10,4);
glEnd();
//hurdle 2
glColor3f(0.9,0.9,0.9);
glBegin(GL_QUADS);
    glVertex2f(25,4);
    glVertex2f(25,10);
    glVertex2f(29,10);
    glVertex2f(29,4);
glEnd();
//hurdle 3
glColor3f(0.9,0.9,0.9);
glBegin(GL_QUADS);
    glVertex2f(-4,26);
    glVertex2f(-4,20);
    glVertex2f(25,20);
    glVertex2f(25,26);
glEnd();
//hurdle 4
glColor3f(0.9,0.9,0.9);
glBegin(GL_QUADS);
    glVertex2f(-4,-3);
    glVertex2f(-4,-9);
    glVertex2f(25,-9);
    glVertex2f(25,-3);
glEnd();
glutSwapBuffers();
}
//We define the callback function in main
//We open one or more windows with the 
//required properties
int main(int argc,char** argv) 
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE); //This requests properties for the window. 
                                              //(RGB color,Single buffering)
    glutInitWindowSize(1000, 1000);  //This is the window size in pixels.
                                    // This makes the window in the mentioned size.
    glutCreateWindow("CG PROJECT"); //This creates window with the given title 
    glutDisplayFunc(display);      //This is the display callback statement
    init();
    //
    glutReshapeFunc(reshape);
    glutTimerFunc(0,timer,0);
    glutMainLoop();   //required to enter the infinite event loop
    return 0;
}
void reshape(int w, int h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10.0,30.0,-10.0,30.0);
    glMatrixMode(GL_MODELVIEW);
}
void timer(int x)
{
    glutPostRedisplay();   
    glutTimerFunc(1000/60,timer,0);
    switch(step)
    {
        case 0:
            if(x_pos<13)
            {
            x_pos+=0.15;
            }
            else
            {
                step = 1;
            }
        break;
        case 1:
            if(x_pos>-6)
            {
                x_pos-=0.15;
            }
            else
            {
                step = 2;
            }
        break;
        case 2:
            if(y_pos<7)
            {
                y_pos+=0.15;
            }
            else
            {
                step = -2;
            }
        break;
        case -2:
            if(y_pos>1)
            {
                y_pos-=0.15;
            }
            else
            {
                step = 0;
            }
        break;
        }
}
