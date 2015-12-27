#ifndef PUNTO_H
#define PUNTO_H


class Punto
{

private:
    float X,Y;
public:
    Punto();
    Punto(float x, float y){
        X = x;
        Y = y;
    }
    float getX(){return X;}
    float getY(){return Y;}
    Punto middlePoint(Punto B);
};

#endif // PUNTO_H
