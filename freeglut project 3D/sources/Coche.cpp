#include "Coche.h"

Coche::Coche(){
	this->verticesCubo = new PV3D*[24];
	creaCubo();
}

void Coche::dibujaCoche(){
	
	//Cubo
	glBegin(GL_LINE_STRIP);
	for(int i=0; i<24; i++){
		glVertex3f(verticesCubo[i]->getX(), verticesCubo[i]->getY(), verticesCubo[i]->getZ());
	}
	glEnd();
	
}

void Coche::creaCubo(){
	//Front
	verticesCubo[0] = new PV3D(0.5, -0.5, -0.5, 1);
	verticesCubo[1] = new PV3D(0.5,  0.5, -0.5, 1);
	verticesCubo[2] = new PV3D(-0.5,  0.5, -0.5, 1);
	verticesCubo[3] = new PV3D(-0.5, -0.5, -0.5, 1);

	//Back
	verticesCubo[4] = new PV3D(0.5, -0.5, 0.5, 1);
	verticesCubo[5] = new PV3D(0.5,  0.5, 0.5, 1);
	verticesCubo[6] = new PV3D(-0.5, 0.5, 0.5, 1);
	verticesCubo[7] = new PV3D(-0.5, -0.5, 0.5, 1);
	
	//Right
	verticesCubo[8] = new PV3D(0.5, -0.5, -0.5, 1);
	verticesCubo[9] = new PV3D(0.5, 0.5, -0.5, 1);
	verticesCubo[10] = new PV3D(0.5, 0.5, 0.5, 1);
	verticesCubo[11] = new PV3D(0.5, -0.5, 0.5, 1);
	
	//Left
	verticesCubo[12] = new PV3D(-0.5, -0.5, 0.5, 1);
	verticesCubo[13] = new PV3D(-0.5, 0.5, 0.5, 1);
	verticesCubo[14] = new PV3D(-0.5, 0.5, -0.5, 1);
	verticesCubo[15] = new PV3D(-0.5, -0.5, -0.5, 1);
	
	//Top
	verticesCubo[16] = new PV3D(0.5, 0.5, 0.5, 1);
	verticesCubo[17] = new PV3D(0.5, 0.5, -0.5, 1);
	verticesCubo[18] = new PV3D(-0.5, 0.5, -0.5, 1);
	verticesCubo[19] = new PV3D(-0.5, 0.5, 0.5, 1);
	
	//Bottom
	verticesCubo[20] = new PV3D(0.5, -0.5, -0.5, 1);
	verticesCubo[21] = new PV3D(0.5, -0.5, 0.5, 1);
	verticesCubo[22] = new PV3D(-0.5, -0.5, 0.5, 1);
	verticesCubo[23] = new PV3D(-0.5, -0.5, -0.5, 1);
}