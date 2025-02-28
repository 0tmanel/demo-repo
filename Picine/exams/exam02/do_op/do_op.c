#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main (int argc, char**argv)
{
    int result = 0;
    
    if(argc == 4)
    {
       int num1 =  atoi(argv[1]);
       int num2 = atoi (argv[3]);
       if(argv[2][0] == '/')
       {
        result = num1 / num2;
        printf("%d", result);
       }
       else if(argv[2][0] == '+')
       {
        result = num1 + num2;
        printf("%d", result);
       }
       else if(argv[2][0] == '-')
       {
        result = num1 - num2;
        printf("%d", result);
       }
       else if(argv[2][0] == '*')
       {
        result = num1 * num2;
        printf("%d", result);
       }
        else if(argv[2][0] == '%')
       {
        result = num1 % num2;
        printf("%d", result);
       }
    }
    write(1, "\n", 1);
    
    return 0;
}