/* Nirav Agrawal
* nkagrawa
*/



#include "intList.h"
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct IntListNode{
  int item;
  IntList link;
};

const IntList intNil = NULL;

int intFirst(IntList oldL){
  assert(oldL != intNil);
  return oldL->item;
}

IntList intRest(IntList oldL){
  assert(oldL != intNil);
  return oldL->link;
}

IntList intCons(int newE, IntList oldL){
  if (oldL == intNil){
    IntList list = malloc( sizeof(struct IntListNode));
    return list;
  }
  else
    {
    IntList list = malloc( sizeof(struct IntListNode));
    list->item = newE;
    list->link = oldL;
    return list;
    }
}
