#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>


GLfloat angle =0;


void RotateFunc(){
    angle=angle+0.1;
    if (angle>360){
        angle=0;
    }

    glutPostRedisplay(); //From here call the displayFunc

}

void drawPlane(){
    glCallList(1);
}

void myinit(void){

    glNewList(1, GL_COMPILE);
        glBegin(GL_POLYGON);
        glVertex3f(-50,-50,1);
        glVertex3f(-50,50,1);
        glVertex3f(50,50,1);
        glVertex3f(50,-50,1);
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

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(250,250,0);
    glRotatef(angle,1.0,1.0,1.0);

    glPushMatrix(); //front plane
    glColor3f(1.0, 0.0, 0.0);
    glCallList(1);
    glPopMatrix();

    glPushMatrix(); //rear plane
    glTranslatef(0.0,0.0,-100.0);
    glColor3f(0.0, 0.0, 1.0);
    glCallList(1);
    glPopMatrix();

    glPushMatrix(); //Right side
    glTranslatef(50.0,0.0,-50.0);
    glRotatef(90,0.0,1.0,0.0);
    glColor3f(0.0, 1.0, 0.0);
    glCallList(1);
    glPopMatrix();

    glPushMatrix(); //Left side
    glTranslatef(-50.0,0.0,-50.0);
    glRotatef(90,0.0,1.0,0.0);
    glColor3f(0.0, 1.0, 1.0);
    glCallList(1);
    glPopMatrix();

    glPushMatrix(); //Top side
    glTranslatef(0.0,50.0,-50.0);
    glRotatef(90,1.0,0.0,0.0);
    glColor3f(1.0, 1.0, 0.0);
    glCallList(1);
    glPopMatrix();

    glPushMatrix(); //Bottom side
    glTranslatef(0.0,-50.0,-50.0);
    glRotatef(90,1.0,0.0,0.0);
    glColor3f(1.0, 0.0, 1.0);
    glCallList(1);
    glPopMatrix();


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


    glutIdleFunc(RotateFunc); //When idle call RotateFunc

    myinit();

    glutMainLoop();
}
