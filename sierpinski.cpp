#include "sierpinski.h"

Sierpinski::Sierpinski(){}

Sierpinski::Sierpinski(Triangulo t){
	
    calcularSierpinski(t);
	
}


void Sierpinski::calcularSierpinski(Triangulo t){
	listaTrabajos.push_back(t, 0);
	
	Triangulo triActual;
	int stepActual;
	
	std::tuple<Triangulo,int> tuplaActual;
	
	//Calcula cuantos hay al final
	stop = Math.pow(MAXSTEPS-1,3);
	
	while (stop > 0){
		//Lee el trabajo actual
		tuplaActual = listaTrabajos.pop();
		triActual = std::get<0> (tuplaActual);
		stepActual = std::get<1> (tuplaActual);
		
		//Realiza el trabajo
		calcularSierpinski(triActual, stepActual);
	}
}

void Sierpinski::calcularSierpinski(Triangulo t, int step){
	
	//Si es el ultimo paso, añade el triangulo que tiene a la lista final
	if(step >= MAXSTEPS){
		stop--;
		return;
	}
	
	//calcula los puntos medios del triangulo actual
	Punto aux1(t.getA().middlePoint(t.getB()));
	Punto aux2(t.getB().middlePoint(t.getC()));
	Punto aux3(t.getC().middlePoint(t.getA()));
	
	//A partir de los puntos medios calcula los siguientes triangulos
	Triangulo t1(t.getA(), aux1, aux3);
	Triangulo t2(aux1, t.getB(), aux2);
	Triangulo t3( aux3, aux2, t.getC());
	
	listaTrabajos.push_back(std::tuple<Triangulo,int> (t1, step+1));
	listaTrabajos.push_back(std::tuple<Triangulo,int> (t2, step+1));
	listaTrabajos.push_back(std::tuple<Triangulo,int> (t3, step+1));
	
	listaResultado.push_back(t1);
	listaResultado.push_back(t2);
	listaResultado.push_back(t3);
	
}
