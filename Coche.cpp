#include <iostream>

using namespace std;

class Coche{
    public:
        int kilometraje;
        int litros;
        int lXKm ;
        int maxTanque;
        bool encendido;

        Coche(int lXKm, int maxTanque){
            // Estas variables existen solo a nivel clase/objeto
            kilometraje = 0;
            litros = 0;
            encendido = false;
            // Como estas variables existen dentro del ambito local(funcion) 
            // y a nivel clase/objeto es necesario indicar cual es la 
            // variable de clase utilizando el puntero this
            this->lXKm = lXKm;
            this->maxTanque = maxTanque;
            // al ser this un puntero se puede realizar lo siguiente
            // (*this).maxTanque = maxTanque;
        }
        bool encender(){ // this function returns true when success
            if( !encendido ){
                if (litros > 0){
                    encendido = true;
                    return true;
                }
            }
            return false;
        }
        void apagar(){
            encendido = false;
        }
        bool avanzar(int kilometros){
            if (!encendido)
                return false;
            if (litros >= kilometros * lXKm ){
                litros -= kilometros * lXKm;
                kilometraje += kilometros;
                return true;
            }
            return false;
        }
        bool llenarTanque(){
            if(encendido)
                return false;
            litros = maxTanque;
            return true;
        }

        int getLitros(){
            return litros;
        }
        void setLitros(int l){
            litros = l;
        }

        friend ostream& operator<< (ostream &o, Coche &c);
};

ostream& operator<< (ostream &o, Coche &c){
    o << "(L= " << c.litros; 
    o << ";kilometraje= " << c.kilometraje ;
    o << ";" << (c.encendido?"Encendido":"Apagado") ;
    o << ")";
    return o;
}


int main(){
    Coche *c= new Coche(1, 30);
    // Coche c(1, 30); // Esto es lo mismo que arriba
    int opcion;

    while(true){
        
        cout << *c << endl;
        cout << " Elije la opcion " << endl;
        cout << "1: Avanzar" << endl;
        cout << "2: Llenar tanque" << endl;
        cout << "3: Encender" << endl;
        cout << "4: Apagar" << endl;
        cin >> opcion;

        switch (opcion){
            case 1:
                cout << "Dame cuantos kilometros " << endl;
                cin >> opcion;
                (*c).avanzar(opcion);
                break;
            case 2:
                c->llenarTanque();
                break;
            case 3:
                c->encender();
                break;
            case 4:
                c->apagar();
                break;
        }
    }
    delete c;
    return 0;
}
