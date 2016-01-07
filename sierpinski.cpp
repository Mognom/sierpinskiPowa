#include "sierpinski.h"
#include <math.h>
#include <omp.h>

Sierpinski::Sierpinski(){}

Sierpinski::Sierpinski(Triangulo t){
	
    calcularSierpinski(t);
    omp_set_num_threads(8);

}


void Sierpinski::calcularSierpinski(Triangulo t){

	//Cachea las busqueadas del punto
	Punto puntoA = t.getA();
	Punto puntoB = t.getB();
	Punto puntoC = t.getC();
	
	//calcula los puntos medios del triangulo actual
	Punto aux1(puntoA.middlePoint(puntoB));
	Punto aux2(puntoB.middlePoint(puntoC));
	Punto aux3(puntoC.middlePoint(puntoA));

	//Calcula los siguientes pasos de forma recursiva
	#pragma omp single nowait
	{
		#pragma omp task
		calcularSierpinski(Triangulo(puntoA, aux1, aux3), 1);
		#pragma omp task
		calcularSierpinski(Triangulo(aux1, puntoB, aux2), 1);
		#pragma omp task
		calcularSierpinski(Triangulo(aux3, aux2, puntoC), 1);
	}
	
	#pragma omp taskwait
	
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
	
	
	//Calcula los siguientes pasos de forma recursiva
	calcularSierpinski(Triangulo(puntoA, aux1, aux3), step);
	calcularSierpinski(Triangulo(aux1, puntoB, aux2), step);
	calcularSierpinski(Triangulo(aux3, aux2, puntoC), step);
	}
}
