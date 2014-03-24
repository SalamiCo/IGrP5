#pragma once
#include "PV3D.h"

class Coche {
	private:
		PV3D** verticesCubo;
		void creaCubo();
	public:
		Coche(void);
		~Coche(void){};

		void dibujaCoche();
};