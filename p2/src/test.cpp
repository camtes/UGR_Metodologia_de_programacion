#include <iostream>
#include <string>
#include "bloqueLed.h"

using namespace std;

int main(){
    bloqueLed b;
    int posiciones[8];
    int size;

    apagar(b);
    cout << "\nBloque apagado LEDs: ";
    cout << bloqueLedToString(b) << endl;
    // enciendo dos LEDs
    on(b,5);
    on(b,7);
    cout << bloqueLedToString(b) << endl;
    cout << "\nAhora enciendo los LEDs 0, 1 y 2\n";
    on(b,0);
    cout << bloqueLedToString(b) << endl;
    on(b,1);
    cout << bloqueLedToString(b) << endl;
    on(b,2);
    cout << bloqueLedToString(b) << endl;

    cout << "\nLos LEDs encendidos estan en las posiciones: ";
    encendidos(b,posiciones, size);
    for(int i=0; i< size; i++)
        cout << posiciones[i] << ",";

    cout << endl;

    cout << "\nTodos encendidos: ";
    encender(b);
    cout << bloqueLedToString(b) << endl;

    cout << "\nTodos apagados: ";
    apagar(b);
    cout << bloqueLedToString(b) << endl;

    cout << "\nAhora la animacion\nEjemplo 1 \n";
    for (int i=8; i>=0; i--) {
      encender(b);
      off(b,i);

      cout << bloqueLedToString(b) << endl;
    }

    cout << "\n\nEjemplo 2 \n";
    encender(b);
    for (int i=0; i<9; i++) {
      cout << i << " | "<< bloqueLedToString(b) << endl;

      if (i<4) {
        off(b,i);
        off(b,7-i);
      }
      else {
        on(b,i);
        on(b,j);
      }
    }
}
