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
            // Como estas variables existen dentro del ambito local(funcion) y a nivel clase/objeto
            // es necesario indicar cual es la variable de clase utilizando el puntero this
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
    int litros = 10;
    int lXKm = 1;
    int kilometraje= 0;
    int maxTanque = 20;

    bool encendido = false;
    int opcion;

    while(true){
        cout << "EDO-> l:" << litros << " kms:" << kilometraje << " enc:" << encendido << endl;
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
                kilometraje += opcion;
                litros -= opcion * lXKm;
                break;
            case 2:
                litros = maxTanque;
                break;
            case 3:
                if( encendido)
                    cout << "Error, ya esta encendido" << endl;
                else
                    encendido = true;
                break;
            case 4:
                if ( encendido)
                    encendido = false;
                else
                    cout << "Ya esta apagado" << endl;
                break;
        }
    }
    return 0;
}
