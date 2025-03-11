 #include <stdio.h>
 int count(char*str)
 {
    return (*str != '\0');
 }
 int ft_count_if(char **tab, int length, int(*f)(char*))
 {
    int i = 0;
    int count = 0;
    while (tab[i] != NULL)
    {
        if(f(tab[i]) != 0)
        {
            count++;// Count only when f(tab[i]) returns non-zero
        }
        
        i++;
    }
    return count;

 }
 int main ()
 {
    char *tab[] = {"hello", "how", "are", "you", NULL};
    int length = 4;
   int result =  ft_count_if(tab, length, &count);
   printf("%d\n", result);

 }