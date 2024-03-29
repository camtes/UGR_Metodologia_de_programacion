#include <fstream>
#include <string>
#include <stdio.h>
#include <cstring>
#include <iostream>
#include "../include/imagen.h"
#include "../include/pgm.h"
#include "../include/byte.h"

using namespace std;

Imagen::Imagen(){
   nfilas = 0;
   ncolumnas = 0;
};

Imagen::Imagen(int filas, int columnas) {
  crear(filas, columnas);
}

void Imagen::crear(int filas, int columnas){
  if(filas*columnas < MAXPIXELS){
    nfilas = filas;
    ncolumnas = columnas;
    byte bzero = 0x00;
    for(int i=0; i < filas*columnas; i++)
      setPos(i,bzero);
   }
}

int Imagen::filas() {
  return nfilas;
}

int Imagen::columnas(){
	return ncolumnas;
}

void Imagen::set(int y, int x, byte v) {
  if(y < nfilas && x < ncolumnas)
    datos[ncolumnas*y + x] = v;
}

byte Imagen::get(int y, int x){
	return datos[ncolumnas * y + x];
}

void Imagen::setPos(int i, byte v) {
  datos[i] = v;
}

byte Imagen::getPos(int i){
  return datos[i];
}

bool Imagen::leerImagen(const char nombreFichero[]) {
  bool res = false;
  TipoImagen tipo = infoPGM(nombreFichero, nfilas, ncolumnas);

  if (tipo == IMG_PGM_BINARIO && nfilas*ncolumnas < MAXPIXELS)
    res = leerPGMBinario (nombreFichero, datos, nfilas, ncolumnas);

  if (tipo == IMG_PGM_TEXTO && nfilas*ncolumnas < MAXPIXELS)
    res = leerPGM (nombreFichero, datos, nfilas, ncolumnas);

  return res;
}

bool Imagen::escribirImagen(const char nombreFichero[], bool esBinario) {
  bool res = false;

  if (esBinario)
    res = escribirPGMBinario(nombreFichero, datos, nfilas, ncolumnas);
  else
    res = escribirPGMBinario(nombreFichero, datos, nfilas, ncolumnas);

  return res;
}

Imagen Imagen::plano (int k) {
  Imagen nueva_imagen(nfilas, ncolumnas);
  for(int i=0; i<ncolumnas; i++) {
    for(int j=0; j<nfilas; j++) {
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

bool Imagen::aArteASCII(const char grises[], char arteASCII[], int maxlong){
   bool success = maxlong > (ncolumnas*nfilas + nfilas);
   int pos = 0,
      length = strlen(grises);
   if(success){
      for(int i=0; i<ncolumnas; i++){
         for(int j=0; j<nfilas; j++){
            arteASCII[pos++] = grises[1*get(i,j)*length/BITDEPTH];
         }
         arteASCII[pos++]='\n';
      }
   }
   arteASCII[pos] = '\0';
   return success;
}
