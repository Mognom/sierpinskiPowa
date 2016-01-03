#include "sierpinski.h"

Sierpinski::Sierpinski(){}

Sierpinski::Sierpinski(Triangulo t){
	
    calcularSierpinski(t);
	
}


void Sierpinski::calcularSierpinski(Triangulo t){
	calcularSierpinski(t, 0);
}

void Sierpinski::calcularSierpinski(Triangulo t, int step){
	
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
	
	//A partir de los puntos medios calcula los siguientes triangulos
	Triangulo t1(puntoA, aux1, aux3);
	Triangulo t2(aux1, puntoB, aux2);
	Triangulo t3( aux3, aux2, puntoC);
	
	calcularSierpinski(t1,step+1);
	calcularSierpinski(t2,step+1);
	calcularSierpinski(t3,step+1);
}
