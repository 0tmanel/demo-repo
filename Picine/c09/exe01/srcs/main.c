#include "ft.h"
int main()
{
   ft_putchar('O'); 
   ft_putchar('\n');
   ft_putstr("hello\n");
   char *s1 = "hi";
    char *s2 = "ho";

  int len = ft_strcmp(s1, s2);
  printf("%d\n",len);
char *s = "hello";
   printf("%d\n",ft_strlen(s));
   int a = 5;
   int b = 9;
   ft_swap(&a, &b);
    printf("%d %d\n", a, b);

   
}