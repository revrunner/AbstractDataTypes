//Nirav Agrawal
//nkagrawa

#include "libraryList.h"

int main(int argc, char **argv){
  if (argc != 3){
    printf("Expected two files with programs.\n");
    exit(-1);
  }
  FILE *input = fopen(argv[1], "r");
  FILE *commands = fopen(argv[2], "r");

  if (!input){
      fprintf(stderr,"%s\n", argv[1]);
  }

  if (!commands){
    fprintf(stderr,"%s\n", argv[2]);
  }
  
  int status, arraySize, totalProbes, libraryID, bookSearch;
  char line[100];
  char search[40];

  status = fscanf(input, "%d %d\n", &totalProbes, &arraySize);

  BookFCL** fclArray = (BookFCL**)calloc(sizeof(BookFCL*), arraySize);

  for(int i = 0; i<= totalProbes-1; i++){
    fgets(line, 100, input);
    int j = 0;
    while(line[j] != ','){
      j++;
    }
    line[j] = 0;
    libraryID = atoi(line);
    char* ptr = &line[j+2];
    while(*ptr && *ptr != 13 && *ptr != 10){
      ptr++;
    }
    *ptr = 0;
    insert(fclArray, arraySize, &line[j+2], libraryID);
  }
  status = fscanf(commands, "%d\n", &bookSearch);
  for(int x = 0; x < bookSearch; x++){
    fgets(search, 40, commands);
    char* point = search;
    while(point && *point != 13 && *point != 10){
      point++;
    }
    *point = 0;
    listLibraries(find(fclArray, arraySize, search));
  }
}
