// 1. Promedio por materia: Determinar el promedio de calificaciones en cada materia.  
// 2. Promedio por estudiante: Calcular el promedio de cada estudiante en función de sus calificaciones en todas las materias.  
// 3. Alumno con mejor promedio: Identificar al estudiante con el mejor promedio general.  
// 4. Materia con mejor desempeño: Determinar qué materia tiene el promedio más alto.  
// 5. Materias con problemas: Identificar aquellas materias cuyo promedio general sea menor a un umbral de aprobación.  
// 6. Estudiantes con problemas: Listar los estudiantes que han reprobado al menos una materia y aquellos cuyo promedio general sea menor al umbral de aprobación.  

//umbral: 6.0

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float generar_cal();
void ingresar_alumnos(int num_alumnos, int num_materias, float matriz[10][10]);
int num_alumnos();
float promedio_alumno(float calificaciones[], int num_materias);
int num_materias = 7;
float promedio_materia(float matriz[10][10], int num_alumnos, int materia);
int materia_mejor_desempeno(float matriz[10][10], int num_alumnos, int num_materias);
int alumno_mejor_promedio(float matriz[10][10], int num_alumnos, int num_materias);
int materias_con_problemas(float matriz[10][10], int num_alumnos, int num_materias, float umbral); 
int estudiantes_con_problemas(float matriz[10][10], int num_alumnos, int num_materias, float umbral);// Función que solicita al usuario el número de alumnos a calificar

int num_alumnos() {
    int num;
    printf("Ingresa el número de alumnos a calificar: ");
    scanf("%d", &num);
    return num;
}

void ingresar_alumnos(int num_alumnos, int num_materias, float matriz[10][10]) {
    for (int i = 0; i < num_alumnos; i++) {
        printf("Ingresa el nombre del alumno %d: ", i + 1);
        char nombre[50]; 
        scanf("%s", nombre);
        printf("Nombre del alumno %d: %s\n", i + 1, nombre); // Mostrar el nombre ingresado

        for (int j = 0; j < num_materias; j++) {
            matriz[i][j] = generar_cal();
        }
    }
}

// Función que genera una calificación aleatoria entre 5.0 y 10.0
float generar_cal() {
    return 5.0 + (rand() % 51) / 10.0; // Genera valores en el rango [5.0, 10.0]
}

float promedio_alumno(float calificaciones[], int num_materias) {
    float suma = 0.0;
    for(int i = 0; i < num_materias; i++) {
        suma += calificaciones[i];
    }
    float promedio = suma / num_materias;
    printf("El promedio del alumno es: %.1f\n", promedio);
    return promedio;
}

int main() {
    float matriz[10][10];
    srand(time(NULL));

    int num = num_alumnos();
    int num_materias = 7; 

    ingresar_alumnos(num, num_materias, matriz);

    printf("Calificaciones de los alumnos\n");

    for (int i = 0; i < num; i++) {
        printf("Alumno %d: ", i + 1);
        for (int j = 0; j < num_materias; j++) {
            
        }
        printf("\n");
    }
    for (int i = 0; i < num_materias; i++) {
        promedio_materia(matriz, num, i);
    }

    for (int i = 0; i < num; i++) {
        promedio_alumno(matriz[i], num_materias);
    }

    materia_mejor_desempeno(matriz, num, num_materias);
    alumno_mejor_promedio(matriz, num, num_materias);
    materias_con_problemas(matriz, num, num_materias, 6.0); 
    estudiantes_con_problemas(matriz, num, num_materias, 6.0); 

    return 0;
}


float promedio_materia(float matriz[10][10], int num_alumnos, int materia) {
    float suma = 0.0;
    for (int i = 0; i < num_alumnos; i++) {
        suma += matriz[i][materia];
    }
    float promedio = suma / num_alumnos;
    printf("El promedio de la materia %d es: %.1f\n", materia + 1, promedio);
    return promedio;
}

int materia_mejor_desempeno(float matriz[10][10], int num_alumnos, int num_materias) {
    int mejor_materia = 0;
    float mejor_promedio = promedio_materia(matriz, num_alumnos, 0);
    for (int i = 1; i < num_materias; i++) {
        float promedio_actual = promedio_materia(matriz, num_alumnos, i);
        if (promedio_actual > mejor_promedio) {
            mejor_promedio = promedio_actual;
            mejor_materia = i;
        }
    }
    printf("La materia con mejor desempeño es la %d con un promedio de %.1f\n", mejor_materia + 1, mejor_promedio);
    return mejor_materia;
}

int alumno_mejor_promedio(float matriz[10][10], int num_alumnos, int num_materias) {
    int mejor_alumno = 0;
    float mejor_promedio = promedio_alumno(matriz[0], num_materias);
    for (int i = 1; i < num_alumnos; i++) {
        float promedio_actual = promedio_alumno(matriz[i], num_materias);
        if (promedio_actual > mejor_promedio) {
            mejor_promedio = promedio_actual;
            mejor_alumno = i;
        }
    }
    printf("El alumno con mejor promedio es el %d con un promedio de %.1f\n", mejor_alumno + 1, mejor_promedio);
    return mejor_alumno;
}

int materias_con_problemas(float matriz[10][10], int num_alumnos, int num_materias, float umbral) {
    int count = 0;
    for (int i = 0; i < num_materias; i++) {
        float promedio = promedio_materia(matriz, num_alumnos, i);
        if (promedio < umbral) {
            printf("La materia %d tiene problemas con un promedio de %.1f\n", i + 1, promedio);
            count++;
        }
    }
    return count;
}

int estudiantes_con_problemas(float matriz[10][10], int num_alumnos, int num_materias, float umbral) {
    int count = 0;
    for (int i = 0; i < num_alumnos; i++) {
        float promedio = promedio_alumno(matriz[i], num_materias);
        if (promedio < umbral) {
            printf("El alumno %d tiene problemas con un promedio de %.1f\n", i + 1, promedio);
            count++;
        }
        for (int j = 0; j < num_materias; j++) {
            if (matriz[i][j] < umbral) { // Si la calificación es menor al umbral
                printf("El alumno %d ha reprobado la materia %d con una calificación de %.1f\n", i + 1, j + 1, matriz[i][j]);
                count++;
                break;
            }
        }
    }
    return count;
}