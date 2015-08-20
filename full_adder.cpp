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

int main(){
    bool a,b,ci,co,s;
    a = true;
    b = false;
    ci = true;
    full_add(a,b,ci,&co,&s);
    cout << a << "+" << b << "+" << ci << "= " << co << "," << s << endl;

}
