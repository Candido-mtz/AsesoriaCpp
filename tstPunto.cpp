#include <iostream.h>
#include "Punto.h"
using namespace std;

int main(){
    Punto p1 = Punto();
    Punto p2 = Punto(3,4);
    Punto *r = p1.suma(&p2);

    float d = p1.distancia(&p2);

    p1.print();
    p2.print();
    r->print();

    p1.setX(10);
    p1.setY(20);
    p2.setX(20);
    p2.setY(40);
    
    p1.print();
    p2.print();
    r->print();

    return 0;
}
