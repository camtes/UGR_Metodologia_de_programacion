#include "punto.h"
#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

void EscribirPunto(const Punto &p) {
  cout << "(" << p.x << "," << p.y << ")" << endl;
}

Punto LeerPunto() {
  Punto p;

  double x, y;
  scanf("%lf,%lf", &p.x, &p.y);

  return p;
}

double DistanciaPuntos(const Punto &p1, const Punto &p2) {
  double dist = sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
  return dist;
}

Punto PuntoMedio(const Punto &p1, const Punto &p2) {
  Punto p;
  p.x = (p1.x+p2.x)/2;
  p.y = (p1.y+p2.y)/2;

  return p;
}
