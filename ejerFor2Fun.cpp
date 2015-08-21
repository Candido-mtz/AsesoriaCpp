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
	const int SIZE = 5;
    int vector[SIZE];
    // Pidiendo valores
    cout << "Dame los valores del vector" << endl;
    for (int i=0; i<SIZE ;i++){
        cout << "Dame el valor " << (i+1) << endl;
        cin >> vector[i];
    }

    // mostrado el vector
    dispArray(vector, SIZE); // a vector no se le saca la direccion, pues por ser un array ya es un puntero.
    // calculando valores
    for (int i=0; i< SIZE ;i++){
        vector[i] = vector[i] * vector[i];
    }

    // mostrando el resultado
    dispArray(vector, SIZE);
    return 0;

}

