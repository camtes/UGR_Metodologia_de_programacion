#include <stdio.h>
#include <iostream>

/*
* Autor: Carlos Campos
* Email: camposf@correo.ugr.es
*
* Metodología de la programación - Práctica 0
* Manejo de Tiempos
*/

using namespace std;

struct Tiempo{
     int hora; // entre 0 y 23
     int minutos; // entre 0 y 59
     int segundos; // 0 y 59
};

// Declaración de funciones
bool esPosterior(Tiempo t1, Tiempo t2); // Devuelve true si t2 es posterior que t1
int convertirASegundos(Tiempo tiempo); // Devuelve el tiempo en segundos.
Tiempo obtenerNuevoTiempo(Tiempo tiempo, int seg); // Obtengo nuevo tiempo sumando los segundos

int main(void) {
  struct Tiempo tiempo1, tiempo2, nuevoTiempo;

  tiempo1.hora = 1;
  tiempo1.minutos = 1;
  tiempo1.segundos = 3;

  int tiempo1enSeg = 0;

  tiempo2.hora = 2;
  tiempo2.minutos = 39;
  tiempo2.segundos = 58;

  if (esPosterior(tiempo1, tiempo2)) {
    cout << "El tiempo 2 es posterior al tiempo 1" << endl;
  }
  else {
    cout << "El tiempo 1 es posterior al tiempo 2" << endl;
  }

  tiempo1enSeg = convertirASegundos(tiempo1);
  cout << "El tiempo 1 en segundos es: " << tiempo1enSeg << "." << endl;

  nuevoTiempo = obtenerNuevoTiempo(tiempo2, 3663);
  cout << "La suma de los dos tiempos anteriores son: " << nuevoTiempo.hora << " hora/s, "<< nuevoTiempo.minutos << " minuto/s y " << nuevoTiempo.segundos << " segundo/s." << endl;

}

bool esPosterior(Tiempo t1, Tiempo t2) {
  bool result = false;

  if (t1.hora == t2.hora) {
    if (t1.minutos == t2.minutos) {
      if (t1.segundos < t2.segundos) {
        result = true;
      }
    }
    else if (t1.minutos < t2.minutos) {
      result = true;
    }
  }
  else if (t1.hora < t2.hora) {
    result = true;
  }

  return result;
}

int convertirASegundos(Tiempo tiempo) {
  int segundos = tiempo.segundos;

  segundos += tiempo.hora*60*60;
  segundos += tiempo.minutos*60;

  return segundos;
}

Tiempo obtenerNuevoTiempo(Tiempo tiempo, int seg) {
  struct Tiempo nuevoTiempo = tiempo;

  int minutos = 0;
  int horas = 0;

  nuevoTiempo.segundos += seg;

  if (nuevoTiempo.segundos >= 60) {
    nuevoTiempo.minutos += nuevoTiempo.segundos / 60;
    nuevoTiempo.segundos = nuevoTiempo.segundos % 60;

    if (nuevoTiempo.minutos >= 60) {
      nuevoTiempo.hora += nuevoTiempo.minutos / 60;
      nuevoTiempo.minutos = nuevoTiempo.minutos % 60;
    }
  }

  return nuevoTiempo;
}
