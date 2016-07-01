//Nirav Agrawal
//nkagrawa

#include "libraryList.h"
#include <assert.h>

BNode* newBNode(){
  return (BNode*)calloc(sizeof(BNode), 1);
}

LNode* newLNode(){
    return (LNode*)calloc(sizeof(LNode), 1);
}

LibraryFCL* newLFCL(){
  return (LibraryFCL*)calloc(sizeof(LibraryFCL), 1);
}

BookFCL* newBFCL(){
    return (BookFCL*)calloc(sizeof(BookFCL), 1);
}

BookNode* newBookNode(){
  return (BookNode*)calloc(sizeof(BookNode), 1);
}

BNode* addNewBook(char* title, int libraryID){
  assert (title != NULL);
  assert (libraryID != NULL); 

  BNode* bNode = newBNode();
    
  BookNode* bookNode = newBookNode();
  bookNode->title = (char*)calloc(strlen(title), 1);
  strcpy(bookNode->title, title);
    
  bookNode->libraryList = newLFCL();
  LNode* lNode = newLNode();

  bookNode->libraryList->first = lNode;
  bookNode->libraryList->current = lNode;
  bookNode->libraryList->last = lNode;

  lNode->libraryId = libraryID;

  bNode->book = bookNode;
  return bNode;
}

unsigned long hash(char* str){
  unsigned long hash = 5381;
  int c;
  c = *str;
  while (c){
    hash = ((hash << 5) + hash) + c;
    c = *str++;
  }

  return hash;
}

void listLibraries(LibraryFCL* library){
  if (library) {
    LNode* ptr = library->first;
    while(ptr) {
      printf("%d ", ptr->libraryId);
      ptr = ptr->next;
    }
  }
  printf("\n");
}

void insert(BookFCL** bookFclArray, int arraySize, char* title, int libraryID){
  int index = hash(title) % arraySize;
  BookFCL* bookFcl = bookFclArray[index];

  if(!bookFcl){  //new entry
      bookFcl = newBFCL();
      bookFclArray[index] = bookFcl;
      
      BNode* book = addNewBook(title, libraryID);
      
      bookFcl->first = book;
      bookFcl->current = book;
      bookFcl->last = book;
  }
  else{  //collision
    LibraryFCL* lFcl = find(bookFclArray, arraySize, title);
      
    if(lFcl){ //Title found, insert new libraryID
        LNode* lNode = newLNode();
        lNode->libraryId = libraryID;

        lNode->next = lFcl->first;
        lFcl->first = lNode;
    }
    else{
      BNode* newBook = addNewBook(title, libraryID);
      newBook->next = bookFcl->first;
      bookFcl->first = newBook;
    }
  }
}

LibraryFCL* find(BookFCL** bookFclArray, int arraySize, char* title){
  int index = hash(title) % arraySize;
  
  BookFCL* bFcl = bookFclArray[index];

    if (bFcl) {
      BNode* ptr = bFcl->first;
      while(ptr) {
          if(!strcmp(title, ptr->book->title))
              return ptr->book->libraryList;
          ptr = ptr->next;
      }
    }
    return NULL;
}
