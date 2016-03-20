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

  MASK = ~MASK;
  b = b & MASK;
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
  printf("%b\n", b);
}

// Juanda
void encender(bloqueLed &b){

}

// Carlos
void apagar(bloqueLed &b){
  b = 0;
}

// Juanda
void asignar(bloqueLed &b, const bool v[]){

}

// Carlos
void volcar(bloqueLed b, bool v[]){
  // si es diferente de 0 pa lante
  unsigned char MASK = 1;
  for (int i=0 ; i<8; i++) {
    MASK = MASK << i;
    if (b & MASK > 0) {
      v[i] = true;
    }
    else {
      v[i] = false;
    }
  }
}

// Juanda
void encendidos(bloqueLed b, int posic[], int &cuantos){

}

// Carlos
// el bloqueLedToString pa' mi
