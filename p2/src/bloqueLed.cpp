/**
Creado por Carlos Campos, Juan David Vargas Jimenez
*/

#include "bloqueLed.h"
#include <iostream>

using namespace std;

// Juanda
void on(bloqueLed &b, int pos){
	unsigned char MASK = 1;
	MASK << pos-1;
	b = b | MASK;

}

// Carlos
void off(bloqueLed &b, int pos){
  unsigned char MASK = 1;
  MASK << pos-1;
}

// Juanda
bool get(bloqueLed b, int pos){
	unsigned char MASK = 1;
	MASK << pos-1;
	
	if (b|MASK!=0)
		return true;
	else
		return false;
}

// Carlos
void print(bloqueLed b){

}

// Juanda
void encender(bloqueLed &b){

}

// Carlos
void apagar(bloqueLed &b){

}

// Juanda
void asignar(bloqueLed &b, const bool v[]){

}

// Carlos
void volcar(bloqueLed b, bool v[]){

}

// Juanda
void encendidos(bloqueLed b, int posic[], int &cuantos){

}

// Carlos
// el bloqueLedToString pa' mi
