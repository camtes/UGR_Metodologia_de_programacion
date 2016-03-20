/**
* Creado por Carlos Campos, Juan David Vargas Jimenez
*
* Metodología de la programación
* Práctica 2
*/

#include "bloqueLed.h"
#include <iostream>
#include <stdio.h>

using namespace std;

void on(bloqueLed &b, int pos){

	bloqueLed mask;

	if((pos>=0) && (pos<8)) {
		mask = 1 << pos;
		b = b | mask;
	}
}

void off(bloqueLed &b, int pos){
  bloqueLed mask = 1 << pos;
  mask = ~mask;
  b = b & mask;
}

bool get(bloqueLed b, int pos){
	unsigned char mask = 1 << pos;

	if ((b & mask) != 0)
		return true;
	else
		return false;
}

void encender(bloqueLed &b){
	b = 255;
}

void apagar(bloqueLed &b){
  b = 0;
}

void asignar(bloqueLed &b, const bool v[]){
	for (int i=0; i<8; i++) {
		if (v[i])
			on(b,i);
	}
}

void volcar(bloqueLed b, bool v[]){
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

void encendidos(bloqueLed b, int posic[], int &cuantos){
	cuantos = 0;

	for (int i=0; i<8; i++) {
		if (get(b,i)) {
				posic[cuantos] = i;
				cuantos++;
		}
	}
}

string bloqueLedToString(bloqueLed b) {
    string bloque;
    for (int i = 7; i >= 0; i--) {
        if (get(b, i)) {
            bloque = bloque + '1';
        } else {
            bloque = bloque + '0';
        }
    }

    return bloque;
}
