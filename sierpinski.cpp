#include "sierpinski.h"

Sierpinski::Sierpinski(){}

Sierpinski::Sierpinski(Triangulo t){
	
    calcularSierpinski(t);
	
}


void Sierpinski::calcularSierpinski(Triangulo t){
	calcularSierpinski(t, 0);
}

void Sierpinski::calcularSierpinski(Triangulo t, int step){
	
	//Si es el ultimo paso, añade el triangulo que tiene a la lista final
	if(step >= MAXSTEPS){
		lista.push_back(t);
		return;
	}
	
	//Cachea las busqueadas del punto
	Punto puntoA = t.getA();
	Punto puntoB = t.getB();
	Punto puntoC = t.getC();
	
	//calcula los puntos medios del triangulo actual
	Punto aux1(puntoA.middlePoint(puntoB));
	Punto aux2(puntoB.middlePoint(puntoC));
	Punto aux3(puntoC.middlePoint(puntoA));
	
	//Precalcula el step
	step = step+1;
	
	//Calcula los siguientes pasos de forma recursiva
	calcularSierpinski(Triangulo(PuntoA, aux1, aux3), step);
	calcularSierpinski(Triangulo(aux1, puntoB, aux2), step);
	calcularSierpinski(Triangulo(aux1, puntoB, aux2), step);
}
