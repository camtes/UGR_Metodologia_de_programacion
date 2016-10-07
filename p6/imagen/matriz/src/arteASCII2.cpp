/**
 * lee cualquier imagen indicada por el usuario y un fichero con cadenas
 * de caracteres y crea ficheros de imagen transformadas, una por cadena
*/
#include<iostream>
#include<fstream>
#include<cstring>
#include <cstdlib>
#include "../include/imagen.h"
#include "../include/lista.h"

using namespace std;

const int MAXLONG = 900000;

void leelinea(char *s){
	do{
		cin.getline(s, MAXLONG);
	} while (s[0]=='\0');
}

int main(int argc, char ** argv) {
	char ficheroGrises[MAXLONG];
	char ficheroImagen[MAXLONG];
  Imagen origen;
  Lista celdas;

		if (argc < 3) {
	    std::cerr << "/* Faltan argumentos */" << std::endl;
			cout << "bin/arteASCII2 imagen.pgm fichero_ascii.txt" << endl;
			return 1;
		}

    // Leer la imagen desde fichero
    if (!origen.leerImagen(argv[1])){
		cerr << "Error leyendo imagen " << argv[1] << endl;
		return 1;
    }

	// Leer cadenas desde fichero
 	if (celdas.leerLista(argv[2])){
		if (origen.listaAArteASCII(celdas)){
			cout << "Exito en la conversion." << endl;
			cout << "Chequee los ficheros asciiX.txt" << endl;
			cout << endl;
	}
	else {
			cerr << "La conversion no ha sido posible" << endl;
			cerr << endl;
		}

		celdas.destruir(); // liberar memoria listas
	}
	else{
		cerr << "Error lista de grises " << argv[2] << endl;
	}

	origen.destruir();   // liberar memoria imagen
}
