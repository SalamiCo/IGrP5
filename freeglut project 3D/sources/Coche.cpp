//Pedro Morgado Alarcón
//Samuel Méndez Galán

#include "Coche.h"

Coche::Coche(){
	this->verticesCubo = new PV3D*[24];
	creaCubo();
}

void Coche::dibujaCoche(){
	
	//Cubo
	glBegin(GL_LINE_LOOP);
	for(int i=0; i<24; i++){
		glVertex3f(verticesCubo[i]->getX(), verticesCubo[i]->getY(), verticesCubo[i]->getZ());
	}
	glEnd();
}

void Coche::rodaja(float t){
	//push

	PV3D sol[24];
	Matr m;
	m = Matr::matrizNBTC(t);

	for(int i=0; i<24; i++){
		sol[i] = m.prodVect(*verticesCubo[i]);
	}

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0,1.0,0.0);
  	for(int j=0;j<24;j++){
  		glVertex3f(sol[j].getX(), sol[j].getY(), sol[j].getZ());
  	}
  	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	dibujaRueda(sol[8].getX(), sol[8].getY(), sol[8].getZ());
	dibujaRueda(sol[9].getX(), sol[9].getY(), sol[9].getZ());
	dibujaRueda(sol[10].getX(), sol[10].getY(), sol[10].getZ());
	dibujaRueda(sol[11].getX(), sol[11].getY(), sol[11].getZ());
	/*dibujaRueda(0.3, -0.3, -0.3);
	dibujaRueda(0.3, -0.3, 0.3);
	dibujaRueda(-0.3, -0.3, 0.3);
	dibujaRueda(-0.3, -0.3, -0.3);*/

	//pop
}

void Coche::creaCubo(){
	//Front
	verticesCubo[0] = new PV3D(0.3, -0.3, -0.3, 1);
	verticesCubo[1] = new PV3D(0.3,  0.3, -0.3, 1);
	verticesCubo[2] = new PV3D(-0.3,  0.3, -0.3, 1);
	verticesCubo[3] = new PV3D(-0.3, -0.3, -0.3, 1);

	//Back
	verticesCubo[4] = new PV3D(0.3, -0.3, 0.3, 1);
	verticesCubo[5] = new PV3D(0.3,  0.3, 0.3, 1);
	verticesCubo[6] = new PV3D(-0.3, 0.3, 0.3, 1);
	verticesCubo[7] = new PV3D(-0.3, -0.3, 0.3, 1);
	
	//Right
	verticesCubo[8] = new PV3D(0.3, -0.3, -0.3, 1);
	verticesCubo[9] = new PV3D(0.3, 0.3, -0.3, 1);
	verticesCubo[10] = new PV3D(0.3, 0.3, 0.3, 1);
	verticesCubo[11] = new PV3D(0.3, -0.3, 0.3, 1);
	
	//Left
	verticesCubo[12] = new PV3D(-0.3, -0.3, 0.3, 1);
	verticesCubo[13] = new PV3D(-0.3, 0.3, 0.3, 1);
	verticesCubo[14] = new PV3D(-0.3, 0.3, -0.3, 1);
	verticesCubo[15] = new PV3D(-0.3, -0.3, -0.3, 1);
	
	//Top
	verticesCubo[16] = new PV3D(0.3, 0.3, 0.3, 1);
	verticesCubo[17] = new PV3D(0.3, 0.3, -0.3, 1);
	verticesCubo[18] = new PV3D(-0.3, 0.3, -0.3, 1);
	verticesCubo[19] = new PV3D(-0.3, 0.3, 0.3, 1);
	
	//Bottom
	verticesCubo[20] = new PV3D(0.3, -0.3, -0.3, 1);
	verticesCubo[21] = new PV3D(0.3, -0.3, 0.3, 1);
	verticesCubo[22] = new PV3D(-0.3, -0.3, 0.3, 1);
	verticesCubo[23] = new PV3D(-0.3, -0.3, -0.3, 1);
}

void Coche::dibujaRueda(GLfloat x, GLfloat y, GLfloat z){
	glPushMatrix();
	GLUquadricObj* cilindro = gluNewQuadric();
	
	glTranslatef(x+0.1, y+0.1, z+0.1);	
	glRotated(90, 0, 1, 0);
	//gluSphere(cilindro, 0.1, 30, 30);
	gluCylinder(cilindro, 0.1, 0.1, 0.1, 50, 1);
	gluDisk(cilindro, 0, 0.1, 50, 30);
	gluDeleteQuadric(cilindro);

	glPopMatrix();
}