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
    std::cerr << "/* error message */" << std::endl;
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

  // try{
  //   // Imagen suma = operator+(origen1, origen2);
  //
  //   if (argv[4]==string("b")) {
  //     (origen1+origen2).escribirImagen(argv[3], true);
  //   }
  //   else {
  //     (origen1+origen2).escribirImagen(argv[3], false);
  //   }
  // }
  // catch (int e) {
  //     cout << "An exception occurred. Exception Nr. " << e << '\n';
  // }

  return 0;
}
