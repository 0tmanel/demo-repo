 #include <ctype.h>
 #include <stdio.h>
 int test(char *str)
 {
    int i = 0;
    while(str[i] != '\0')
    {
        if(!isalpha(str[i]))
        {
            return 1;
        }
        i++;
    }
    return 0;
 }
 int ft_any(char **tab, int(*f)(char*))
 {
    int i = 0;
    while (tab[i][0] != 0)//??why  this tab[i] != 0 does not work and this work tab[i][0] != 0
    {
        if(f(tab[i]) != 0)
        {
            return 1;
        }
        i++;
    }
   return 0;
 }
 int main ()
 {
    char *tab[] = {"hello", "how", "are", "you"};
    int number = ft_any(tab, &test);
    printf("%d\n", number);
 }