#include <fstream>
#include <string>
#include <stdio.h>
#include "imagen.h"
#include "pgm.h"
#include "byte.h"

using namespace std;

Imagen::Imagen(){
   nfilas = 0;
   ncolumnas = 0;
};
// Carlos
Imagen::Imagen(int filas, int columnas) {
  nfilas = filas;
  ncolumnas = columnas;
  for (int i=0; i<filas*columnas; i++) {
    datos[i]=0;
  }
}

// Juanda
void Imagen::crear(int filas, int columnas){

	for (int i=0;i>=filas;i++){
		for (int j=0;j>=columnas;j++){
			set(i,j,0);
		}
	}
}

// Carlos
int Imagen::filas() {
  return nfilas;
}

// Juanda
int Imagen::columnas(){
	return ncolumnas;
}

// Carlos
void Imagen::set(int y, int x, byte v) {
  datos[y*ncolumnas+x] = v;
}

// Juanda
byte Imagen::get(int y, int x){
	int col;
	col=columnas();
	return (y*col)+x;
}

// Carlos
void Imagen::setPos(int i, byte v) {
  datos[i] = v;
}

// Juanda
byte Imagen::getPos(int i){
  return datos[i];
}

// Carlos
bool Imagen::leerImagen(const char nombreFichero[]) {
  bool result = false;

  TipoImagen tipo = infoPGM(nombreFichero, nfilas, ncolumnas);
  if (tipo != IMG_DESCONOCIDO) {
    if (ncolumnas*nfilas < MAXPIXELS) {
      return leerPGMBinario (nombreFichero, datos, nfilas, ncolumnas);
    }
  }
}

bool Imagen::escribirImagen(const char nombreFichero[], bool esBinario) {
  bool result = false;

  if (esBinario) {
    result = escribirPGMBinario(nombreFichero, datos, nfilas, ncolumnas);
  }

  return result;
}

Imagen Imagen::plano (int k) {
   Imagen nueva_imagen(nfilas, ncolumnas);
   for(int i=0; i<ncolumnas; i++){
      for(int j=0; j<nfilas; j++){
         byte pixel = get(j,i);
         bool is_one = getbit(pixel, k);
         apagar(pixel);
         if(is_one)
            on(pixel,7);
         nueva_imagen.set(j,i,pixel);
      }
   }

   return nueva_imagen;
}
