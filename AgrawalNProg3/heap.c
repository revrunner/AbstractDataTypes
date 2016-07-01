//Nirav Agrawal
//nkagrawa

#include <stdio.h>
#include <string.h>
#include "heap.h"
#include <assert.h>
int heapsize;
// Allocates memory for new Heap starts it empty

heapHndl newHeap(int maxSize){
  heapHndl tempHeap;
  tempHeap = malloc ( sizeof(struct HeapStruct));
  tempHeap->maxSize = maxSize;
  tempHeap->currentSize = 0;
  tempHeap->intArray = (int*)malloc(sizeof(int)*(maxSize+1));
  return tempHeap;
}

//Takes an array with the data in it and moves the data into a heap and returns the heap.

heapHndl buildHeap(int maxSize, int data[], int numData){
  int i;
  heapHndl temp;

  temp = malloc(sizeof(struct HeapStruct));

  temp->intArray = (int*)malloc(sizeof(int)*(maxSize));

  for (i=0; i< numData; i++){
    temp->intArray[i] = data[i];
  }

  temp->maxSize = maxSize;
  temp->currentSize = numData;

  return temp;
}

// Checks if Heap is full or not. Pre condition: Heap isn't null.

int isFull(heapHndl H){

  assert (H != NULL);
  
  return (H->currentSize == H->maxSize);
}

// Checks if Heap is empty or not. Pre condition: Heap isn't null.

int isEmpty(heapHndl H){

  assert (H != NULL);

  return (H->currentSize == 0);
}

// Returns the maxValue of the heapstruct. Pre condition: Heap isn't empty or equal to null.

int maxValue(heapHndl H){

  assert (H != NULL);
  assert (!isEmpty(H));
  
  return (H->intArray[H->currentSize-1]);
}
// Doesn't return anything and deletes the highest priority integer. Pre condition: Heap isn't empty
// or equal to null.

void deleteMax(heapHndl H){

  assert (H != NULL);
  assert (!isEmpty(H));

  H->currentSize--;
}

// Inserts int into the heap. Pre condition: Heap isn't full and Heap is initialized and 
// not equal to null.

void insert(heapHndl H, int priority){
  assert (H != NULL);
  assert (!isFull(H));
 
  H->intArray[H->currentSize++] = priority;
  heapsort(H->intArray, H->currentSize);
}

void printHeap(int* array, int size){
  int i;
  for(i = 0; i< size; i++){
    printf("%d\n", array[i]);
  }
  printf("\n");
}

void heapsort(int *arr,int len)
{
  int i;
  build_max_heap(arr,len);
   for(i= len-1;i>=1;i--)
   {
     swap(&arr[0],&arr[i]);
     heapsize = heapsize -1;
     max_heapify(arr,0);
   }
}

void max_heapify(int *arr,int i)
{
    int l=2*i,r=2*i+1,largest;
    if(l<heapsize && arr[l]>arr[i])
        largest = l;
    else
        largest = i;
    if(r<heapsize && arr[r]>arr[largest])
        largest = r;

    if(largest != i)
    {
      swap(&arr[i],&arr[largest]);
      max_heapify(arr,largest);
    }
}

void build_max_heap(int *arr,int len)
{
  heapsize = len;
  int i;
  for(i =len/2;i>=0;i--)
  {
    max_heapify(arr,i);
  }
}

void swap(int *a ,int *b)
{
  int temp = *a;
  *a= *b;
  *b= temp;
}
