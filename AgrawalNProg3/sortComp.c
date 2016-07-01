//Nirav Agrawal
//nkagrawa

#include <stdio.h>
#include <string.h>
#include "heapSort.h"
#include "insertionSort.h"
#include "heap.h"
#include <time.h>


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
  clock_t startTime, duration;

  startTime = clock();
  insertionSort(insertArray, currentSize);
  duration = clock() - startTime;
  printf ("Insertion sort took %f seconds.\n", ((float) duration)/ CLOCKS_PER_SEC);

  startTime = clock();
  heapSort(dataArray, currentSize);
  duration = clock() - startTime;
  printf ("Heap sort took %f seconds.\n", ((float) duration)/ CLOCKS_PER_SEC);  
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
