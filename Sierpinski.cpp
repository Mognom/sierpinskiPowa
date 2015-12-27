#include "Sierpinski.h"

Sierpinski::Sierpinski(){}

Sierpinski::Sierpinski(Triangulo t){
	
	calcularSierpinski(t);
	
}


Sierpinski::calcularSierpinski(Triangulo t){
	calcularSierpinski(t, 0);
}

Sierpinski::calcularSierpinski(Triangulo t, int step){
	
	if(step >= MAXSTEPS)
		return;
	
	//calcula los puntos medios del triangulo actual
	Punto aux1(t.getA().middlePoint(t.getB()));
	Punto aux2(t.getB().middlePoint(t.getC()));
	Punto aux3(t.getC().middlePoint(t.getA()));
	
	//A partir de los puntos medios calcula los siguientes triangulos
	Triangulo t1(t.getA(), aux1, aux3);
	Triangulo t2(aux1, t.getB(), aux2);
	Triangulo t3( aux3, aux2, t.getC());
	
	lista.push_back(t1);
	lista.push_back(t2);
	lista.push_back(t3);
	
	calcularSierpinski(t1,step+1);
	calcularSierpinski(t2,step+1);
	calcularSierpinski(t3,step+1);
}