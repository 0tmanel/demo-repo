#include <stdio.h>
//A function pointer is a pointer that holds the address of a function. The ability of pointers to point to functions turns out to be an important and useful feature of C. This provides us with another way of executing functions in an order that may not be known at compile time and without using conditional statements.
//One concern regarding the use of function pointers is a potentially slower running program. 

//The syntax for declaring a pointer to a function can be confusing when you first see it.

// Let’s start with a simple declaration. Below, we declare a pointer to a function that is passed void and returns void:
void (*foo)();

//This declaration looks a lot like a function prototype. If we removed the first set of parentheses, it would appear to be a function prototype for the function foo, which is passed void and returns a pointer to void. However, the parentheses make it a function pointer with a name of foo.

 //Other examples of function pointer declarations are illustrated below:
int (*f1)(double); // Passed a double and // returns an int
void (*f2)(char*); // Passed a pointer to char and // returns void
double* (*f3)(int, int); // Passed two integers and returns a pointer to adouble

//!!Do not confuse functions that return a pointer with function pointers

//The following declares f4 as a function that returns a pointer to an integer, while f5 is a function pointer that returns an integer. The variable f6 is a function pointer that returns a pointer to an integer:
int *f4();
 int (*f5)(); 
 int* (*f6)();
//The whitespace within these expressions can be rearranged so that it reads as follows:
int* f4(); 
int (*f5)();
//It is clear that f4 is a function that returns a pointer to an integer. However, using parentheses with f5 clearly bind the “pointer” asterisk to the function name, making it a function pointer.

//#######Initializing Function Pointers

//Initializing a function pointer variable can be done in two ways.
//1. With the “address of” operator.
//2. Via an implicit assignment.
//The following source code illustrates two methods of initializing function pointers, which are mentioned above. Source code. Fptr1.c
#include <stdlib.h>
#include <stdio.h>
void mesg(int num )
{
      printf("Mesg no. %d\n", num);
}

int* add(int x, int y)
{
      int *z = (int*)malloc(sizeof(int));
      *z = 10;
      return z;
}
int main(int argc, char* argv[])
{
      int *t;
      void (*fpmsg)(int);
      int* (*addfptr)(int, int); //function pointer variable to point to the function "add"
      addfptr = &add;            //assignment using "address of" operator
      fpmsg = mesg;              //assignment using implicit method
      return 0;
}

//#######Passing Function Pointers
//Passing a function pointer is easy enough to do. Simply use a function pointer declara‐ tion as a parameter of a function. We will demonstrate passing a function pointer using add, sub, and compute functions as declared below:
int add(int num1, int num2) { return num1 + num2;
}
int subtract(int num1, int num2) { return num1 - num2;
}
typedef int (*fptrOperation)(int,int);

int compute(fptrOperation operation, int num1, int num2) {
return operation(num1, num2);
 }
//The following sequence demonstrates these functions:
printf("%d\n",compute(add,5,6)); 
printf("%d\n",compute(sub,5,6));
//The output will be an 11 and a –1. The add and sub function’s addresses were passed to the compute function. These addresses were then used to invoke the corresponding operation. This example also shows how code can be made more flexible through the use of function pointers.
