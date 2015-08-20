#include <iostream>

using namespace std;

/**
    Programa que modelara el full adder, mediante una funcion que obtenga
    la suma y el carry out, a partir de los operandos a, b y el carry in.
    Los tipos de datos seran bool
    */

void full_add(bool A ,bool B,bool C,bool *CO,bool *S){
    *S = A ^ B ^ C;
    *CO = (A && B) || (B && C) || (A && C);
}

void full_add(bool *A ,bool *B,bool C,bool *CO,bool *S,int size){
    bool ci=C;
    for(int i=0;i<size ;i++){
        full_add(A[i],B[i],ci,CO,&S[i]);
        ci = *CO;
    }
}
void desplega(bool *array, int size){
    for ( int i=size-1;i>=0;i--){
        cout << array[i] << "";
    }
}

int main(){
    bool a,b,ci,co,s;
    a = true;
    b = false;
    ci = true;
    full_add(a,b,ci,&co,&s);
    cout << a << "+" << b << "+" << ci << "= " << co << "," << s << endl;

    // Cosas para hacerlo de muchos bits

    bool op1[]={true,false,true,false};
    bool op2[]={0,false,true,true};
    bool ci2 = false;
    bool suma[4];
    bool co2;

    full_add(op1,op2,ci2,&co2,suma,4);
    desplega(op1,4);
    cout << "+" ;
    desplega(op2,4);
    cout << "= " << co2<<",";
    desplega(suma,4);
    cout << endl;
}
