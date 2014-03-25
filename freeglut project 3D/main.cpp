//Pedro Morgado Alarc�n
//Samuel M�ndez Gal�n

#define _USE_MATH_DEFINES
#include <cmath>
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>

#include <GL/glut.h>

#include <iostream>
#include "PV3D.h"
#include "Matr.h"
#include "Malla.h"
#include "Coche.h"

using namespace std;

// Freeglut parameters
// Flag telling us to keep processing events
// bool continue_in_main_loop= true; //(**)

// Viewport size
int WIDTH= 500, HEIGHT= 500;

// Viewing frustum parameters
GLdouble xRight=5, xLeft=-xRight, yTop=5, yBot=-yTop, N=1, F=1000;

// Camera parameters
GLdouble eyeX=100.0, eyeY=100.0, eyeZ=100.0;
GLdouble lookX=0.0, lookY=0.0, lookZ=0.0;
GLdouble upX=0, upY=1, upZ=0;

Malla malla;
Coche coche;
GLdouble angleX = 0.0;
GLdouble angleY = 0.0;
GLdouble angleZ = 0.0;
bool rellena = false;
bool normales = false;
double time = 0.0;

void initGL() {	 		 
	glClearColor(0.6f,0.7f,0.8f,1.0);
    glEnable(GL_LIGHTING);    

	glEnable(GL_COLOR_MATERIAL);
	glMaterialf(GL_FRONT, GL_SHININESS, 0.1f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);

	// buildSceneObjects();

	// Camera set up
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, lookX, lookY, lookZ, upX, upY, upZ);

	// Frustum set up
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();     
	glOrtho(xLeft, xRight, yBot, yTop, N, F);

	// Viewport set up
    glViewport(0, 0, WIDTH, HEIGHT);  

	 // Light0
    glEnable(GL_LIGHT0);
    GLfloat d[]={1.0,1.0,1.0,1.0};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, d);
    GLfloat a[]={0.3f,0.3f,0.3f,1.0};
    glLightfv(GL_LIGHT0, GL_AMBIENT, a);
	GLfloat p[]={25.0, 25.0, 0.0, 1.0};	 
	glLightfv(GL_LIGHT0, GL_POSITION, p);

	//Haz malla
	malla.hazMallaSuperficie();
 }

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  

	// Drawing axes
	glBegin( GL_LINES );
		glColor3f(1.0,0.0,0.0); 
		glVertex3f(0, 0, 0);
		glVertex3f(20, 0, 0);	     
	 
		glColor3f(0.0,1.0,0.0); 
		glVertex3f(0, 0, 0);
		glVertex3f(0, 20, 0);	 
	 
		glColor3f(0.0,0.0,1.0); 
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, 20);	     
	glEnd();

	// Our code

	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
 
	glRotated(angleX, 1,0,0);
	glRotated(angleY, 0,1,0);
	glRotated(angleZ, 0,0,1);

	malla.dibuja(rellena, normales);
	//coche.dibujaCoche();
	coche.rodaja(time);
	/*coche.dibujaRueda(0.3, -0.3, -0.3);
	coche.dibujaRueda(0.3, -0.3, 0.3);
	coche.dibujaRueda(-0.3, -0.3, 0.3);
	coche.dibujaRueda(-0.3, -0.3, -0.3);*/
	
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}


void resize(int newWidth, int newHeight) {
	WIDTH= newWidth;
	HEIGHT= newHeight;
	GLdouble RatioViewPort= (float)WIDTH/(float)HEIGHT;
	glViewport (0, 0, WIDTH, HEIGHT) ;
   
	GLdouble SVAWidth= xRight-xLeft;
	GLdouble SVAHeight= yTop-yBot;
	GLdouble SVARatio= SVAWidth/SVAHeight;
	if (SVARatio >= RatioViewPort) {		 
		GLdouble newHeight= SVAWidth/RatioViewPort;
		GLdouble yMiddle= ( yBot+yTop )/2.0;
		yTop= yMiddle + newHeight/2.0;
		yBot= yMiddle - newHeight/2.0;
    }
	else {      
		GLdouble newWidth= SVAHeight*RatioViewPort;
		GLdouble xMiddle= ( xLeft+xRight )/2.0;
		xRight= xMiddle + newWidth/2.0;
		xLeft=  xMiddle - newWidth/2.0;
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();   
	glOrtho(xLeft, xRight, yBot, yTop, N, F);
}

void key(unsigned char key, int x, int y){
	bool need_redisplay = true;
	switch (key) {
		case 27:  /* Escape key */
			//continue_in_main_loop = false; // (**)
			//Freeglut's sentence for stopping glut's main loop (*)
			glutLeaveMainLoop(); 
			break;

		case 'a': //Eje X
			angleX += 1.0;
			break;
		case 'z': //Eje X
			angleX -= 1.0;
			break;

		case 's': //Eje Y
			angleY += 1.0;
			break;
		case 'x': //Eje Y
			angleY -= 1.0;
			break;

		case 'd': //Eje Z
			angleZ += 1.0;
			break;
		case 'c': //Eje Z
			angleZ -= 1.0;
			break;

		case 'g': //Rellena
			rellena = true;
			break;
		case 'h': //Sin rellenar
			rellena = false;
			break;

		case 'j': //Dibuja normales
			normales = true;
			break;
		case 'k': //No dibuja normales
			normales = false;
			break;

		case 'q': //Coche hacia delante
			time += 0.1;
			break;
		case 'w': //Coche hacia atr�s
			time -= 0.1;
			break;

		default:
			need_redisplay = false;
			break;
	}
	if (need_redisplay)
		glutPostRedisplay();
}

int main(int argc, char *argv[]){
	cout<< "Starting console..." << endl;

	int my_window; // my window's identifier

	// Initialization
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition (140, 140);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInit(&argc, argv);

	// Window construction
	my_window = glutCreateWindow("Freeglut 3D-project");
    
	// Callback registration
	glutReshapeFunc(resize);
	glutKeyboardFunc(key);
	glutDisplayFunc(display);

	// OpenGL basic setting
	initGL();

	// Freeglut's main loop can be stopped executing (**)
	// while (continue_in_main_loop) glutMainLoopEvent();

	// Classic glut's main loop can be stopped after X-closing the window,
	// using the following freeglut's setting (*)
	glutSetOption (GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION) ;
    
	// Classic glut's main loop can be stopped in freeglut using (*)
	glutMainLoop(); 
  
	// We would never reach this point using classic glut
	//system("PAUSE"); 
   
	return 0;
}
