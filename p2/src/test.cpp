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
    //encendidos(b,posiciones, size);
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
    // aqui debes escribir las instrucciones para que se muestre
    // el primer ejemplo de animacion.

    cout << "\n\nEjemplo 2 \n";
    // aqui debes escribir las instrucciones para que se muestre
    // el segundo ejemplo de animacion.

}
