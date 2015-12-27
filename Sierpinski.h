#define MAXSTEPS 10
#include "Triangulo.h"
#include "Punto.h"
#include <list>

class Sierpinski{
	public:
		Sierpinski();
		Sierpinski(Triangulo t);
	
	private:
		std::list<Triangulo> lista;
		
		void calcularSierpinski(Triangulo t);
		void calcularSierpinski(Triangulo t, int step);
};