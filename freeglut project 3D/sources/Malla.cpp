#include "Malla.h"

Malla::Malla(void){
	this->numVertices = 0;
	this->numNormales = 0;
	this->numCaras = 0;
	this->vertice = new PV3D*[1];
	this->normal = new PV3D*[numCaras];
	this->cara = new Cara*[numCaras];
}

Malla::~Malla(void)
{
}

void Malla::dibuja(){
	for(int i = 0; i < numCaras; i++){
		glLineWidth(1.0);
		glBegin(GL_POLYGON);
		for(int j = 0; j < cara[i]->getNumVertices(); j++){
			int iN = cara[i]->getIndiceNormalK(j);
			int iV = cara[i]->getIndiceVerticeK(j);
			glNormal3f(normal[iN]->getX(), normal[iN]->getY(), normal[iN]->getZ());
			glVertex3f(vertice[iV]->getX(), vertice[iV]->getY(), vertice[iV]->getZ());
		}
		glEnd();
	}
}


PV3D* Malla::vectorNormalNewell(Cara c){
	PV3D* n = new PV3D();
	for(int i=0; i<c.getNumVertices(); i++){
		PV3D* vertActual = vertice[c.getIndiceVerticeK(i)];
		PV3D* vertSig = vertice[c.getIndiceVerticeK(i+1 % c.getNumVertices())];

		n->setX(n->getX() + (vertActual->getY() - vertSig->getY() * vertActual->getZ() + vertSig->getZ()));
		n->setY(n->getY() + (vertActual->getZ() - vertSig->getZ() * vertActual->getX() + vertSig->getX()));
		n->setZ(n->getZ() + (vertActual->getX() - vertSig->getX() * vertActual->getY() + vertSig->getY()));
	}
	return n->normaliza();
}
