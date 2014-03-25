#include "Matr.h"

Matr::Matr(){
	// Identity  Matrix
	for(int i=0; i<ancho; i++){
		for(int j=0; j<alto; j++){
			if(i==j){
				data[i][j] = 1.0;
			} else{
				data[i][j] = 0.0;	
			} 
		}
	}
}

Matr::Matr(float data[ancho][alto]){
	for(int i=0; i<ancho; i++){
		for(int j=0; j<alto; j++){
			this->data[i][j] = data[i][j];
		}
	}
}

PV3D Matr::prodVect(PV3D vect){
	float vectArray[4] = {vect.getX(), vect.getY(), vect.getZ(), vect.getPV()};
	float vectResult[4];

	for(int i=0; i<ancho; i++){
		vectResult[i] = 0.0;
		for (int k=0; k<alto; k++){
			vectResult[i] += this->data[i][k] * vectArray[k];
		}
	} 

	return PV3D(vectResult[0], vectResult[1], vectResult[2], vectResult[3]);
}

Matr Matr::matrizNBTC(float t){
	//Calcular los valores c, c' y c''
	PV3D aux = PV3D();
	PV3D* c = aux.calculaValorFormula(t);
	PV3D* cc = aux.calculaValorPrimDerivada(t);
	PV3D* ccc = aux.calculaValorSegDerivada(t);
	//Calcular T, B y N
	PV3D* T = aux.calculaT(cc);
	PV3D* B = aux.calculaB(cc, ccc);
	PV3D* N = aux.calculaN();
	//Recorro por columnas
	float data[alto][ancho];
	data[0][0] = N->getX();
	data[1][0] = N->getY();
	data[2][0] = N->getZ();
	data[3][0] = 0;

	data[0][1] = B->getX();
	data[1][1] = B->getY();
	data[2][1] = B->getZ();
	data[3][1] = 0;

	data[0][2] = T->getX();
	data[1][2] = T->getY();
	data[2][2] = T->getZ();
	data[3][2] = 0;

	data[0][3] = c->getX();
	data[1][3] = c->getY();
	data[2][3] = c->getZ();
	data[3][3] = 1;

	return Matr(data);
}