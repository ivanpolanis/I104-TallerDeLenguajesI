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

int main()
{
  list l = inicializar(5);
  agregarFinal(&l, 6);
  agregarFinal(&l, 7);
  agregarFinal(&l, 8);
  agregarInicio(&l, 4);
  printlist(l);
  printf("\n");
  printf("size: %d\n", elems(l));
  borrar(&l);
  printlist(l);
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