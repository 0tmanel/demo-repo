 #include <stdio.h>
 #include <string.h>
 int add(int num1, int num2);
int sub(int num1, int num2);
int mult(int num1, int num2);
int div(int num1, int num2);
int mod(int num1, int num2);

 int add(int num1, int num2)
    {
        return num1 + num2;
    }
 int sub(int num1, int num2)
    {
        return num1 - num2;
    }
 int mult(int num1, int num2 )
    {
        return num2 * num2;
    }
 int div(int num1, int num2)
    {
        if(num1 == 0 || num2 == 0)
        {
            write(1, "stop : modulo by zero", 1);
            return 0;
        }else
        return num1 / num2;
    }
int mod(int num1, int num2 )
    {
        if(num1 == 0 || num2 == 0)
        {
            write(1, "stop : devision by zero", 1);
            return 0;
        }else 
        return num1 % num2;
    } 
int ft_argv1(char* num1)
{
    int i = 0;
    int result = 0;
    while (num1[i] != '\0')
    {
    result *= 10;
    result += num1[i] - 48;
    i++;
    }
    return result;
}
int ft_argv3(char* num3)
{
     int result = 0;
     int i = 0;
    while (num3[i] != '\0')
    {
    result *= 10;
    result += num3[i] - 48;
    i++;
    }
    return result;
}
int main (int arc, char* argv[])
{
    if(arc != 4)
    {
        return 0;
    }
   
    int (*operatio[5])(int, int) = {add, sub, mult, div, mod};
    char *operation[] = {"+", "-", "*", "/", "%"};

    int num1 = ft_argv1(argv[1]);
    int num2 = ft_argv3(argv[3]);
    char* operator = argv[2];
    int i = 0;
    while (i < 5)
    {
        if(strcmp(operator, operation[i])== 0)
        {
       int result =  operatio[i](num1, num2);
        printf("%d\n", result);
        }
        i++;
    }

    
}