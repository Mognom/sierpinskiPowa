#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "punto.h"

class Triangulo
{
private:
    Punto A,B,C;
public:
    Triangulo();
    Triangulo(Punto a, Punto b, Punto c){
        A = a;
        B = b;
        C = c;
    }
    Punto getA(){return A;}
    Punto getB(){return B;}
    Punto getC(){return C;}
};

#endif // TRIANGULO_H
