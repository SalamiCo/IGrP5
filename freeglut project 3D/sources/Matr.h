#pragma once

#include "PV3D.h"

#define WIDTH 4
#define HEIGHT 4

class Matr {
	private:
		float data [WIDTH][HEIGHT];
	public:
		Matr();
		Matr(float data[WIDTH][HEIGHT]);
		PV3D prodVect(PV3D vect);

};