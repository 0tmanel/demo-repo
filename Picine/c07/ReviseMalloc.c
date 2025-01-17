//Dynamic memory allocation uses a pointer variable to request memory from the O/S while the program is running. The basic function call for dynamic mem- ory allocation is malloc() it is found in t'library stdlib.h]

#include <stdlib.h>  /* header file for malloc() */
int main(){

             double  *a;          /* pointer variable */
             a = (double *) malloc(40);
            

//The typecast identifies the type of pointer arithmetic expected for the address returned from malloc(). The malloc() function call is the request to the O/S for memory. It takes one parameter, which is the number of bytes needed. In this example, we request 40 bytes, which is 5 doubles (8 bytes per double).
//One of the primary jobs of the O/S is to manage memory. A malloc() call asks the O/S for a chunk of memory of the given size. The chunk of memory is obtained from an area of memory called the heap.

//Dynamically allocated memory does not have an existing label, so we use [DM] to temporarily provide it a name. In order to give it a name that our program can use, we must use either pointer or array syntax based upon the variable a. Every cell of memory in the chunk of bytes has both a pointer-based label and an array-based label and can be accessed using either syntax. 

//Every time a function ends, its statically declared memory is released from the stack and returned to the O/S. Dynamic memory allocation is different. Because the allocation can be made at any point in a program, the program must also be responsible for releasing the memory and returning it to the O/S. This is done by calling the free() function:\\
free(a);

//Failure to call the free() function appropriately may result in a program losing track of the memory it uses. Sometimes this is referred to as a memory leak. For example, consider the following code:
             double *b;
             b=(double *)malloc(70);
             b=(double *)malloc(300);  /* memory leak */
             
    //The program requests 70 bytes from the O/S, and then 300 bytes, each time storing the address of the bytes in a. But the second request overwrites the address of the first request. What happens to those 70 bytes? They are still reserved for use by the program, but the program has lost any record of the address where they reside! This is a common programming mistake and can lead to a program crashing.

}