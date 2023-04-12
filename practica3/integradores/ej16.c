#include <stdio.h>

// Frecuencia de tonos musicales

typedef enum tono {BASE=440, DO=262, RE=294, MI=330, FA=349, SOL=392, LA=440, SI=494} tono_t;

// Estructura de comando

typedef struct comando {
  unsigned encendido : 1;
  unsigned frecuencia : 15;
} comando_t;

// Encendido y apagado del dispositivo

#define NO 0
#define SI 1

/* Prototipos */

comando_t recibir_comando();

void generar_sonido(comando_t);

int main(){

    comando_t c;
    printf("Encendiendo el dispositivo...\r\n");
    c = recibir_comando();
    while(c.encendido == SI){
        // Es un valor de frecuencia válida
        if(c.frecuencia == DO || c.frecuencia == RE || c.frecuencia == MI || c.frecuencia == FA || c.frecuencia == SOL || c.frecuencia == LA || c.frecuencia == SI)
            generar_sonido(c); // Generar tono correspondiente
        else
          printf("ERROR: Valor de frecuencia incorrecto.\r\n");
        c = recibir_comando();
}
    printf("Apagando el dispositivo...\r\n");
    return 0;
}

// Leer comando desde la entrada estándar con el formato "encendido.frecuencia"

comando_t recibir_comando(){
    comando_t c;
    int val1, val2;
    printf("Ingrese comando: ");
    scanf("%d %d", &val1, &val2); // Leer comando
    c.encendido = val1;
    c.frecuencia = val2;
    return c;
}

// Generar tono recibido por parámetro (sin implementar)

void generar_sonido(comando_t c){
    printf("Tono: %d Hz\r\n", c.frecuencia);
    // Generar sonido ...
    return;
}