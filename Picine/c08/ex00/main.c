#include "ft_f.h"
int main ()
{
    char c = 'i';
    int a = 6;
    int b = 8;
    char str[]= "hello";
    char str2[]= "hello";
     char s1[]= "hello";
    char s2[]= "hello";
 ft_putchar(c);
 ft_swap( &a, &b);
 ft_putstr( str);
 int len = ft_strlen(str2);
 int number = ft_strcmp(s1, s2);
 printf("%d %d\n", a, b);
 printf("%d\n", number);
 printf("%d\n", len);
}