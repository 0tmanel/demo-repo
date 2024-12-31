//The core purpose of putnbr is to display an integer by
// printing it to the output. as long as we are allowed only to 
//use write, we can not print the number as it is, we must convert
//it to string , that's what our function is used for

// "**" is the exponentiation operator, 
//which means it raises a number to the power of another number.
//so to know what is the max of in integer 32 bit run in your shell
//echo $(2**31 - 1) for max positive and echo $(2**31) negative
#include <unistd.h>
#include <limits.h>
  void ft_putchar(char c)
  {
    write(1, &c, 1);
  }
void ft_putnbr(int nb)
  {
    long n = (long) nb;
    if(n < 0)
    {
        ft_putchar('-');
        n = -n;
    }
    if(n < 9)
    {
        //To get the ones place (the last digit) of a number, 
        //you can use the modulo operator (%).
         //This operator gives the remainder of a division.
        ft_putchar(n % 10 + '0');
    }
    
    if(n > 9)
    {
        ft_putnbr(n / 10);
        ft_putchar(n % 10 + '0');
        //The number 42 is greater than 9, so it enters this loop:

//ft_putnbr(42 / 10);  ==> ft_putnbr(4)
//Inside ft_putnbr(4):
//4 < 9, so it will enter the first loop and print '4'.
//Now, it returns to the previous call (which is ft_putnbr(42)).
//After returning from ft_putnbr(4), the function 
//proceeds to print the last digit of 42:
//ft_putchar(42 % 10 + '0');  // Prints '2'
    }


  }
  int main ()
  {
    ft_putnbr(INT_MIN);
    write(1, "\n", 1);
  }
  //be caereful when you pass the -2147483648 as int and you 
  //do not convert it to 'long' the program will not work ,

  //int and long are both integer data types that store 
  //whole numbers, but they have different size limitations 
  //depending on the platform (whether it's 32-bit or 64-bit).
//int:
//Typically, int is a 32-bit integer (4 bytes).
//Range for signed 32-bit int: from -2,147,483,648 to 
//2,147,483,647 (i.e., -2^31 to 2^31 - 1).
//Range for unsigned 32-bit int: from 0 to
// 4,294,967,295 (i.e., 0 to 2^32 - 1).
//long:

//On 32-bit systems, long is often 32 bits (same as int).
//On 64-bit systems, long is typically 64 bits (8 bytes).
//Range for signed 64-bit long: from -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 (i.e., -2^63 to 2^63 - 1).
//Range for unsigned 64-bit long: from 0 to 18,446,744,073,709,551,615 (i.e., 0 to 2^64 - 1).