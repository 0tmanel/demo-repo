//The atoi function in C stands for ASCII to Integer. 
//It is used to convert a string representing a number into 
//its corresponding integer value. The function takes a string
 //(a sequence of characters) as input and 
 //attempts to interpret it as an integer.
#include <unistd.h>
#include <stdio.h>

//calculate the number of - in a loop
//If the number of - signs in the string passed to the atoi 
//function is odd, the resulting number will be negative.
 //If the number of - signs is even, the result will be positive.
int ft_atoi(char *str)
  {
    int i = 0;
    long result = 0;
    int sign = 1;
        while((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        {
            i++;
        }
        while(str[i] == '-' || str[i] == '+')
        {
            if(str[i]== '-')
            {
                sign = -1;
            }
            i++;
        }
        while(str[i] >= '0' && str[i] <= '9')
        {
            result = result * 10;
            result += str[i] - '0';
            i++;
        }
//Even Numbers ====== positive number: A number is even if it is divisible by 2 without 
//leaving a remainder. This means that when
// divided by 2, the remainder is 0.

//Odd Numbers===== negative: A number is odd if it is not divisible by 2 without
// leaving a remainder. When divided by 2, the remainder is 1.
 if(!sign && result > 2147483648)
        return 2147483648 * -1;
        else if(sign && result > 2147483647)
        return 2147483647 * sign;
   return result * sign;
  }
  int main ()
  {
    char str[] = "-91283472332";
  int number = ft_atoi(str);
  printf("%d\n", number);
  }
  /*
  int ft_atoi(char *str)
  {
    int i = 0;
    int result = 0;
    int sign = 1;
    
        while((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        {
            i++;
        }
        while(str[i] == '-' || str[i] == '+')
        {
            if(str[i]== '-')
            {
                sign *= -1;
            }
            i++;
        }
        while(str[i] >= '0' && str[i] <= '9')
        {
            result = result * 10;
            result += str[i] - '0';
            i++;
        }
       
   return result * sign;
  }*/