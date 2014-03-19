#pragma once
#include "PV3D.h"
#include "Cara.h"

#include <windows.h>

#include <gl/gl.h>
#include <gl/glu.h>

#include <GL/freeglut.h>
#include <GL/glut.h>

class Malla
{
private:
	int numVertices;
	PV3D** vertice;
	int numNormales;
	PV3D** normal;
	int numCaras;
	Cara** cara;

public:
	Malla(void);
	~Malla(void);
	void dibuja();
	PV3D* vectorNormalNewell(Cara c);
};

