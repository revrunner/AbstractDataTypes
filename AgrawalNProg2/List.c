//Nirav Agrawal
//nkagrawa

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "myinclude.h"
#include "List.h"
#include <assert.h>

typedef struct NodeStruct {
  long data;
  struct NodeStruct* next;
  struct NodeStruct* prev;
} NodeStruct;

typedef struct ListStruct {
  NodePtr first;
  NodePtr last;
  NodePtr current;
} ListStruct;

ListHndl newList ()
{
  ListHndl tempStack;
  tempStack = malloc ( sizeof(ListStruct));
  tempStack->first = NULL;
  tempStack->current = NULL;
  tempStack->last = NULL;
  return tempStack;
}

void freeList (ListHndl *L)
{
  assert ((*L) != NULL);

  while (! isEmpty((*L))){
    deleteFirst (*L);
  }
  free ((*L));
  (*L) = NULL;
}

int isEmpty(ListHndl L)
{
  assert (L != NULL);
  return (L->first == NULL);
}

int offEnd(ListHndl L)
{
  assert (L != NULL);
  return (L->current == NULL);
}

int atFirst(ListHndl L)
{
  assert (L != NULL);
  return (L->current == L->first && !offEnd(L));
}

int atLast(ListHndl L)
{
  assert (L != NULL);
  return (L->current == L->last && !offEnd(L));
}

long getFirst(ListHndl L)
{
  assert (L != NULL);
  assert (!isEmpty(L));
  return (L->first->data);
}

long getLast(ListHndl L)
{
  assert (L != NULL);
  assert (!isEmpty(L));
  return (L->last->data);
}

long getCurrent(ListHndl L)
{
  assert (L != NULL);
  assert (!isEmpty(L));
  return (L->current->data);
}

void makeEmpty(ListHndl L)
{
  assert (L != NULL);
  assert (!isEmpty(L));
  while (!isEmpty(L) && !offEnd(L)){
    L->first = L->first->next;
    if (L->first == L->last){
      L->first = NULL;
      L->last = NULL;
    }
    L->current = L->first;
  }
}

void moveFirst(ListHndl L)
{
  assert (L != NULL);
  assert (!isEmpty(L));
  L->current = L->first;
}

void moveLast(ListHndl L)
{
  assert (L != NULL);
  assert (!isEmpty(L));
  L->current = L->last;
}

void movePrev(ListHndl L)
{
  assert (L != NULL);
  assert (!isEmpty(L));
  assert (!offEnd(L));

  if (!atFirst(L)){
    L->current = L->current->prev;
  }
  else{
    L->current = NULL;
  }
}

void moveNext(ListHndl L)
{
  assert (L != NULL);
  assert (!isEmpty(L));
  assert (!offEnd(L));

  if (!atLast(L)){

    L->current = L->current->next;
  }
  else{
    L->current = NULL;
  }
}

void insert(ListHndl L, long data)
{
  assert (L != NULL);
  
  NodePtr temp = L->first;
  if(L->first == NULL){
    insertAtFront(L, data);
    L->last = L->first;
  }
  else{
    while(temp != NULL && temp->data < data){
      temp = temp->next;
    }
    if (temp == NULL){
      insertAtBack(L, data);
    }
    else{
      NodePtr tmp = malloc(sizeof(NodeStruct));
      tmp->data = data;
      tmp->prev = temp->prev;
      tmp->next = temp;
      temp->prev = tmp;
      if (temp == L->first){
        L->first = tmp;
      }
      else{
        tmp->prev->next = tmp;
      }
    }
  }
}

void insertAtFront(ListHndl L, long data)
{
  assert (L != NULL);
  
  NodePtr temp = malloc(sizeof(NodeStruct));
  temp->data = data;
  if(L->first != NULL){
  temp->next = L->first;
  }
   L->first = temp;
}

void insertAtBack(ListHndl L, long data)
{
  NodePtr temp = malloc(sizeof(NodeStruct));
  temp->data = data;
  temp->prev = L->last;
  L->last->next = temp;
  L->last = temp;
}

void insertBeforeCurrent(ListHndl L, long data)
{
  if(atFirst(L)){
    insertAtFront(L, data);
  }
  else if(atLast(L)){
    insertAtBack(L, data);
  }
  else{
    NodePtr tmp = malloc(sizeof(NodeStruct));
    if (L->current->prev != NULL){
      L->current->prev->next = tmp;
    }
    tmp->data = data;
    tmp->prev = L->current->prev;
    tmp->next = L->current;
    L->current->prev = tmp;
  }
}

void deleteFirst(ListHndl L)
{
  assert (!isEmpty(L));
  
  L->first = L->first->next;
}

void deleteLast(ListHndl L)
{
  assert (!isEmpty(L));

  L->last = L->last->prev;
}

void deleteCurrent(ListHndl L)
{
  assert (!isEmpty(L));
  
  if (atFirst(L)){
    deleteFirst(L);
  }
  else if (atLast(L)){
    deleteLast(L);
  }
  else{
    L->current->next->prev = L->current->prev;
    L->current->prev->next = L->current->next;
  }
}

void printList(FILE* out, ListHndl L, long customerID)
{
  fprintf(out, "%ld\t", customerID);
  if (L->first->data == NULL){
    fprintf(out, "no books purchased\n");
  }
  else{
    NodePtr temp = L->first;
    while (temp != NULL){
      if (temp == L->current){
        fprintf(out, "%ld*\t", temp->data);
      }
      else{
        fprintf(out, "%ld\t", temp->data);
      }
      temp = temp->next;
    }
  }
  printf("\n");
}
