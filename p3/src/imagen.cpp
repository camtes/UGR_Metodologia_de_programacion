#include <fstream>
#include <string>
#include "imagen.h"
#include "pgm.h"

using namespace std;

// Carlos
Imagen(int filas, int columnas) {
  nfilas = filas;
  ncolumnas = columnas;
  for (int i=0; i<filas*columnas; i++) {
    datos[i]=0;
  }
}

// Juanda
void crear(int filas, int columnas){

	for (int i=0;i>=filas;i++){
		for (int j=0;j>=columnas;j++){
			set(i,j,0);
		}
	}
}

// Carlos
int filas() {
  return nfilas;
}

// Juanda
int columnas(){
	return ncolumnas;
}

// Carlos
void set(int y, int x, byte v) {
  datos[y*ncolumnas+x] = v;
}

// Juanda
byte get(int y, int x){
	int col;
	col=columnas();
	return (y*col)+x;
}

// Carlos
void setPos(int i, byte v) {
  datos[i] = v;
}

// Juanda
byte getPos(int i){
  return datos[i];
}

// Carlos
bool leerImagen(const char nombreFichero[]) {
  /**
  @brief Carga una imagen desde un fichero
  @param nombreFichero nombre del fichero que contiene la imagen
  @retval true 	si ha tenido éxito en la lectura
  @retval false 	si se ha producido algún error en la lectura

  Lee desde disco los datos de la imagen llamada @a nombreFichero y la
  guarda en la memoria. La función debe asegurarse de que la imagen es de un
  tipo de imagen conocido y de que su tamaño es menor del tamaño máximo permitido (@c MAXDATOS).
  */

  bool result = false;


  TipoImagen tipo = infoPGM(nombreFichero[], nfilas, ncolumnas)
  if ( tipo != IMG_DESCONOCIDO) {

  }

  return result;
}

// Juanda
bool escribirImagen(const char nombreFichero[], bool esBinario){

}
