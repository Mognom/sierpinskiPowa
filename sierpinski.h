
#ifndef SIERPINSKI_H
#define SIERPINSKI_H

#define MAXSTEPS 13 //MAX 13

#include <list>
#include <tuple>
#include "triangulo.h"

class Sierpinski{

private:
    std::list<Triangulo> listaResultado;
	std::list<std::tuple<Triangulo, int>> listaTrabajos;
	int stop;

    void calcularSierpinski(Triangulo t);
    void calcularSierpinski(Triangulo t, int step);

public:
    Sierpinski();
    Sierpinski(Triangulo t);
    std::list<Triangulo> getLista(){return lista;}

};

#endif