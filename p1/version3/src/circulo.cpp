#include "circulo.h"
#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

void EscribirCirculo(const Circulo &p) {
  cout << p.radio << "-(" << p.centro.x << "," << p.centro.y << ")" << endl;
}

Circulo LeerCirculo() {
  Circulo c;
  Punto p;
  double radio, x, y;

  scanf("%lf-(%lf,%lf)", &c.radio, &c.centro.x, &c.centro.y);
  
  return c;
}

double AreaCirculo(const Circulo &c) {
  return M_PI*c.radio*c.radio;
}
