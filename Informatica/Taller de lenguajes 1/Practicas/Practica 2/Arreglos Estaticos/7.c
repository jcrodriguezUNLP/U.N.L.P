#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ANIOS 10
#define MESES 12
#define DIAS 30

void llenarPrecipitaciones( float precipitaciones[ANIOS][MESES][DIAS] ) {
    srand(time(NULL));
    for (int anio = 0; anio < ANIOS; anio++) {
        for (int mes = 0; mes < MESES; mes++) {
            for (int dia = 0; dia < DIAS; dia++) {
                precipitaciones[anio][mes][dia] = (rand() % 100) / 10.0; // Precipitaciones entre 0.0 y 10.0
            }
        }
    }
}

float calcularPromedioAnual(float precipitaciones[MESES][DIAS]) {
    float suma = 0.0;
    for (int mes = 0; mes < MESES; mes++) {
        for (int dia = 0; dia < DIAS; dia++) {
            suma += precipitaciones[mes][dia];
        }
    }
    return suma / (MESES * DIAS);
}

int mesMenorPrecipitacion(float precipitaciones[MESES][DIAS]) {
    float sumaMensual[MESES] = {0};
    for (int mes = 0; mes < MESES; mes++) {
        for (int dia = 0; dia < DIAS; dia++) {
            sumaMensual[mes] += precipitaciones[mes][dia];
        }
    }

    int mesMin = 0;
    for (int mes = 1; mes < MESES; mes++) {
        if (sumaMensual[mes] < sumaMensual[mesMin]) {
            mesMin = mes;
        }
    }
    return mesMin;
}

int main() {
    float precipitaciones[ANIOS][MESES][DIAS];
    llenarPrecipitaciones(precipitaciones);

    int mesMenor[ANIOS];
    float promedioAnual[ANIOS];
    float menorPromedio = __FLT_MAX__;
    int anioMenorPromedio = 0;

    for (int anio = 0; anio < ANIOS; anio++) {
        mesMenor[anio] = mesMenorPrecipitacion(precipitaciones[anio]);
        promedioAnual[anio] = calcularPromedioAnual(precipitaciones[anio]);

        if (promedioAnual[anio] < menorPromedio) {
            menorPromedio = promedioAnual[anio];
            anioMenorPromedio = anio;
        }
    }

    for (int anio = 0; anio < ANIOS; anio++) {
        printf("Anio %02d: Mes con menor precipitacion: %02d\n", anio + 1, mesMenor[anio] + 1);
    }
    printf("El anio con menor precipitacion promedio es: %d con un promedio de %.2f\n", anioMenorPromedio + 1, menorPromedio);

    return 0;
}