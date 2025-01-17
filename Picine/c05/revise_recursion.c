//it’s possible for a function to call itself. This is termed recursion. You’re unlikely to come across a need for recursion very often

//Recursion is a sometimes tricky, sometimes convenient tool. It’s tricky to get recursion to end because a function that calls itself tends to do so indefinitely unless the programming includes a conditional test to terminate recursion.

//recursion often can be used where loops can be used. Sometimes the loop solution is more obvious; sometimes the recursive solution is more obvious. Recursive solutions tend to be more elegant and less efficient than loop solutions.

//To see what’s involved, let’s look at an example. The function main() below calls the up_and_down() function. We’ll term this the “first level of recursion.” Then up_and_down() calls itself; we’ll call that the “second level of recursion.” The second level calls the third
//level, and so on. This example is set up to go four levels. To provide an inside look at what is happening, the program not only displays the value of the variable n, it also displays &n, which is the memory address at which the variable n is stored

#include <stdio.h>
void up_and_down(int);
int main(void) {
up_and_down(1);
return 0; 
}
void up_and_down(int n) {
printf("Level %d: n location %p\n", n, &n); // 1 
if (n < 4)
up_and_down(n+1);

printf("LEVEL %d: n location %p\n", n, &n); // 2
}

// Let’s trace through the program to see how recursion works. First, main() calls up_and_down() with an argument of 1. As a result, the formal parameter n in up_and_down() has the value 1, so print statement #1 prints Level 1. Then, because n is less than 4, up_and_down() (Level
//1) calls up_and_down() (Level 2) with an actual argument of n + 1, or 2. This causes n in the
  
//Level 2 call to be assigned the value 2, so print statement #1 prints Level 2. Similarly, the next two calls lead to printing Level 3 and Level 4.
//When Level 4 is reached, n is 4, so the if test fails. The up_and_down() function is not called again. Instead, the Level 4 call proceeds to print statement #2, which prints LEVEL 4, because n is 4. Then it reaches the return statement. At this point, the Level 4 call ends, and control passes back to the function that called it (the Level 3 call). The last statement executed in the Level 3 call was the call to Level 4 in the if statement. Therefore, Level 3 resumes with the following statement, which is print statement #2. This causes LEVEL 3 to be printed. Then Level 3 ends, passing control to Level 2, which prints LEVEL 2, and so on.

//Note that each level of recursion uses its own private n variable. You can tell this is so by looking at the address values. (Of course, different systems, in general, will report different addresses, possibly in a different format. The critical point is that the address on the Level 1 line is the same as the address on the LEVEL 1 line, and so on.)

//each function call is balanced with a return. When program flow reaches the return at the end of the last recursion level, control passes to the previous recursion level. The program does not jump all the way back to the original call in main(). Instead, the program must move back through each recursion level, returning from one level of up_and_down() to the level of up_and_down() that called it.


//look at the C course , PART OF recursion  , it said that in order for the return the control, it will look at the stack and see if there anything 