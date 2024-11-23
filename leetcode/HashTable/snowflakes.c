#include <stdio.h>
/*int identical_right(int snow1[], int snow2[], int start)
{ // bugged!
    int offset;
    for (offset = 0; offset < 6; offset++)
    {
        if (snow1[offset] != snow2[start + offset])
            return 0;
    }
    return 1;
}*/
/*int identical_right(int snow1[], int snow2[], int start)
{
    int offset, snow2_index;
    for (offset = 0; offset < 6; offset++)
    {
        snow2_index = start + offset;
        if (snow2_index >= 6)
            snow2_index = snow2_index - 6;
        if (snow1[offset] != snow2[snow2_index])
            return 0;
    }
    return 1;
}*/
int identical_right(int snow1[], int snow2[], int start)
{
    int offset = 0;
    while (offset < 6)
    {
        if(snow1[offset] != snow2[(start + offset) % 6])
        {
            return 0;
        }
        offset++;
    }
    return 1;
}
int identical_left(int snow1[], int snow2[], int start)
{
    int offset = 0;
    int snow2_index;
    snow2_index = offset - start;
    while (offset < 6)
    {
        if( snow2_index < 0)
        {
            snow2_index = snow2_index + 6;
        }
        if(snow1[offset] != snow2[snow2_index])//we can not use the reminder here 
        {
            return 0;
        }
        offset++;
    }
    return 1;
}
int are_identecal(int snow1[], int snow2[])
{
    int start = 0;
    while (start < 6)
    {
        if(identical_right(snow1, snow2, start))
        {
            return 1;
        }
         if(identical_left(snow1, snow2, start))
        {
            return 1;
        }
        start++;
    }
    return 0;

}
int ft_check(int arr[][6])
{
    int i = 0;
    int l = 0;
    int k = 1;
    int j = 0;
    while (i < 6)
    {
        while (j < 6)
        {
            if (arr[l][i] == arr[k][j])
            {
                j++;
                break
            }
        }
    }
}
int main()
{
    /*In the case of a two-dimensional array, you are passing a pointer to an array of arrays.
     This means you need to explicitly define the size of at least the second dimension when
      passing it to a function. The compiler needs to know how to
      calculate the memory offsets when accessing array elements.*/
    int snowflakes[2][6] = {{1, 2, 3, 4, 5, 6}, {1, 2, 3, 4, 5, 6}};

    ft_check(snowflakes);
}