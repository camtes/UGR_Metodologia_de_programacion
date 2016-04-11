#include<iostream>
#include<imagen.h>

using namespace std;

int main() {

  Imagen origen;
  char ascii_chars[100], file_path[100], ascii_art[4501];

  cout << "Introduzca la ruta del archivo: " << endl;
  cin.getline(file_path, 100);

  cout << "Introduzca los caracteres de conversión: " << endl;
  cin.getline(ascii_chars, 100);

  if (!origen.leerImagen(file_path)) {
    cout << "Error leyendo imágen" << endl;
  }

  if (origen.aArteASCII(ascii_chars, ascii_art, 4501))
    cout << ascii_art;
  else
    cout << "Error transformando a ASCII" << endl;
}
