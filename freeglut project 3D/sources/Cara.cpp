#include "Cara.h"


Cara::Cara(void)
{
}

int Cara::getIndiceNormalK(int i){
	return arrayVN[i]->getIndiceNormal();
}

int Cara::getIndiceVerticeK(int i){
	return arrayVN[i]->getIndiceVertice();
}