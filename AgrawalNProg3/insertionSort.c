//Nirav Agrawal
//nkagrawa

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "insertionSort.h"

void insertionSort (int keys[], int numKeys){
  int xindex;
  for (xindex = 1; xindex < numKeys; xindex++){
    int current = keys[xindex];
    int xLoc = shiftVac(keys, xindex, current);
    keys[xLoc] = current;
  }
}

int shiftVac(int Keys[], int xindex, int current){
  int vacant, xLoc;
  vacant = xindex;
  xLoc = 0; //Assume failure
  while (vacant > 0){
    if (Keys[vacant-1] <= current){
      xLoc = vacant; //Succeed.
      break;
    }
    Keys[vacant] = Keys[vacant-1];
    vacant--; //Keep Looking.
  }
  return xLoc;
}
    
