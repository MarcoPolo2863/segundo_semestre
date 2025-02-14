//Escribir un programa que dado el año de nacimiento y el año actual
//Calcule la edad de una persona 
//Escriba una funcion que imprima la edad 

#include <stdio.h>

int main(){

    int anaci;
    int aactual = 2025;
    int edad;

    printf("Dime tu año de nacimiento: \n");
    scanf("%d", &anaci);

    edad = aactual - anaci;

    printf("Tienes %d años de edad\n", edad);
    return edad;
}