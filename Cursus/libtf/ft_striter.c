#include <stdio.h>
void ft_toupper(char *str)
{
    if(*str >= 'a' && *str <= 'z')
    {
        *str -= 32;
    }
}
void ft_striter(char *s, void (*f)(char *)){
    int i = 0;
    while(*s)
    {
        f(s);
        s++;
    }

}
int main ()
{
    char str[] = "hello world";
    ft_striter(str, &ft_toupper);
    printf("%s\n", str);
}