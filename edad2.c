#include <stdio.h>

void edad();
int imprimir();

void main(){
    edad();
    int edad = imprimir();
    printf("Tienes %d años de edad\n", edad);
}

void edad(){
    int año_actual = 2025;
    int año_nac = 2005;
    int edad;
    edad = año_actual - año_nac;
    printf("Tienes %d años de edad\n", edad);
}

int imprimir(){
    int año_actual = 2025;
    int año_nac = 2005;
    int edad;
    edad = año_actual - año_nac;
    return edad;
}