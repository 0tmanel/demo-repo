/*
The memcmp() function compares two blocks of memory and returns an integer indicating which one is greater.

For this comparison bytes at the same position from both memory blocks are compared one by one starting at position 0 until one of them does not match or the end of the block of memory has been reached. There are three possible scenarios:

If the end of the memory blocks is reached without any mismatches then the function returns zero.
At the first mismatch, if the value of the byte in the first memory block is greater then the function returns a positive number.
At the first mismatch, if the value of the byte in the second memory block is greater then the function returns a negative number.*/
#include <string.h>
#include <stdio.h>

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    const char *str = (const char *)s1;
    const char *str2 = (const char *)s2;
    int i = 0;
    while (i < n && str[i] == str2[i])
    {
        if (str[i] != str2[i])
        {
            return str[i] - str2[i];
        }
        i++;
    }
    return 0;
}
int main()
{
    const void *s1 = "hello world";
    const void *s2 = "hello korld";

    int value = ft_memcmp(s1, s2, strlen(s1));
    //  int value = memcmp(s1, s2, strlen(s1)); try the original funciton to test yours
    printf("%d\n", value);
}