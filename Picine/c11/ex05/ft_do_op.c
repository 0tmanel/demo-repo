#include <unistd.h>
#include "ft_atoi.c"
#include "ft_putnbr.c"

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
void help(int num1, char *oper, int num2, int (*f[5])(int, int))
{
    char op[] = "+-/*%";
    int i = 0;
    while (i < 5)
    {
        if (oper[0] == op[i])
        {
            if (oper[0] == '/' && num2 == 0)
            {
                write(1, "Stop : division by zero", 23);
                return;
            }
            else if (oper[0] == '%' && num2 == 0)
            {
                write(1, "Stop : modulo by zero", 21);
                return;
            }
            ft_putnbr(f[i](num1, num2));
            return;
        }  
        i++;
    }
     write(1, "0", 1);
}
int main(int argc, char **argv)
{
    int (*f[5])(int, int) = {add, subtract, divide, multibly, modulo};
    if (argc == 4)
    {
    int num1 = ft_atoi(argv[1]);
    int num2 = ft_atoi(argv[3]);
        help(num1, argv[2], num2, f);
        write(1, "\n", 1);
    }
}