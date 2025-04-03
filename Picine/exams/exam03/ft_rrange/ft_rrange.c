#include <stdio.h>
#include <stdlib.h>

int *ft_rrange(int start, int end)
{
    int len = 0;
    if(end >= start)
    {
        len = end - start + 1;
    }
    else{
        len = start - end + 1;
    }
    int *array = (int *)malloc(len * sizeof(int));
    if (!array)
    {
        return NULL;
    }
    while(len--)
    {
        if(end >= start)
        {
            array[len] = start;
            start++;
        }
        else{
            array[len] = start;
            start--;
        }
    }
    return array;
}
int main()
{
    int start = 0;
    int end = -3;
    int *array = ft_rrange(start, end);
    int i = 0;
     int len = (end >= start) ? end - start + 1 : start - end + 1;
    while (i < len)
    {
        printf("%d\n", array[i]);
        i++;
    }
}