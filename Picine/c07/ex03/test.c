// Write a function that will concatenate all the strings pointed by strs separated by sep.
// • size is the number of strings in strs
// • if size is 0, you must return an empty string that you can free(). • Here’s how it should be prototyped :
#include <stdio.h>
#include <stdlib.h>
int ft_strlen(char **str, char *sep, int size)
{
    int i = 0;
    int index = 0;
    int sepa = 0;
    while (sep[sepa])
    {
        sepa++;
    }
    sepa--;
    while (i < size)
    {
        int j = 0;
        while (str[i][j] != '\0')
        {
            index++;
            j++;
        }
        index += sepa;
        i++;
    }
    return index;
}
char *ft_strjoin(int size, char **strs, char *sep)
{
    int len = ft_strlen(strs, sep, size);
    // printf("%d\n", len);
    char *string = malloc((len + 1) * sizeof(char));
    if (!string)
        return NULL;
    if (size == 0)
        return string;
    int i = 0;
    int l = 0;
    while (i < size)
    {
        int j = 0;
        while (strs[i][j])
        {
            string[l++] = strs[i][j++];
        }
        if (i < size - 1)
        {
            j = 0;
            while (sep[j])
                string[l++] = sep[j++];
        }
        i++;
    }
    string[l] = '\0';
    return string;
}
int main()
{
    char *str[] = {"hello", "my name is", "Otman"};
    int size = 3;
    char sep[] = ", ";
    printf("%s\n", ft_strjoin(size, str, sep));
    // ft_strjoin(size, str, sep);
}