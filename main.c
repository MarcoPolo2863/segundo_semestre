/* Escriba un programa que imprima los dias de la semana en dos fucnioes, uno que imprima los dias habiles y otro los dias 
de fin de semana 
*/

#include <stdio.h>

void entresemana(); // prototipo
void findesemana();

void main(){
    entresemana();
    findesemana();

}

void entresemana(){
    printf("Lunes\n Martes\nMiercoles\nJueves\nViernes\n ");
}
void findesemana(){
    printf("Sabado\nDomingo\n");
}