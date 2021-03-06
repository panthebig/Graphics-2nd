#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

#define a 5.0

#define initialLength 2.0
#define ScaleFactor a/initialLength
#define iX

GLfloat angle = 0;
GLfloat theScale = 1.0;
GLfloat rotator = 0;
float radius=5;
float b=70.0;
int flag=0;
int i = 1;
int j = 1;
int MenuFlag = 0;


void RotateFunc(){
    angle=angle+0.2;
    if (angle>360){
        angle=0;
    }

    theScale= theScale + i*0.005;
    if(theScale>=2){
        i=-1;
    }

    if(theScale<=1){
        i=1;
    }


    rotator= rotator + 0.005;
    if (rotator>360){
        rotator=0;
    }


    glutPostRedisplay(); //From here call the displayFunc
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
    glOrtho(-15, 15.0, -15, 15, -100.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}


void display( void )
{

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    switch(MenuFlag){
    case 0:
        glTranslatef(0 ,0 , -b);
        glRotatef(angle, 1.0, 2.0, 2.0);
        glScalef(theScale,theScale,theScale);
        break;
    case 1:
        glTranslatef(cos(rotator)*radius ,sin(rotator)*radius, -8*b/10);
        glRotatef(angle, 1.0, 2.0, 2.0);
        glScalef(theScale,theScale,theScale);
        break;
    }

    //  !!!First Scale than Rotate then Translate!!!
    glPushMatrix(); //front plane -Red
    glScalef(ScaleFactor, ScaleFactor, ScaleFactor/2);
    glColor3f(1.0, 0.0, 0.0);
    glCallList(1);
    glPopMatrix();

    glPushMatrix(); //rear plane -Blue
    glTranslatef(0.0,0.0,-a);
    glScalef(ScaleFactor, ScaleFactor, ScaleFactor/2);
    glColor3f(0.0, 0.0, 1.0);
    glCallList(1);
    glPopMatrix();

    glPushMatrix(); //Right side -Green
    glTranslatef(ScaleFactor, 0.0, -ScaleFactor);
    glRotatef(90, 0.0, 1.0, 0.0);
    glTranslatef(-ScaleFactor/2,0.0,-ScaleFactor*initialLength/2);
    glScalef(ScaleFactor, ScaleFactor, ScaleFactor);
    glColor3f(0.0, 1.0, 0.0);
    glCallList(1);
    glPopMatrix();

    glPushMatrix(); //Left side -Cyan
    glTranslatef(-ScaleFactor, 0.0, -ScaleFactor);
    glRotatef(90, 0.0, 1.0, 0.0);
    glTranslatef(-ScaleFactor/2,0.0,-ScaleFactor*initialLength/2);
    glScalef(ScaleFactor, ScaleFactor, ScaleFactor);
    glColor3f(0.0, 1.0, 1.0);
    glCallList(1);
    glPopMatrix();

    glPushMatrix(); //Top side -Yellow
    glTranslatef(ScaleFactor/2, ScaleFactor, -ScaleFactor/2);
    glRotatef(90, 1.0, 0.0, 0.0);
    glTranslatef(-ScaleFactor/2,0.0,-ScaleFactor*initialLength/2);
    glScalef(ScaleFactor, ScaleFactor, ScaleFactor);
    glColor3f(1.0, 1.0, 0.0);
    glCallList(1);
    glPopMatrix();

    glPushMatrix(); //Bottom side -Pink
    glTranslatef(ScaleFactor/2, -ScaleFactor, -ScaleFactor/2);
    glRotatef(90, 1.0, 0.0, 0.0);
    glTranslatef(-ScaleFactor/2,0.0,-ScaleFactor*initialLength/2);
    glScalef(ScaleFactor, ScaleFactor, ScaleFactor);
    glColor3f(1.0, 0.0, 1.0);
    glCallList(1);
    glPopMatrix();


    glutSwapBuffers(); //Buffer swapping

 }

 void project_Menu(int id){
    switch (id)
    {
    case 1:
        MenuFlag = 0;
        break;
    case 2:
        MenuFlag = 1;
        break;
    case 3:
        exit(0);
        break;
    }

    glutPostRedisplay();
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

    glutCreateMenu(project_Menu);
        glutAddMenuEntry("Case A",1);
        glutAddMenuEntry("Case B",2);
        glutAddMenuEntry("Exit the Application",3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();
}
