#include<GL/glut.h>
#include<stdio.h>
double xmin = 40, ymin = 40, xmax = 100, ymax = 100; // Window boundaries

void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 599.0, 0.0,499.0);
    glMatrixMode(GL_MODELVIEW);
}

void update(double *x,double *y,double m,double c)
{
    if(*x<xmin)
    {
        *x = xmin;
        *y = (m*xmin) + c;
    }
    else    
    {
        *y = ymax;
        *x = (*y-c)/m;
    }
}

void computeCode(int a[4],double x,double y)
{
    a[0]=0;
    a[1]=0;
    a[2]=0;
    a[3]=0;
    if(y>ymax)
    {
        a[0]=1;
    }
    if(y<ymin)
    {
        a[1]=1;
    }
    if(x>xmax)
    {
        a[2]=1;
    }
    if(x<xmin)
    {
        a[3]=1;
    }
}

void cohenSutherland(double x0,double y0,double x1,double y1)
{

    int i[4];
    int j[4];

    //computing the code for both the coordinates 
    computeCode(i,x0,y0);
    computeCode(j,x1,y1);

    if((i[0]==0 && i[1]==0 && i[2]==0 && i[3]==0) && (j[0]==0 && j[1]==0 && j[2]==0 && j[3]==0))
    {
        glBegin(GL_LINES);
            glColor3f(0.0,0.0,1.0);
            glVertex2d(200+x0,200+y0);
            glVertex2d(200+x1,200+y1);
        glEnd();

        glBegin(GL_LINE_LOOP);
            glColor3f(1.0,1.0,1.0);
            glVertex2d(xmin+200, ymin+200);
            glVertex2d(xmax+200, ymin+200);
            glVertex2d(xmax+200, ymax+200);
            glVertex2d(xmin+200, ymax+200);
        glEnd();   
    }
    else if((i[0]&j[0]==0) && (i[1]&j[1]==0) && (i[2]&j[2]==0) && (i[3]&j[3]==0))
    {
        printf("Line is invisible!");
        glBegin(GL_LINE_LOOP);
            glColor3f(1.0,1.0,1.0);
            glVertex2d(xmin+200, ymin+200);
            glVertex2d(xmax+200, ymin+200);
            glVertex2d(xmax+200, ymax+200);
            glVertex2d(xmin+200, ymax+200);
        glEnd();   
    }
    else 
    {
        double m = (double)((y1-y0)/(x1-x0));
        update(&x0,&y0,m,10);
        update(&x1,&y1,m,10);

        glBegin(GL_LINES);
            glColor3f(0.0,0.0,1.0);
            glVertex2d(200+x0,200+y0);
            glVertex2d(200+x1,200+y1);
        glEnd();

        glBegin(GL_LINE_LOOP);
            glColor3f(1.0,1.0,1.0);
            glVertex2d(xmin+200, ymin+200);
            glVertex2d(xmax+200, ymin+200);
            glVertex2d(xmax+200, ymax+200);
            glVertex2d(xmin+200, ymax+200);
        glEnd();
    }
}

void displayFunc(void)
{
    glClearColor(0.0,0.0,0.0,1);
    glClear(GL_COLOR_BUFFER_BIT);
    double x0 = 20, y0 = 20, x1 = 100 , y1 = 180;
    glBegin(GL_LINES);
        glColor3f(1.0,0.0,0.0);
        glVertex2d(x0,y0);
        glVertex2d(x1,y1);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glColor3f(1.0,1.0,1.0);
        glVertex2d(xmin, ymin);
        glVertex2d(xmax, ymin);
        glVertex2d(xmax, ymax);
        glVertex2d(xmin, ymax);
    glEnd();
        cohenSutherland(x0,y0,x1,y1);
    glFlush();
}

int main(int argc,char **argv)
{
    printf("Prakrati Singh");
    printf("\nSAP ID : 500082638\n");
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,500);
    glutCreateWindow("Cohen Sutherland Line Clipping algorithm");
    glutDisplayFunc(displayFunc);
    init();
    glutMainLoop();
    return 0;
}
