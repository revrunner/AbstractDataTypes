//Nirav Agrawal
//nkagrawa

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "intList.h"

int main(int argc, char **argv){
  if (argc != 2){
    printf("Expected one file with programs.\n");
    exit(-1);
  }
    FILE *input = fopen(argv[1], "r");

    if (!input){
        fprintf(stderr,"%s\n", argv[1]);
        exit(-1);
    }
    int status, numVerts, numQueries, index, vertex, start, end;
    char line[1024];
    
    status = fscanf(input, "%d %d\n", &numVerts, &numQueries);
    Node** graph = (Node**)calloc(sizeof(Node*), numVerts);
    int i;
    for(i = 0; i < numVerts; i++){
        char* ptr = fgets(line, 1024, input);
        index = atoi(line);
        while (*ptr != 10) {
            while(*ptr != ' ' && *ptr != 10){
                ptr++;
            }
            if (*ptr == ' '){
                vertex = atoi(ptr);
                graph[index] = addEdge(graph[index], vertex);
                ptr++;
            }
        }
    }
    int x;
    for(x = 0; x < numQueries; x++){
        status = fscanf(input, "%d %d", &start, &end);
        bfs(graph, start, numVerts);
        if (hasPathTo(end)) {
            int edgesToEnd = distToo(end);
            printf("To get from %d to %d requires %d edge(s), follow the path ", start, end, edgesToEnd);
            int* path = pathTo(end);
            printf("%d, ", start);
            for(i = 0; i < edgesToEnd-1; i++){
                printf("%d, ", path[i]);
            }
            printf("%d.\n\n", path[edgesToEnd-1]);
            free(path);
        }
        else{
            printf("I am sorry, there is no way to get from %d to %d in this graph.\n\n", start, end);
        }
        freeMemory();
    }
}
