#include "sierpinski.h"
#include <math.h>
#include <omp.h>

Sierpinski::Sierpinski(){}

Sierpinski::Sierpinski(Triangulo t){
	
    calcularSierpinski(t);
    omp_set_num_threads(8);

}


void Sierpinski::calcularSierpinski(Triangulo t){

    listaTrabajos.push_back(std::tuple<Triangulo, int>(t, 0));
	
	Triangulo triActual;
	int stepActual;
	
	std::tuple<Triangulo,int> tuplaActual;
	
	//Calcula cuantos hay al final
    stop = pow(3,MAXSTEPS);

    #pragma omp parallel private(triActual, stepActual, tuplaActual)
	while (stop > 0){
		//Lee el trabajo actual
		#pragma omp critical
		{
			if(listaTrabajos.empty())
				flag = true;
			else{
				tuplaActual = listaTrabajos.back();
				listaTrabajos.pop_back();
			}
		}
		if(!flag){
			triActual = std::get<0> (tuplaActual);
			stepActual = std::get<1> (tuplaActual);
		
			//Realiza el trabajo
			calcularSierpinski(triActual, stepActual);
		}
	}
}

void Sierpinski::calcularSierpinski(Triangulo t, int step){
	
	//Si es el ultimo paso, añade el triangulo que tiene a la lista final
	if(step >= MAXSTEPS){
		listaResultado.push_back(t);
		stop--;
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
	
	listaTrabajos.push_back(std::tuple<Triangulo,int> (Triangulo(puntoA, aux1, aux3), step));
	listaTrabajos.push_back(std::tuple<Triangulo,int> (Triangulo(aux1, puntoB, aux2), step));
	listaTrabajos.push_back(std::tuple<Triangulo,int> (Triangulo(aux3, aux2, puntoC), step));
	
	//Calcula los siguientes pasos de forma recursiva
    //calcularSierpinski(Triangulo(puntoA, aux1, aux3), step);
	//calcularSierpinski(Triangulo(aux1, puntoB, aux2), step);
    //calcularSierpinski(Triangulo(aux3, aux2, puntoC), step);
}
