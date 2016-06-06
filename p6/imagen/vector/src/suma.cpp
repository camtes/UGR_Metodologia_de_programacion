#include <fstream>
#include <string>
#include <stdio.h>
#include <cstring>
#include <iostream>
#include "../include/imagen.h"

using namespace std;

int main(int argc, char ** argv) {

  Imagen origen1, origen2, destino;

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

  try{
    Imagen suma = (origen1+origen2);

    if (argv[4]==string("b"))
      suma.escribirImagen(argv[3],true);
    else
      suma.escribirImagen(argv[3],false);
    }
    catch (int e) {
      cout << "An exception occurred. Exception Nr. " << e << '\n';
    }
}
