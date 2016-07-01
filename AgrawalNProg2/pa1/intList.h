/* Nirav Agrawal
* nkagrawa
*/



/* intList.h
 * write the methods to the class intList.h
 */

#ifndef C101IntList
#define C101IntList
/* Multiple typedefs for the same type are an error in C. */

typedef struct IntListNode * IntList;

/** intNil denotes the empty IntList */
extern const IntList intNil;

/* Access functions
 * Preconditions: list isn't empty
 */

/** first
 */
int intFirst(IntList oldL);

/** rest
 * Preconditions: list isn't empty
 */
IntList intRest(IntList oldL);

/* Constructors
 * Preconditions: list is empty
 * Postcondition: none
 */

/** cons
 */
IntList intCons(int newE, IntList oldL);

#endif

