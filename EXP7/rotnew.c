#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
//rotation angle theta 
float theta;

//rotation function
void Rotation2D(float *x,float *y)
{
    float a = *x;
    float b = *y;
    *x = ((a*cos(theta)) - (b*sin(theta)));
    *y = ((a*sin(theta)) + (b*cos(theta))); 
}

void displayFunc(void)
{
    float x1,y1,x2,y2,x3,y3,x4,y4,x5,y5;
    x1 = 0.3;
    y1 = 0.1;
    x2 = 0.1;
    y2 = 0.3;
    x3 = 0.2;
    y3 = 0.4;
    x4 = 0.5;
    y4 = 0.4;
    x5 = 0.6;
    y5 = 0.3;
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
        glVertex2f(x3,y3);
        glVertex2f(x4,y4);
        glVertex2f(x5,y5);
    glEnd();

    //applying transformation (rotation) to the coordinates
    Rotation2D(&x1,&y1);
    Rotation2D(&x2,&y2);
    Rotation2D(&x3,&y3);
    Rotation2D(&x4,&y4);
    Rotation2D(&x5,&y5);

    //plotting the ploygon after rotation
    glBegin(GL_POLYGON);
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
        glVertex2f(x3,y3);
        glVertex2f(x4,y4);
        glVertex2f(x5,y5);
    glEnd();

    glFlush();
}

int main(int argc,char** argv)
{
    //getting th rotation angle from the user 
    printf("Enter the rotation angle (theta) : ");
    scanf("%f",&theta);
    theta=(3.14*theta)/180;
    //initializing the glut library
    glutInit(&argc,argv);
    //initializing the mode of the display
    glutInitDisplayMode(GLUT_SINGLE);
    //initializing the window position and the size 
    glutInitWindowPosition(100,100);
    glutInitWindowSize(600,700);
    //creating and naming the window 
    glutCreateWindow("Rotation (2d Transformation)");
    glutDisplayFunc(displayFunc);
    glutMainLoop();
    return 0;

}