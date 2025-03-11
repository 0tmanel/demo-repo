#include <stdio.h>
int		max(int* tab, unsigned int len)
{
    int biggest = 0;
    int i = 0;
    while (i < len)
    {
        if(tab[i] > biggest)
        {
            biggest = tab[i];
        }
        i++;
    }
    return biggest;
}
int main ()
{
    int tab[] = {4, 75, 95, 74, 69, 23, 43};
    unsigned int len = 7;
    int biggest = max(tab, len);
    printf("%d\n", biggest);
}