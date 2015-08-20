#include <iostream>
using namespace std;
// Funcion que desplega un arreglo de ints por pantalla
void dispArray(int *arr, int size){
    cout << "[" ;
    for (int i=0; i< size ;i++){
        if (i != 0)
            cout << "," ;
        cout << arr[i]; 
    }
    cout << "]" << endl;
}
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
    dispArray(vector, 3); // a vector no se le saca la direccion, pues por ser un array ya es un puntero.
    // calculando valores
    for (int i=0; i<3 ;i++){
        vector[i] = vector[i] * vector[i];
    }

    // mostrando el resultado
    dispArray(vector, 3);
    return 0;

}

