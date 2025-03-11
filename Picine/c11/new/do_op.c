#include <unistd.h>
#include <stdio.h>
int ft_atoi(char *str)
  {
    int i = 0;
    int result = 0;
    int sign = 0;
        while((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        {
            i++;
        }
        while(str[i] == '-' || str[i] == '+')
        {
            if(str[i]== '-')
            {
                sign++;
            }
            i++;
        }
        while(str[i] >= '0' && str[i] <= '9')
        {
            result = result * 10;
            result += str[i] - '0';
            i++;
        }
    if (!sign % 2 == 0)
    {
        return -result;
    }
   return result;
  }
int add(int num1, int num2)
{
    return num1 + num2;
}
int subtract(int num1, int num2)
{
    return num1 - num2;
}
int divide(int num1, int num2)
{
    return num1 / num2;
}
int multibly(int num1, int num2)
{
    return num1 * num2;
}
int modulo(int num1, int num2)
{
    return num1 % num2;
}
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
        ft_putchar(n % 10 + '0');
    }
    if(n > 9)
    {
        ft_putnbr(n / 10);
        ft_putchar(n % 10 + '0');
    }
  }
void help(char* value1, char * oper, char *value2, int (*f[5])(int, int))
{
        int num1 = ft_atoi(value1);
        //printf("%d\n", num1);
        int num2 = ft_atoi(value2);
       // printf("%d\n", num1);
        if(oper[0] == '+')
           ft_putnbr(f[0](num1, num2));
        else if(oper[0] == '-')
            ft_putnbr(f[1](num1, num2));
        else if(oper[0] == '/')
        {
            if(num2 == 0)
            {
                write(1, "Stop : division by zero", 23);
                return;
            }
            ft_putnbr(f[2](num1, num2));
        }
       else if(oper[0] == '*')
            ft_putnbr(f[3](num1, num2));
       else if(oper[0] == '%')
        {
            if(num2 == 0)
            {
                write(1, "Stop : modulo by zero", 21);
                return;
            }
            ft_putnbr(f[4](num1, num2));
        }
        else
            write(1, "0", 1);
}
int main (int argc, char** argv)
{
    int (*f[5])(int, int) = {add, subtract, divide, multibly, modulo};
    if(argc == 4)
    {
        help(argv[1], argv[2], argv[3],f);
        write(1, "\n", 1);
    }
}
/*
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
        return num1 * num2;
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
*/