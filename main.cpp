#include <math.h>
#include <iostream>

#include "triangulo.h"
using namespace std;

int main()
{
    Punto a(0,0);
    Punto b(0.5,sqrt(3)/2);
    Punto c(0,1);

    Triangulo t0(a,b,c);
}

