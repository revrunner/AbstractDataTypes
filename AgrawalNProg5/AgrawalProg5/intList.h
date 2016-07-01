// Nirav Agrawal
// nkagrawa

#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#ifndef C101IntList
#define C101IntList

int* marked;
int* edgeTo;
int* distTo;

typedef struct Node Node;

Node** newNodeArray(int size);

Node* addEdge(Node* list, int newValue);

int isEmpty(Node* list);

int dequeue(Node* list);

Node* enqueue(Node* list, int value);

void printGraph(Node** graph, int numVerts);

void freeMemory();

void bfs(Node** graph, int s, int numVerts);

int hasPathTo(int v);

int distToo(int v);

int* pathTo(int v);

#endif

