#include <fstream>
#include <string>
#include "imagen.h"

using namespace std;

Imagen(int filas, int columnas);

void crear(int filas, int columnas);

int filas();

int columnas();

void set(int y, int x, byte v);

byte get(int y, int x);

void setPos(int i, byte v);

byte getPos(int i);

bool leerImagen(const char nombreFichero[]);

bool escribirImagen(const char nombreFichero[], bool esBinario);
