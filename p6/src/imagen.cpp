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
   datos = 0;
};

Imagen::Imagen(int filas, int columnas) {
  datos = 0;
  crear(filas,columnas);
}

Imagen::Imagen (const Imagen & orig) {
  datos = 0;
  copiar(orig.datos, orig.nfilas, orig.ncolumnas);
}

void Imagen::crear(int filas, int columnas){
  if (datos != 0) {
    destruir();
  }

  nfilas=filas;
  ncolumnas=columnas;
  datos = new byte[filas*columnas];
  for(int i =0; i< filas; i++){
     for(int j=0; j< columnas; j++){
        datos[i*ncolumnas+j]=0;
     }
  }
}

void Imagen::copiar(byte * data,int f, int c) {
        this->nfilas = f;
        this->ncolumnas = c;
        crear(nfilas,ncolumnas);

        for (int i=0; i<nfilas; i++) {
          for (int j=0;j<ncolumnas;j++)
                this->datos[i][j]=data[i][j];
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

  if (tipo == IMG_PGM_BINARIO && nfilas*ncolumnas <= MAXPIXELS){
    res = leerPGMBinario (nombreFichero, datos, nfilas, ncolumnas);
  }

  if (tipo == IMG_PGM_TEXTO && nfilas*ncolumnas <= MAXPIXELS){
    crear(nfilas, ncolumnas);
    res = leerPGM (nombreFichero, datos, nfilas, ncolumnas);
  }

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
  int pos = 0, length = strlen(grises);
  if(success){
     for(int i=0; i<ncolumnas; i++){
        for(int j=0; j<nfilas; j++){
           arteASCII[pos] = grises[get(i,j)*length/BITDEPTH];
           pos++;
        }
        arteASCII[pos]='\n';
        pos++;
     }
  }
  arteASCII[pos] = '\0';
  return success;
}

void Imagen::destruir(){
  if (datos!=0) {
    delete [] datos;
  }

  datos = 0;
  nfilas = ncolumnas = 0;
}

Imagen::~Imagen(){
  destruir();
}

bool Imagen::listaAArteASCII(const Lista celdas) {
  bool result = false;
  char * arteASCII = new char[nfilas*(ncolumnas+1)];

  for (int i=0; i<celdas.longitud(); i++) {
    string gris = celdas.getCelda(i);
    const char *gris_char = gris.c_str();

    if (this->aArteASCII(gris_char, arteASCII, 5000)) {
      char nombre_aux[255] = "";
      ofstream fsalida;
      sprintf(nombre_aux, "%s%d%s", "ascii", i,".txt");
      fsalida.open(nombre_aux);
      fsalida << arteASCII;
      fsalida.close();
      result = true;
    }
    else {
      cout << "\nNo se ha podido generar el archivo ascii" << i << ".txt" << endl;
      result = false;
    }
  }

  return result;
}
