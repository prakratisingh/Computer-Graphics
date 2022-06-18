#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
float xtranslation,ytranslation,ztranslation;
void Translation(float *x,float *y,float *z)
{
    float a = *x;
    float b = *y;
    float c = *z;
    *x = a+ xtranslation;
    *y = b+ ytranslation;
    *z = c+ ztranslation;
}
void display(void)
{
    float Fig[12][3] =
        {
            // A1
            {0.2, 0.5, 0.0}, //[0]
                             // G11
            {0.3, 0.6, -0.5}, //[1]
                              // B2
            {0.2, 0.2, 0.0}, //[2]
                             // H22
            {0.3, 0.3, -0.5}, //[3]
                              // C3
            {0.5, 0.2, 0.0}, //[4]
                             // I33
            {0.6, 0.3, -0.5}, //[5]
                              // D4
            {0.5, 0.3, 0.0}, //[6]
                             // J44
            {0.6, 0.4, -0.5}, //[7]
                              // E5
            {0.3, 0.3, 0.0}, //[8]
                             // K55
            {0.4, 0.4, -0.5}, //[9]
                              // F6
            {0.3, 0.5, 0.0}, //[10]
                             // L66
            {0.4, 0.6, -0.5} //[11]
        };
    // bottom
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3fv(Fig[3]);
    glVertex3fv(Fig[5]);
    glVertex3fv(Fig[4]);
    glVertex3fv(Fig[2]);
    glEnd();
    // left
    glBegin(GL_QUADS);
    glColor3f(4.0, 2.0, 0.1);
    glVertex3fv(Fig[8]);
    glVertex3fv(Fig[2]);
    glVertex3fv(Fig[0]);
    glVertex3fv(Fig[1]);
    glEnd();
    // back
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.3, 0.5);
    glVertex3fv(Fig[1]);
    glVertex3fv(Fig[11]);
    glVertex3fv(Fig[9]);
    glVertex3fv(Fig[3]);
    glEnd();
    // top
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.2, 0.6);
    glVertex3fv(Fig[0]);
    glVertex3fv(Fig[1]);
    glVertex3fv(Fig[11]);
    glVertex3fv(Fig[10]);
    glEnd();
    // right
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.5);
    glVertex3fv(Fig[10]);
    glVertex3fv(Fig[11]);
    glVertex3fv(Fig[9]);
    glVertex3fv(Fig[8]);
    glEnd();
    // top2
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.3, 0.4);
    glVertex3fv(Fig[8]);
    glVertex3fv(Fig[9]);
    glVertex3fv(Fig[7]);
    glVertex3fv(Fig[6]);
    glEnd();
    // right2
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3fv(Fig[6]);
    glVertex3fv(Fig[7]);
    glVertex3fv(Fig[5]);
    glVertex3fv(Fig[4]);
    glEnd();
    // face
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.3, 0.3);
    glVertex3fv(Fig[8]);
    glVertex3fv(Fig[10]);
    glVertex3fv(Fig[0]);
    glVertex3fv(Fig[2]);
    glVertex3fv(Fig[4]);
    glVertex3fv(Fig[6]);
    glEnd();

Translation(&Fig[0][0],&Fig[0][1],&Fig[0][2]);
Translation(&Fig[1][0],&Fig[1][1],&Fig[1][2]);
Translation(&Fig[2][0],&Fig[2][1],&Fig[2][2]);
Translation(&Fig[3][0],&Fig[3][1],&Fig[3][2]);
Translation(&Fig[4][0],&Fig[4][1],&Fig[4][2]);
Translation(&Fig[5][0],&Fig[5][1],&Fig[5][2]);
Translation(&Fig[6][0],&Fig[6][1],&Fig[6][2]);
Translation(&Fig[7][0],&Fig[7][1],&Fig[7][2]);
Translation(&Fig[8][0],&Fig[8][1],&Fig[8][2]);
Translation(&Fig[9][0],&Fig[9][1],&Fig[9][2]);
Translation(&Fig[10][0],&Fig[10][1],&Fig[10][2]);
Translation(&Fig[11][0],&Fig[11][1],&Fig[11][2]);

    // bottom
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3fv(Fig[3]);
    glVertex3fv(Fig[5]);
    glVertex3fv(Fig[4]);
    glVertex3fv(Fig[2]);
    glEnd();
    // left
    glBegin(GL_QUADS);
    glColor3f(4.0, 2.0, 0.1);
    glVertex3fv(Fig[8]);
    glVertex3fv(Fig[2]);
    glVertex3fv(Fig[0]);
    glVertex3fv(Fig[1]);
    glEnd();
    // back
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.3, 0.5);
    glVertex3fv(Fig[1]);
    glVertex3fv(Fig[11]);
    glVertex3fv(Fig[9]);
    glVertex3fv(Fig[3]);
    glEnd();
    // top
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.2, 0.6);
    glVertex3fv(Fig[0]);
    glVertex3fv(Fig[1]);
    glVertex3fv(Fig[11]);
    glVertex3fv(Fig[10]);
    glEnd();
    // right
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.5);
    glVertex3fv(Fig[10]);
    glVertex3fv(Fig[11]);
    glVertex3fv(Fig[9]);
    glVertex3fv(Fig[8]);
    glEnd();
    // top2
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.3, 0.4);
    glVertex3fv(Fig[8]);
    glVertex3fv(Fig[9]);
    glVertex3fv(Fig[7]);
    glVertex3fv(Fig[6]);
    glEnd();
    // right2
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3fv(Fig[6]);
    glVertex3fv(Fig[7]);
    glVertex3fv(Fig[5]);
    glVertex3fv(Fig[4]);
    glEnd();
    // face
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.3, 0.3);
    glVertex3fv(Fig[8]);
    glVertex3fv(Fig[10]);
    glVertex3fv(Fig[0]);
    glVertex3fv(Fig[2]);
    glVertex3fv(Fig[4]);
    glVertex3fv(Fig[6]);
    glEnd();
    glFlush();
}
int main(int argc,char** argv)
{
    printf("Enter translation factor for x ");
    scanf("%f",&xtranslation);
    printf("Enter translation factor for y ");
    scanf("%f",&ytranslation);
    printf("Enter translation factor for z ");
    scanf("%f",&ztranslation);
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Translation in 3D");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
