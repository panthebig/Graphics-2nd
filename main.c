#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>


GLfloat angle =0;
float a = 5.0;
float initial = 1.0;


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
        glVertex3f( 1.0, 1.0, 1.0);
        glVertex3f(-1.0, 1.0, 1.0);
        glVertex3f(-1.0,-1.0, 1.0);
        glVertex3f( 1.0,-1.0, 1.0);
        glEnd();
    glEndList();


    glEnable(GL_BLEND);
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-25, 25.0, -25, 25, -25.0, 25.0);
    glMatrixMode(GL_MODELVIEW);
}


void display( void )
{

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    //glTranslatef(-cameraX, -cameraY, 0.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //glTranslatef(250,250,00);
    glRotatef(angle, 1.0, 1.0, 1.0);

    glPushMatrix(); //front plane //Red //First Scale than Rotate then Translate
    glScalef(2.5, 2.5, 1);
    glColor3f(1.0, 0.0, 0.0);
    glCallList(1);
    glPopMatrix();

    glPushMatrix(); //rear plane //Blue
    glTranslatef(0.0,0.0,-5);
    glScalef(2.5, 2.5, 1);
    glColor3f(0.0, 0.0, 1.0);
    glCallList(1);
    glPopMatrix();

    glPushMatrix(); //Right side //Green
    glTranslatef(1.5, 0.0, -1.5);
    glRotatef(90, 0.0, 1.0, 0.0);
    glScalef(2.5, 2.5, 1);
    glColor3f(0.0, 1.0, 0.0);
    glCallList(1);
    glPopMatrix();

    glPushMatrix(); //Left side -Cyan
    glTranslatef(-3.5, 0.0, -1.5);
    glRotatef(90, 0.0, 1.0, 0.0);
    glScalef(2.5, 2.5, 1);
    glColor3f(0.0, 1.0, 1.0);
    glCallList(1);
    glPopMatrix();

    glPushMatrix(); //Top side -Yellow
    glTranslatef(0.0, 3.5, -1.5);
    glRotatef(90, 1.0, 0.0, 0.0);
    glScalef(2.5, 2.5, 1);
    glColor3f(1.0, 1.0, 0.0);
    glCallList(1);
    glPopMatrix();

    glPushMatrix(); //Bottom side -Pink
    glTranslatef(0.0, -1.5, -1.5);
    glRotatef(90, 1.0, 0.0, 0.0);
    glScalef(2.5, 2.5, 1);
    glColor3f(1.0, 0.0, 1.0);
    glCallList(1);
    glPopMatrix();


    glutSwapBuffers(); //Buffer swapping

 }


int main(int argc, char** argv)
{

    glutInit(&argc,argv);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Second Project");
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);


    glutIdleFunc(RotateFunc); //When idle call RotateFunc

    myinit();

    glutMainLoop();
}
