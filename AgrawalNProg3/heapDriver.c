//Nirav Agrawal
//nkagrawa

#include <stdio.h>
#include <string.h>
#include "heapSort.h"
#include "insertionSort.h"
#include "heap.h"

int verifySort(int* array, int size){

  for (int i = 1; i< size; i++){
    if (array[i-1] > array[i])
      return i;
  }
  return 0;
}

void inputparser (FILE *input){
  int status, maxSize, currentSize;
  int* dataArray;

  status = fscanf(input, "%d", &maxSize);
  if (status != 1){ 
    printf("Invalid Array Size.\n");
    exit(-1);
  }
  currentSize = maxSize;  

  dataArray = (int*)malloc(sizeof(int)*(maxSize+1));

  for(int i = 0; i< maxSize; i++){
    fscanf(input, "%d", &dataArray[i]);
  }

  printf("Heap before Sorted\n");
  if(currentSize > 0 && currentSize <= maxSize){
    printHeap(dataArray, maxSize);
  }
  heapSort(dataArray, currentSize);
  if(verifySort(dataArray, currentSize) == 0){
    printf("Array has been verified to be sorted\n");
  }
  else{
    printf("Array failed to sort\n");
  }
  printf("Heap after Sorted\n");
  printHeap(dataArray, maxSize);

  heapHndl tmp = newHeap(maxSize);
  printf("Created a new heap with newHeap function\n");
  printf("newHeap is %s\n", isEmpty(tmp) ? "empty" : "not empty");
  printf("newHeap is %s\n", isFull(tmp) ? "full" : "not full");

  heapHndl temp = buildHeap(maxSize, dataArray, currentSize);

  printf("Heap from array is %s\n", isEmpty(temp) ? "empty" : "not empty");
  printf("Heap from array is %s\n", isFull(temp) ? "full" : "not full");

  printf("Max value return: %d\n", maxValue(temp));

  deleteMax(temp);

  printf("After deleteMax\n");
  printHeap(temp->intArray, temp->currentSize);
  
  insert(tmp, 10);
  insert(tmp, 5);

  printf("Inserted two elements, 10 and 5, into an empty heap and sorted it.\n");
  printHeap(tmp->intArray, 2);
}

void fileinputparser (char *filename){
  FILE *input = fopen (filename, "r");
  if (input == NULL){
    fprintf (stderr,"%s\n", filename);
  }
  else{
    printf("Opened %s for input. \n", filename);
    inputparser (input);
    if (fclose (input)) fprintf (stderr, "Problem closing %s\n", filename);
  };
}

int main (int argc, char **argv){
  if (argc <2){
    inputparser (stdin);
  }
  else{
    if (strcmp (argv[1], "-") == 0){
      inputparser (stdin);
    }
    else{
      fileinputparser (argv[1]);
    };
  };
  return 0;
}
