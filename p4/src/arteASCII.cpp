#include<iostream>
#include<fstream>
#include <string.h>
#include <stdio.h>
#include "../include/imagen.h"

using namespace std;

int main() {

  Imagen origen;
  ifstream infile;
  ofstream ofile;
  char ascii_chars[100], file_path[100], file_grises[100], file_ascii[100];
  char ascii_art[4501], ascii_chart[4501], file_sufix[] = "n.txt";

  int num; // numero de filas de caracteres


  cout << "Introduzca la ruta de los archivos: " << endl;
  cin.getline(file_path, 100);

  cout << "Introduzca archivo de caracteres(grises.txt vaya..): " << endl;
  cin.getline(file_grises, 100);

//  cout << "Introduzca los caracteres de conversión: " << endl;
//  cin.getline(ascii_chars, 100);

  cout << "Introduzca el nombre del archivo: " << endl;
  cin.getline(file_ascii, 100);

  infile.open(file_grises);
  if (origen.leerImagen(file_path)) {

      // ignoro primera linea
    infile.ignore(100, '\n');
    infile >> num;

    for (int i=0; i<num; i++) {

      char filename[100];

      file_sufix[0] = '0'+i;
      strcpy(filename, file_ascii);
      strncat(filename, file_sufix, 10);

      cout << filename << endl;

      ofile.open(filename);
      infile >> ascii_chars;

      origen.aArteASCII(ascii_chars, ascii_art, 60000);
      ofile << ascii_art;

      ofile.close();
    }
  }
  else
    cout << "Error de lectura de archivos" << endl;


  if (!origen.leerImagen(file_path)) {
    cout << "Error leyendo imágen" << endl;
  }
}
