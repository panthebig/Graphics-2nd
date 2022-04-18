#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>


int numOfPoints=10000;

char check = 0;
int scale = 6;
int mbutton = 0;
int mstate = 0;
char paused=0;


float cameraX, cameraY;
int lastMouseX, lastMouseY;



void drawPlane(){
    glCallList(1);
}

void myinit(void){

    glNewList(1, GL_COMPILE);
        glBegin(GL_POLYGON);
        glVertex3f(200,200,1);
        glVertex3f(200,300,1);
        glVertex3f(300,300,1);
        glVertex3f(300,200,1);
        glEnd();
    glEndList();


    glEnable(GL_BLEND);
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 500.0, 0.0, 500.0, 0.0, -500.0);
    glMatrixMode(GL_MODELVIEW);
}

void display( void )
{

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    //glTranslatef(-cameraX, -cameraY, 0.0f);


    glColor3f(1.0, 0.0, 0.0);
    glCallList(1);






    glutSwapBuffers(); //Buffer swapping

 }


int main(int argc, char** argv)
{

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glEnable(GL_DEPTH_TEST);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Second Project");

    glutDisplayFunc(display);


    myinit();

    glutMainLoop();
}

