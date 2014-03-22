#pragma once

#include "PV3D.h"

#define ancho 4
#define alto 4

class Matr {
	private:
		float data [ancho][alto];
	public:
		Matr();
		Matr(float data[ancho][alto]);
		float getData(int i, int j){return data[i][j];};
		PV3D prodVect(PV3D vect);

		Matr static matrizNBTC(float t);

};