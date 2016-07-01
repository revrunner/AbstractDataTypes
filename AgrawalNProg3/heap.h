//Nirav Agrawal
//nkagrawa

#ifndef _HEAP_H_INCLUDED_
#define _HEAP_H_INCLUDED_

struct HeapStruct {
  int maxSize;
  int currentSize;
  int* intArray;
};

typedef struct HeapStruct* heapHndl;
typedef int Boolean;
#define TRUE 1
#define FALSE 0

heapHndl newHeap(int maxSize);

heapHndl buildHeap(int maxSize, int data[], int numData);

int isFull(heapHndl H);

int isEmpty(heapHndl H);

void heapsort(int *arr, int len);

void max_heapify(int *arr, int i);

void build_max_heap(int *arr, int len);

void swap(int *a, int *b);

int maxValue(heapHndl H);

void deleteMax(heapHndl H);

void insert(heapHndl H, int priority);

void printHeap(int* array, int size);

#endif /* _HEAP_H_INCLUDED_ */
