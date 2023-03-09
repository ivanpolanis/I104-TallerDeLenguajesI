#include <stdio.h>

#define NUM_PAISES 14
#define LIMITE_ESPECIES 40

int main() {
    int cantidad_especies[NUM_PAISES];
    char codigo_pais[NUM_PAISES][3];

    // Leer información de cantidad de especies y código de país
    for (int i = 0; i < NUM_PAISES; i++) {
        printf("Ingrese el código de país para el país %d: ", i+1);
        scanf("%s", codigo_pais[i]);

        printf("Ingrese la cantidad de especies de aves para el país %s: ", codigo_pais[i]);
        scanf("%d", &cantidad_especies[i]);
    }

    // Encontrar los 2 países con menor cantidad de especies
    int menor1 = 0, menor2 = 1;
    for (int i = 2; i < NUM_PAISES; i++) {
        if (cantidad_especies[i] < cantidad_especies[menor1]) {
            menor2 = menor1;
            menor1 = i;
        } else if (cantidad_especies[i] < cantidad_especies[menor2]) {
            menor2 = i;
        }
    }
    printf("Los dos países con menor cantidad de especies son:\n");
    printf("%s con %d especies\n", codigo_pais[menor1], cantidad_especies[menor1]);
    printf("%s con %d especies\n", codigo_pais[menor2], cantidad_especies[menor2]);

    // Calcular el porcentaje de países con más de 40 especies
    int paises_con_mas_de_40_especies = 0;
    for (int i = 0; i < NUM_PAISES; i++) {
        if (cantidad_especies[i] > LIMITE_ESPECIES) {
            paises_con_mas_de_40_especies++;
        }
    }
    float porcentaje = (float)paises_con_mas_de_40_especies / NUM_PAISES * 100;
    printf("El porcentaje de países con más de %d especies es: %.2f%%\n", LIMITE_ESPECIES, porcentaje);

    return 0;
}