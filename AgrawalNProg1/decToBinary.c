//Nirav Agrawal
//nkagrawa

#include "myinclude.h"
#include "intstack.h"
#include <math.h>

int main(){
  int n;
  StackHndl temp;
  temp = NULL;
  temp = NewStack ();
  
  printf("Input a non-negative decimal integer to convert to binary:\n");
  scanf("%d", &n);

  printf("Decimal %d is ", n);

  if (n == 0){
    Push(temp, 0);
  }
  while (n > 0){
    if ( (n % 2) == 1){
      Push(temp, 1);
    }
    else{
      Push(temp, 0);
    }
    n = (int)(floor((double)(n/2)));
  }
  while (! IsEmpty(temp)){
    printf("%d", Top(temp));
    Pop (temp);
  }
  printf(" in binary.\n");
}
