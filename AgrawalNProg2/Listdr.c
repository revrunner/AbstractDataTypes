//Nirav Agrawal
//nkagrawa

#include "myinclude.h"
#include "List.h"

void inputparser (FILE *input, char *filename){
  char buffer[1024];
  long customers, purchases;
  long customer, bookID;
  int status, booksPurchased;
  
  booksPurchased = 0;
  
  status = fscanf(input, "%ld", &customers);
  if (status != 1){ 
    printf("Invalid Customer Count.\n");
    exit(-1);
  }
  status = fscanf(input, "%ld", &purchases);
  if (status != 1){ 
    printf("Invalid Purchase Count.\n");
    exit(-1);
  }
  
  struct ListHndl** list = (struct ListHndl**)calloc(customers, sizeof(struct ListHndl*));

  while((status = fscanf(input, "%ld %ld", &customer, &bookID)) == 2){
    if (customer > customers){
      printf("Invalid Customer ID %ld\n", customer);
      exit(-1);
    }
    
    if(list[customer-1] == NULL){
      list[customer-1] = newList ();
    }
    insert(list[customer-1], bookID);
    booksPurchased++;
  }
  moveFirst(list[1]);
  if(booksPurchased > 0){
    fprintf(stdout, "customer#\tbooks purchased\n");
    for(int x = 0; x < customers; x++){
      printList(stdout, list[x], x+1);
    }
  }
  moveLast(list[1]);
  if(booksPurchased > 0){
    fprintf(stdout, "customer#\tbooks purchased\n");
    for(int x = 0; x < customers; x++){
      printList(stdout, list[x], x+1);
    }
  }
  moveFirst(list[1]);
  insertBeforeCurrent(list[1], 20);
  if(booksPurchased > 0){
    fprintf(stdout, "customer#\tbooks purchased\n");
    for(int x = 0; x < customers; x++){
      printList(stdout, list[x], x+1);
    }
  }
  insertAtFront(list[0], 25);
  insertAtBack(list[2], 33333);
  if(booksPurchased > 0){
    fprintf(stdout, "customer#\tbooks purchased\n");
    for(int x = 0; x < customers; x++){
      printList(stdout, list[x], x+1);
    }
  }
  moveLast(list[0]);
  movePrev(list[0]);
  if(booksPurchased > 0){
    fprintf(stdout, "customer#\tbooks purchased\n");
    for(int x = 0; x < customers; x++){
      printList(stdout, list[x], x+1);
    }
  }
  moveNext(list[0]);
  if(booksPurchased > 0){
    fprintf(stdout, "customer#\tbooks purchased\n");
    for(int x = 0; x < customers; x++){
      printList(stdout, list[x], x+1);
    }
  }
  fprintf(stdout, "Get First 3 %ld\n", getFirst(list[2]));
  fprintf(stdout, "Get Last 3 %ld\n", getLast(list[2]));
  fprintf(stdout, "Get Current 2 %ld\n", getCurrent(list[1]));
  fprintf(stdout, "At First 2 %s\n", atFirst(list[1]) ? "true" : "false");
  moveLast(list[0]);
  fprintf(stdout, "At Last 1 %s\n", atLast(list[0]) ? "true" : "false");
  
}

void fileinputparser (char *filename){
  FILE *input = fopen (filename, "r");
  if (input == NULL){
    fprintf (stderr,"%s\n", filename);
  }
  else{
    printf("Opened %s for input. \n", filename);
    inputparser (input, filename);
    if (fclose (input)) fprintf (stderr, "Problem closing %s\n", filename);
  };
}

int main (int argc, char **argv){
  if (argc <2){
    inputparser (stdin, "-");
  }
  else{
    int argi;
    for (argi = 1; argi < argc; ++argi){
      if (strcmp (argv[argi], "-") == 0){
        inputparser (stdin, "-");
      }
      else{
        fileinputparser (argv[argi]);
      };
    };
  };
  return EXIT_SUCCESS;
}
