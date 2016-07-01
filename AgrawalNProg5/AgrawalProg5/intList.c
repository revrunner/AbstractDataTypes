/* Nirav Agrawal
* nkagrawa
*/



#include "intList.h"
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct Node{
  int item;
  Node* next;
};

Node** newNodeArray(int size){
    return (Node**)calloc(sizeof(Node*), size);
}

Node* addEdge(Node* list, int newValue){

    Node *temp = (Node *)calloc(sizeof(Node), 1);
    temp->item = newValue;

    if(list == NULL){
        temp->next = NULL;
    }
    else{
        temp->next = list;
    }
    return temp;
}

int isEmpty(Node* list){
    if(list == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int dequeue(Node* list){
    
    assert(list != NULL);
    
    Node* temp = list;
    list = list->next;
    int x = temp->item;
    free(temp);
    return x;
}

Node* enqueue(Node* list, int value){
    
    Node* temp = (Node*)calloc(sizeof(Node), 1);
    temp->item = value;
    temp->next = NULL;
    
    if(list == NULL){
        list = temp;
    }
    else{
        Node* tmp = list;
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = temp;
    }
    return list;
}

void printGraph(Node** graph, int numVerts){
    int i;
    for(i = 0; i < numVerts; i++){
        printf("%d ", i);
        Node* temp;
        for (temp = graph[i]; temp != NULL; temp = temp->next) {
            printf("%d ", temp->item);
        }
        printf("\n");
    }
}

void freeMemory(){
    free(marked);
    free(distTo);
    free(edgeTo);
}

void bfs(Node** graph, int s, int numVerts){
    
    Node* queue = NULL;
    
    marked = (int*)calloc(sizeof(int), numVerts);
    distTo = (int*)calloc(sizeof(int), numVerts);
    edgeTo = (int*)calloc(sizeof(int), numVerts);
    
    int i;
    for(i = 0; i < numVerts; i++){
        distTo[i] = INT_MAX;
    }
    
    marked[s] = 1;
    distTo[s] = 0;
    
    queue = enqueue(queue, s);
    while( !isEmpty(queue) ){
        
        int v = queue->item;
        queue = queue->next;
        
        Node* edges = graph[v];
        while(edges != NULL){
            int x = edges->item;
            if(marked[x] == 0){
                edgeTo[x] = v;
                distTo[x] = distTo[v]+1;
                marked[x] = 1;
                queue = enqueue(queue, x);
            }
            edges = edges->next;
        }
    }
}

int hasPathTo(int v){
    return marked[v];
}

int distToo(int v){
    return distTo[v];
}

int* pathTo(int v){
    
    int index = distToo(v);
    
    if(hasPathTo(v) == 0) return NULL;
    
    int* path = (int*)calloc(sizeof(int), index);
    index--;
    int x;
    for(x = v; distTo[x] != 0; x = edgeTo[x])
        path[index--] = x;
    path[index] = x;
    return path;
}
