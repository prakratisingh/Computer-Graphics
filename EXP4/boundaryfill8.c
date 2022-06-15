#include <GL/glut.h>
#include <stdio.h>
//bhag jaaa :)
void init()
{
    glViewport(0, 0, 600, 600);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 600.0, 0.0, 600.0);
    glMatrixMode(GL_MODELVIEW);
}
void Setpixel(int x, int y, float color[3])
{
    glBegin(GL_POINTS);
        glColor3fv(color);
        glVertex2i(x, y);
    glEnd();
    glFlush();
}
void boundaryfill(int x,int y,float newco[3],float edgecol[3] )
{
    float pixel[3];
    glReadPixels(x,y,1,1,GL_RGB,GL_FLOAT,pixel);
    // printf("r : %f",pixel[0]);
    // printf("\ng : %f",pixel[1]);
    // printf("\nb : %f",pixel[2]);
    if((pixel[0]!=newco[0] && pixel[1]!=newco[1]&& pixel[2]!=newco[2])&&(pixel[0]!=edgecol[0]&& pixel[1]!=edgecol[1] && pixel[2]!=edgecol[2]))
    {
        Setpixel(x,y,newco);
        boundaryfill(x-1,y,newco,edgecol);
        boundaryfill(x+1,y,newco,edgecol);
        boundaryfill(x,y+1,newco,edgecol);
        boundaryfill(x,y-1,newco,edgecol);
        boundaryfill(x-1,y-1,newco,edgecol);
        boundaryfill(x+1,y+1,newco,edgecol);
        boundaryfill(x-1,y+1,newco,edgecol);
        boundaryfill(x+1,y-1,newco,edgecol);
    }
    return;
}
void display(void)
{
    float edgecol[3] = {1.0, 0.0, 0.0};
    float newco[3] = {0.4, 0.7, 0.0};
    int fig[4][2] =
        {
            {200, 200},
            {200, 300},
            {300, 300},
            {300, 200},
        };
    glClearColor(0.7, 0.4, 0.3, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3fv(edgecol);
    glBegin(GL_LINES);
        glVertex2iv(fig[0]);
        glVertex2iv(fig[3]);
    glEnd();
    glBegin(GL_LINES);
        glVertex2iv(fig[3]);
        glVertex2iv(fig[2]);
    glEnd();
    glBegin(GL_LINES);
        glVertex2iv(fig[2]);
        glVertex2iv(fig[1]);
    glEnd();
    glBegin(GL_LINES);
        glVertex2iv(fig[1]);
        glVertex2iv(fig[0]);
    glEnd();
    boundaryfill(fig[0][0],fig[0][1],newco,edgecol);
    glFlush();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Boundary Fill Algorithm");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}