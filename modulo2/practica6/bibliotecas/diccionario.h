#ifndef DICCIONARIO_H
#define DICCIONARIO_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct{
    char **arr;
    int size;
    int capacity;
}dict;

dict crearDiccionario(){
    dict aux;
    char **arr = (char **)malloc(sizeof(char *)*100);
    aux.arr = arr;
    aux.size=0;
    aux.capacity=100;
    return aux;
}

int existePalabra(dict d, char* str){
    int i;
    for (i=0; i<d.size; i++){
        if (strcmp(d.arr[i], str) == 0)
            return 1;
    }
    return 0;
}

int agregarPalabra(dict *d, char* str){
    if (existePalabra(*d, str))
        return 0;
    if (d->size == d->capacity){
        d->capacity *= 2;
        d->arr = (char **)realloc(d->arr, sizeof(char *)*d->capacity);
    }
    d->arr[d->size] = (char *)malloc(sizeof(char)*(strlen(str)+1));
    strcpy(d->arr[d->size], str);
    d->size++;
    return 1;
}

int eliminarPalabra(dict *d, char* str){
    int i;
    for (i=0; i<d->size; i++){
        if (strcmp(d->arr[i], str) == 0){
            free(d->arr[i]);
            d->arr[i] = d->arr[d->size-1];
            d->size--;
            return 1;
        }
    }
    return 0;
}

dict cargarDiccionario(){
    dict aux = crearDiccionario();
    FILE *f = fopen("diccionario.txt", "r");
    char str[100];
    while (fscanf(f, "%s", str) != EOF){
        agregarPalabra(&aux, str);
    }
    fclose(f);
    return aux;
}

void guardarDiccionario(dict d){
    FILE *f = fopen("diccionario.txt", "w");
    int i;
    for (i=0; i<d.size; i++){
        fprintf(f, "%s\n", d.arr[i]);
    }
    fclose(f);
}

void destruirDiccionario(dict *d){
    int i;
    for (i=0; i<d->size; i++){
        free(d->arr[i]);
    }
    free(d->arr);
    d->size = 0;
    d->capacity = 0;
}
#endif