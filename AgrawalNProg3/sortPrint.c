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
  int* insertArray; 

  status = fscanf(input, "%d", &maxSize);
  if (status != 1){ 
    printf("Invalid Array Size.\n");
    exit(-1);
  }
  currentSize = maxSize;  

  dataArray = (int*)malloc(sizeof(int)*(maxSize+1));
  insertArray = (int*)malloc(sizeof(int)*(maxSize+1));

  for(int i = 0; i< maxSize; i++){
    fscanf(input, "%d", &dataArray[i]);
    insertArray[i] = dataArray[i];
  }

  printf("Insertion before Sorted\n");
  if(currentSize > 0 && currentSize <= maxSize){
    printHeap(insertArray, maxSize);
  }
  
  insertionSort(insertArray, currentSize);
  if(verifySort(insertArray, currentSize) == 0){
    printf("Array has been verified to be sorted\n");
  }
  else{
    printf("Array failed to sort\n");
  }
  printf("Insertion after Sorted\n");
  printHeap(insertArray, maxSize);

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
