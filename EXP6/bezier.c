#include<GL/glut.h>
#include<math.h>
#include<stdio.h>

int x[4],y[4];

void displayFunc(void)
{
    gluOrtho2D(0,300,0,300);
    double put_x,put_y,t;
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    for(int i=0;i<4;i++)
    {
        glVertex2i(x[i],y[i]);
    }
    glEnd();

    glBegin(GL_POINTS);
    for(t=0.0;t<=1.0;t=t+0.001)             // t always lies between 0 and 1
    {
        put_x = pow(1-t,3)*x[0] + 3*t*pow(1-t,2)*x[1] + 3*t*t*(1-t)*x[2] + pow(t,3)*x[3]; // Formula to draw curve
        put_y =  pow(1-t,3)*y[0] + 3*t*pow(1-t,2)*y[1] + 3*t*t*(1-t)*y[2] + pow(t,3)*y[3];
        // putpixel(put_x,put_y, WHITE);            // putting pixel 
        glVertex2d(put_x,put_y);
    }
    glEnd();
    glFlush();
}

int main(int argc,char** argv)
{
    printf("Prakrati Singh");
    printf("\nSAP ID : 500082638\n");
    printf("\n Enter the x- and y-coordinates of the four control points.\n");
    for(int i=0;i<4;i++)                 
    {
        scanf("%d%d",&x[i],&y[i]);
    }
    //initializing the glut library
    glutInit(&argc,argv);
    //initializing the mode of the display
    glutInitDisplayMode(GLUT_SINGLE);
    //initializing the window position and the size 
    glutInitWindowPosition(30,30);
    glutInitWindowSize(600,700);
    //creating and naming the window 
    glutCreateWindow("Beizere Curve");
    glutDisplayFunc(displayFunc);
    glutMainLoop();
    return 0;
}
