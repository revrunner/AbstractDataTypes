/* Nirav Agrawal
* nkagrawa
*/


#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "intList.h"

typedef struct Edge* Edge_p;

struct Edge
{
  int from;
  int to;
  double weight;
};

Edge_p parseEdge(char* line)
{
  Edge_p newE = calloc(1, sizeof (Edge_p));
  int numFields;
  numFields = sscanf(line, " %d %d %1g %*s", &newE->from, &newE->to, (float*)&newE->weight);
  if (numFields < 2 || numFields > 3)
    {
      printf("Bad edge: %s", line);
      exit (1);
    }
  if (numFields == 2)
    {
      newE->weight = 0.0;
    }
  return newE;
}

int parseN (char* line){
  int n = atoi (line);
  return n;
}

int loadEdges (FILE *input, IntList* adjVertices){
  char line[1024];
  char* fgetsRetn;
  int num = 0;
  fgetsRetn = fgets(line, 1024, input);
  while (fgetsRetn == line){
    Edge_p e = parseEdge (line);
    adjVertices[e->from] = intCons(e->to, adjVertices[e->from]);
    num++;
    fgetsRetn = fgets(line, 1024, input);
  }
  return num;
}

IntList* initEdges (int n){
  IntList IntNil = 0;
  IntList* adjVertices;
  for (int i = 1; i <= n; i++){
    adjVertices[i] = IntNil;
  }
  return adjVertices;
}

void inputparser (FILE *input, char *filename){
  char buffer[1024];
  int m, n;
  IntList* adjVertices;

  char *linepos = fgets(buffer, sizeof buffer, input);
  linepos = strchr (buffer, '\n');
  if (linepos == NULL){
    fprintf (stderr, "%s: unterminated line\n", filename);
  }
  else{
    *linepos = '\0';
  }
  linepos = strdup (buffer);
  assert (linepos != NULL);
  n = parseN(linepos);
  free(linepos);
  printf("n = %d\n", n);
  adjVertices = initEdges(n);
  m = loadEdges(input, adjVertices);
  printf("m = %d\n", m);
  for (int i = 1; i<= n; i++){
    printf("%d\t", i);
    toString_IntList(i, adjVertices[i]);
  }
}

void fileinputparser (char *filename){
  FILE *input = fopen (filename, "r");
  if (input == NULL){
    fprintf (stderr, filename);
  }
  else{
    printf("Opened %s for input. \n", filename);
    inputparser (input, filename);
    if (fclose (input)) fprintf (stderr, "Problem closing %s\n", filename);
  };
}

void toString_IntList(int index, IntList list){
  if(list == NULL){
    printf("[null]\n");
  }
  else{
    printf("[%d", intFirst(list));
    list = intRest(list);
    while (list != NULL){
      printf(", %d", intFirst(list));
      list = intRest(list);
    }
    printf("]\n");
  }
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

