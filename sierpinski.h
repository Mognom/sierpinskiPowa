#ifndef SIERPINSKI_H
#define SIERPINSKI_H

#define MAXSTEPS 2

#include <list>
#include "triangulo.h"

class Sierpinski{

private:
    std::list<Triangulo> lista;

    void calcularSierpinski(Triangulo t);
    void calcularSierpinski(Triangulo t, int step);

public:
    Sierpinski();
    Sierpinski(Triangulo t);
    std::list<Triangulo> getLista(){return lista;}

};

#endif
