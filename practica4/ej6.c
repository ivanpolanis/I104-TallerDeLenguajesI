#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
  int n;
  struct nodo *next;
} nodo;

typedef nodo *list;

list inicializar();
void borrar(list ptr);
void agregarInicio(list ptr);
void agregarFinal(list ptr);
int elems(list ptr);
void printlist(list ptr);

int main()
{
  return 0;
}

list inicializar()
{
  list ptr = (list)malloc(sizeof(list));
  ptr->next = NULL;
  return ptr;
}

void borrar(list *ptr)
{
  while (ptr != NULL)
  {
    list curr = *ptr;
    *ptr = (*ptr)->next;
    free(curr);
  }
}

void agregarInicio(list *ptr, int n)
{
  list new = (list)malloc(sizeof(list));
  printf("Ingrese un numero: ");
  new->n = n;
  new->next = *ptr;
  *ptr = new;
}

void agregarFinal(list *ptr, int n)
{
  list aux = ptr;
  list new = (list)malloc(sizeof(list));
  printf("Ingrese un numero: ");
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

int elems(list *ptr)
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

void printlist(list *ptr)
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