#include <math.h>
#include <iostream>

#include "sierpinski.h"
using namespace std;

int main()
{
    Punto a(0,0);
    Punto b(0.5,sqrt(3)/2);
    Punto c(0,1);

    Triangulo t0(a,b,c);
    Sierpinski s(t0);
    std::list<Triangulo> l = s.getLista();
    printf("%i\n",l.size());
}

