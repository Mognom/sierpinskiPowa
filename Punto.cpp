//Crea un punto a partir de sus dos coordenadas
Punto::Punto(float x, float y){
	this.x = x;
	this.y = y;
}

Punto::puntoMedio(Punto a, Punto b){
	//calcula el punto medio
	x = (a.x + b.x)/2;
	y = (a.y + b.y)/2;
	
	//LO devuelve. =D
	Punto resultado (x,y);
	return resultado;
}