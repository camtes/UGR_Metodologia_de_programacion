/**
Creado por Carlos Campos, Juan David Vargas Jimenez
*/

#include "bloqueLed.h"
#include <iostream>
#include <stdio.h>

using namespace std;

// Juanda
void on(bloqueLed &b, int pos){
	unsigned char mask = 1;
	if (pos > 0)
		mask = mask << pos;

	b = b | mask;
}

// Carlos
void off(bloqueLed &b, int pos){
  unsigned char mask = 1 << pos;
  mask = ~mask;
  b = b & mask;
}

// Juanda
bool get(bloqueLed b, int pos){
	unsigned char mask = 1 << pos;

	if (b & mask != 0)
		return true;
	else
		return false;
}

// Juanda
void encender(bloqueLed &b){
	b = 1;
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
  unsigned char mask = 1;
  for (int i=0 ; i<8; i++) {
    mask = mask << i;
    if (b & mask > 0) {
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
string bloqueLedToString(bloqueLed b) {
    string bloque;
    for (int i = 0; i < 8; i++) {
        if (get(b, i)) {
            bloque = bloque + '1';
        } else {
            bloque = bloque + '0';
        }
    }

    return bloque;
}
