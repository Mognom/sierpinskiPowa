#include "punto.h"

Punto::Punto(){

}

Punto Punto::middlePoint(Punto B){
    return Punto( (X+B.getX())/2 , (Y+B.getY())/2);
}
