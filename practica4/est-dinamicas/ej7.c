#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
  int n;
  struct nodo *next;
} nodo;

typedef nodo *list;

list inicializar(int);
void borrar(list *ptr);
void agregarInicio(list *ptr, int);
void agregarFinal(list *ptr, int);
int elems(list ptr);
void printlist(list ptr);
list invertir(list ptr);

int main()
{
  list l = NULL;
  int n;
  do{
    printf("Ingrese un numero(0 para terminar): ");
    scanf("%d", &n);
    agregarFinal(&l, n);
  } while (n != 0);
  list il = invertir(l);
  printlist(l);
  printf("\n");
  printlist(il);
  return 0;
}

list inicializar(int n)
{
  list ptr = (list)malloc(sizeof(nodo));
  ptr->n = n;
  ptr->next = NULL;
  return ptr;
}

void borrar(list *ptr)
{
  while (*ptr != NULL)
  {
    list curr = *ptr;
    *ptr = (*ptr)->next;
    free(curr);
  }
}

void agregarInicio(list *ptr, int n)
{
  list new = (list)malloc(sizeof(nodo));
  new->n = n;
  new->next = *ptr;
  *ptr = new;
}

void agregarFinal(list *ptr, int n)
{
  list aux = *ptr;
  list new = (list)malloc(sizeof(nodo));
  new->n = n;
  new->next = NULL;
  if (aux != NULL)
  {
    while (aux->next != NULL)
      aux = aux->next;
    aux->next = new;
  }
  else
  {
    *ptr = new;
  }
}

int elems(list ptr)
{
  int el = 0;
  if (ptr != NULL)
  {
    list aux = ptr;
    while (aux != NULL)
    {
      aux = aux->next;
      el++;
    }
  }
  return el;
}

void printlist(list ptr)
{
  if (ptr != NULL)
  {
    list aux = ptr;
    while (aux->next != NULL)
    {
      printf("%d->", aux->n);
      aux = aux->next;
    }
    printf("%d", aux->n);
  }
  else
    printf("La lista no tiene elementos");
}

list invertir(list ptr){
  list l=NULL;
  while(ptr != NULL){
    agregarInicio(&l, ptr->n);
    ptr = ptr->next;
  }
  return l;
}