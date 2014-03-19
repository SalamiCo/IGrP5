#include "Matr.h"

Matr::Matr(){
	// Identity  Matrix
	for(int i=0; i<WIDTH; i++){
		for(int j=0; j<HEIGHT; j++){
			if(i==j){
				data[i][j] = 1.0;
			} else{
				data[i][j] = 0.0;	
			} 
		}
	}
}

Matr::Matr(float data[WIDTH][HEIGHT]){
	for(int i=0; i<WIDTH; i++){
		for(int j=0; j<HEIGHT; j++){
			this->data[i][j] = data[i][j];
		}
	}
}

PV3D Matr::prodVect(PV3D vect){
	float vectArray[4] = {vect.getX(), vect.getY(), vect.getZ(), vect.getPV()};
	float vectResult[4];

	for(int i=0; i<WIDTH; i++){
		vectResult[i] = 0.0;
		for (int k=0; k<WIDTH; k++){
			vectResult[i] += this->data[i][k] * vectArray[k];
		}
	} 

	return PV3D(vectResult[0], vectResult[1], vectResult[2], vectResult[3]);
}
