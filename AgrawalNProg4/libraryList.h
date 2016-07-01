//Nirav Agrawal
//nkagrawa

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct LNode {
    struct LNode* previous;
    struct LNode* next;
    int libraryId;
} LNode;

typedef struct LibaryFCL {
    LNode* first;
    LNode* current;
    LNode* last;
} LibraryFCL;

typedef struct BookNode {
  char* title;
  LibraryFCL* libraryList;
} BookNode;

typedef struct BNode {
    struct BNode* previous;
    struct BNode* next;
    BookNode* book;
} BNode;

typedef struct BookFCL {
    BNode* first;
    BNode* current;
    BNode* last;
} BookFCL;

struct BNode* newBNode(); //allocates memory for a new BNode and initializes it all to 
                          //0. No pre or post conditions.

struct LNode* newLNode(); //allocates memory for a new LNode and initializes it all to
                          //0. No pre or post conditions.

struct LibaryFCL* newLFCL(); //allocates memory for a new LibraryFCL and intialize all
                             //of its values to 0. No pre or post conditions.

struct BookFCL* newBFCL(); //allocates memory for a new BookFCL and initializes all
                           //of its values to 0. No pre or post conditions.

struct BookNode* newBookNode(); //allocates memory for a new BookNode and initializes
                                //all of its values to 0. No pre or post conditions.

BNode* addNewBook(char* title, int libraryID); //creates and adds another BNode under 
                                               //the BookFCL. pre- title and libraryID 
                                               //cannot be equal to null. 

void listLibraries(LibraryFCL* library); //prints out the LNodes under the LibraryFCL
                                         //given to the program. pre- library cannot
                                         //be null.

void insert(BookFCL** bookFclArray, int arraySize, char* title, int libraryID);
  //takes in data, the title and libraryID, and uses the arraySize variable to create
  //bookNodes for each index in the array. Also adds libraryIDs for books with the
  //same title in the same index. pre- title and libraryID cannot be equal to null.

LibraryFCL* find(BookFCL** bookFclArray, int arraySize, char* title);
  //takes in data and a bookFCL array and searches all of the BookNodes within it
  //for books withe the same title as the title given to the function. returns the
  //LibraryFCL for the book. pre- title cannot be null and bookFclArray cannot be null
  //and arraySize cannot be null.

unsigned long hash(char* str); //uses a formula to determine the index that the data
			       //will be hashed into. pre- str cannot be null.
