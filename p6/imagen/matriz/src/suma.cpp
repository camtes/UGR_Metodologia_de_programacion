#include <fstream>
#include <string>
#include <stdio.h>
#include <cstring>
#include <iostream>
#include "../include/imagen.h"

using namespace std;

int main(int argc, char ** argv) {

  Imagen origen1, origen2, nueva;
  bool isBinary = false;

  if (argc < 5) {
    std::cerr << "/* Faltan argumentos */" << std::endl;
		cout << "bin/suma imagen1.pgm imagen2.pgm imagen_final.pgm (b|t)" << endl;
    return 1;
  }

  if (!origen1.leerImagen(argv[1])){
    cerr << "error leyendo la imagen a\n";
    return 1;
  }

  if (!origen2.leerImagen(argv[2])){
    cerr << "error leyendo la imagen b\n";
    return 1;
  }

  if(*argv[4]=='b')
		isBinary=true;
	else
		isBinary=false;

  nueva = origen1+origen2;

  if ((origen1+origen2).escribirImagen(argv[3], isBinary)){
    cout << argv[3] << " guardado correctamente \n";
	} else { // si error
		cerr << "Error guardando la imagen " << argv[3] << "\n";
		return 1;
	}

  // Destruimos las imagenes
  origen1.destruir();
  origen2.destruir();
  nueva.destruir();

  return 0;
}
