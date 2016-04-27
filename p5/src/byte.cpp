/**
* Creado por Carlos Campos, Juan David Vargas Jimenez
*
* Metodología de la programación
* Práctica 2
*/

#include "byte.h"
#include <iostream>
#include <stdio.h>

using namespace std;

void on(byte &b, int pos){

	byte mask;

	if((pos>=0) && (pos<8)) {
		mask = 1 << pos;
		b = b | mask;
	}
}

void off(byte &b, int pos){
  byte mask = 1 << pos;
  mask = ~mask;
  b = b & mask;
}

bool getbit(byte b, int pos){
	unsigned char mask = 1 << pos;

	if ((b & mask) != 0)
		return true;
	else
		return false;
}

void encender(byte &b){
	b = 255;
}

void apagar(byte &b){
  b = 0;
}

void asignar(byte &b, const bool v[]){
	for (int i=0; i<8; i++) {
		if (v[i])
			on(b,i);
	}
}

void volcar(byte b, bool v[]){
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

void encendidos(byte b, int posic[], int &cuantos){
	cuantos = 0;

	for (int i=0; i<8; i++) {
		if (getbit(b,i)) {
				posic[cuantos] = i;
				cuantos++;
		}
	}
}

string byteToString(byte b) {
    string bloque;
    for (int i = 7; i >= 0; i--) {
        if (getbit(b, i)) {
            bloque = bloque + '1';
        } else {
            bloque = bloque + '0';
        }
    }

    return bloque;
}
