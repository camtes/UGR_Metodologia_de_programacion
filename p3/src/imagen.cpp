#include <fstream>
#include <string>
#include "imagen.h"

using namespace std;

// Carlos
Imagen(int filas, int columnas);

// Juanda
void crear(int filas, int columnas);

// Carlos
int filas();

// Juanda
int columnas();

// Carlos
void set(int y, int x, byte v);

// Juanda
byte get(int y, int x);

// Carlos
void setPos(int i, byte v);

// Juanda
byte getPos(int i);

// Carlos
bool leerImagen(const char nombreFichero[]);

// Juanda
bool escribirImagen(const char nombreFichero[], bool esBinario);
