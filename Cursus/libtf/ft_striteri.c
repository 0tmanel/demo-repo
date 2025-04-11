#include <stdio.h>
void ft_toupper(unsigned int i, char *str)
{
     if (i % 2 == 0 && *str >= 'a' && *str <= 'z') 
     {
      *str -= 32;
     }
   
}
void ft_striteri(char *s, void (*f)(unsigned int, char *)){
    int i = 0;
    while(s[i])
    {
        f(i, &s[i]);
        i++;
    }

}
int main ()
{
    char str[] = "hello world";
    ft_striteri(str, &ft_toupper);
    printf("%s\n", str);
}