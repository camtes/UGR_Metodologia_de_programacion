#include<iostream>
#include<fstream>
#include <string.h>
#include <stdio.h>
#include "../include/imagen.h"

using namespace std;

int main(){

  Imagen origen1, origen2, destino;
  //ifstream infile;
  //ofstream ofile;

  char file_path[100],file_path2[100],file_ascii[100],tipo;

  cout << "Introduzca la ruta de la imagen a: " << endl;
  cin.getline(file_path, 100);

  cout << "Introduzca la ruta de la imagen b: " << endl;
  cin.getline(file_path2, 100);

  cout << "Introduzca el nombre del archivo final: " << endl;
  cin.getline(file_ascii, 100);

  cout << "Introduzca si quiere que se guarde en (t)exto o (b)inario: " << endl;
  cin >> tipo;

  if (!origen1.leerImagen(file_path)){
    cerr << "error leyendo la imagen a\n";
    return 1;
  }

  if (!origen2.leerImagen(file_path2)){
    cerr << "error leyendo la imagen b\n";
    return 1;
  }

  if(!destino.concatenar(file_ascii,tipo)){
    cerr << "error concatenando las imagenes\n";
    return 1;
  }

  if (destino.escribirImagen(file_ascii, true)){
		// si todo va bien
		cout << "suma guardada correctamente \n";
	} else { // si error
		cerr << "Error guardando la suma\n";
		return 1;
	}

  return 0;
}
