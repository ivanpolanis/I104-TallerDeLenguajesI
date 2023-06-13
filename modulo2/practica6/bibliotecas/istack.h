#ifndef ISTACK_H
#define ISTACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node *next;
} Node;

typedef Node *Stack;

Stack create(){
  Stack s = NULL;
  return s;
}

int s_push(Stack *s, int n){
  Node *newNode = (Node*)malloc(sizeof(Node));
  if(newNode == NULL){
    return 0;
  }
  newNode->data = n;
  newNode->next = *s;
  *s = newNode;
  return n;
}

int s_pop(Stack *s){
  if(s == NULL){
    return 0;
  }
  if((*s) == NULL){
    return 0;
  }
  Node *aux = *s;
  *s = aux->next;
  int n = aux->data;
  free(aux);
  return n;
}

int s_top(Stack *s){
  if(s == NULL){
    return 0;
  }
  if((*s) == NULL){
    return 0;
  }
  return (*s)->data;
}

int s_empty(Stack *s){
  if(s == NULL){
    return 0;
  }
  if((*s) == NULL){
    return 1;
  }
  return 0;
}

int s_length(Stack *s){
  if(s == NULL){
    return 0;
  }
  if((*s) == NULL){
    return 0;
  }
  int length = 0;
  Node *aux = *s;
  while(aux != NULL){
    length++;
    aux = aux->next;
  }
  return length;
}


#endif