//Pedro Morgado Alarc�n
//Samuel M�ndez Gal�n

#pragma once
#include "PV3D.h"
#include "Matr.h"

class Coche {
	private:
		PV3D** verticesCubo;
		void creaCubo();
	public:
		Coche(void);
		~Coche(void){};

		void dibujaCoche();
		void rodaja(float t);
		void dibujaRueda(GLfloat x, GLfloat y, GLfloat z);
};