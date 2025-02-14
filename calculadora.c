#include <stdio.h>

int n1 = 10;
int n2 = 3;

int suma();
int resta();
int multiplicacion();
float division();

void main(){
    printf("%d + %d = %d\n",n1, n2, suma());
    printf("%d / %d = %f\n", n1, n2, division());
    printf("%d - %d = %d\n", n1, n2, resta());
    printf("%d * %d = %d\n", n1, n2, multiplicacion());
}

int suma(){
    return n1+n2;
}

float division(){
    return n1/(float)n2; //casting explicito
}

int resta(){
    return n1-n2;
}

int multiplicacion(){
    return n1*n2;
}