#include <iostream>
using namespace std;

int main(){
     // Se declara un vector de longitud 3 y tipo de dato int
    int vector[3];
    // Pidiendo valores
    cout << "Dame los valores del vector" << endl;
    for (int i=0; i<3 ;i++){
        cout << "Dame el valor " << (i+1) << endl;
        cin >> vector[i];
    }

    // mostrado el vector
    cout << "[" ;
    for (int i=0; i<3 ;i++){
        if (i != 0)
            cout << "," ;
        cout << vector[i]; 
    }
    cout << "]" << endl;

    // calculando valores
    for (int i=0; i<3 ;i++){
        vector[i] = vector[i] * vector[i];
    }

    // mostrando el resultado
    cout << "[" ;
    for (int i=0; i<3 ;i++){
        if (i != 0)
            cout << "," ;
        cout << vector[i]; 
    }
    cout << "]" << endl;

    return 0;

}

