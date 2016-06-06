/**
  * @file
  * @brief Fichero con las definiciones para la E/S de imágenes PGM
  *
  * Permite la E/S de archivos de tipos PGM
  *
  */
#include <iostream>
#include <fstream>
#include <string>
#include "../include/pgm.h"
#include "../include/byte.h"
using namespace std;


TipoImagen LeerTipo(ifstream& f)
{
  char c1,c2;
  TipoImagen res= IMG_DESCONOCIDO;

  if (f) {
    f >> c1 >> c2;
    if (f && c1=='P')
      switch (c2) {
        case '5': res= IMG_PGM_BINARIO; break;
        case '2': res= IMG_PGM_TEXTO; break;
        default: res= IMG_DESCONOCIDO;
      }
  }
  return res;
}


// _____________________________________________________________________________

char SaltarSeparadores (ifstream& f)
{
  char c;
  do {
    c= f.get();
  } while (isspace(c));
  f.putback(c);
  return c;
}

// _____________________________________________________________________________

bool LeerCabecera (ifstream& f, int& filas, int& columnas)
{
    int maxvalor;

    while (SaltarSeparadores(f)=='#')
      f.ignore(10000,'\n');

    f >> columnas >> filas >> maxvalor;

    if (/*str &&*/ f && filas>0 && filas <5000 && columnas >0 && columnas<5000) {
        f.get(); // Saltamos separador
        return true;
    }
    else return false;
}

// _____________________________________________________________________________

TipoImagen infoPGM(const char nombre[], int& filas, int& columnas)
{
  TipoImagen tipo;
  filas=columnas=0;
  ifstream f(nombre);

  tipo=LeerTipo(f);
  if (tipo!=IMG_DESCONOCIDO)
    if (!LeerCabecera(f,filas,columnas)) {
      tipo=IMG_DESCONOCIDO;
    }

  return tipo;
}

// _____________________________________________________________________________

bool leerPGMBinario (const char nombre[], unsigned char datos[], int& filas, int& columnas) {
  cout << "leo pgm binario" << endl;
  bool exito= false;
        filas=0;
        columnas=0;
        ifstream f(nombre);

        if (LeerTipo(f)==IMG_PGM_BINARIO)
                if (LeerCabecera (f, filas, columnas))
                        if (f.read(reinterpret_cast<char *>(datos),filas*columnas)) {
                          exito = true;
                        }

        return exito;
}

// _____________________________________________________________________________

bool leerPGM (const char nombre[], unsigned char datos[], int& filas, int& columnas)
{
  cout << "leo pgm text" << endl;
  bool exito= false;
	filas=0;
	columnas=0;
	int c;
	int contador = 0;
	ifstream f(nombre);
	if (LeerTipo(f)==IMG_PGM_TEXTO) {
    	if (LeerCabecera (f, filas, columnas)){
			while(contador <filas*columnas){
				f >> c;
				datos[contador]=(char)c;    //ASIGNAR DATOS AL VECTOR
				contador ++;
				}
			exito = true;
		}
  }

  return exito;
}

//_______________________________________________________________________________

bool escribirPGMBinario (const char nombre[], const unsigned char datos[], int filas, int columnas)
{
  ofstream f(nombre);
  bool res= true;

  if (f) {
    f << "P5" << endl;
    f << columnas << ' ' << filas << endl;
    f << 255 << endl;
    f.write(reinterpret_cast<const char *>(datos),filas*columnas);
    if (!f) res=false;
  }
  return res;
}


//_______________________________________________________________________________

bool escribirPGM (const char nombre[], const unsigned char datos[], int filas, int columnas)
{
	ofstream f;

	bool res = true;
	//f.open();
	if(f) {
		f << "P2" << endl;
		f << columnas << ' ' << filas << endl;
		f << 255 << endl;
		//f.write(reinterpret_cast<const char *>(datos),filas*columnas);
		for (int i=0; i<filas*columnas;i++){
			f << (int)datos[i]<<' ';
		}
		if (!f) res=false;
  	}
	f.close();
  return res;

}
