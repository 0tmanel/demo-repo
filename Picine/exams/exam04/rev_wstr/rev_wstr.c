#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*
void swapStrings(char **a, char **b)
{
    char *temp = *a;
    *a = *b;
    *b = temp;
}
int ft_seperator(char c, char *charset)
{
    int i = 0;
    while (charset[i] != '\0')
    {
        if (c == charset[i])
        {
            return 1;
        }
        i++;
    }
    return 0;
}
int ft_count(char *str, char *charset)
{
    int i = 0;
    int count = 0;
    while (str[i] != '\0')
    {
        while (str[i] != '\0' && ft_seperator(str[i], charset))
            i++;
        if (str[i] != '\0')
            count++;
        while (str[i] != '\0' && !ft_seperator(str[i], charset))
            i++;
    }
    return count;
}
int ft_len(char *str, char *charset)
{
    int i = 0;
    while (str[i] != '\0' && !ft_seperator(str[i], charset))
    {
        i++;
    }
    return i;
}
char *ft_word(char *str, char *charset)
{
    int str_len = ft_len(str, charset);
    char *string = (char *)malloc((str_len + 1) * sizeof(char));
    int i = 0;
    while (i < str_len)
    {
        string[i] = str[i];
        i++;
    }
    string[i] = '\0';

    return string;
}
char **ft_split(char *str, char *charset)
{
    char **strs = (char **)malloc((ft_count(str, charset) + 1) * sizeof(char *));
    int l = 0;
    // int i = 0;
    while (*str)
    {
        while (*str != '\0' && ft_seperator(*str, charset))
            str++;
        if (*str)
        {
            strs[l] = ft_word(str, charset);
            l++;
        }
        while (*str != '\0' && !ft_seperator(*str, charset))
            str++;
    }
    strs[l] = 0;

    return strs;
}
int ft_strlen(char **str, char sep, int size)
{
    int i = 0;
    int index = 0;

    while (i < size)
    {
        int j = 0;
        while (str[i][j] != '\0')
        {
            index++;
            j++;
        }
        index += 1;
        i++;
    }
    return index;
}
char *ft_strjoin(int size, char **strs, char sep)
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

            string[l++] = sep;
        }
        i++;
    }
    string[l] = '\0';
    return string;
}
int main(int argc, char **av)
{
    if (argc == 2)
    {

        char *sep = " \t";
        char **string = ft_split(av[1], sep);
        // int length = sizeof(string) / sizeof(string[0]);
        // this method only works if string is a true array (like char *string[]) declared in the same scope.

        // ⚠️ If string is just a pointer (char **string passed to a function), sizeof(string) gives you the size of the pointer itself (usually 4 or 8 bytes), not the array, so it won't work correctly.
        int length = 0;
        while (string[length] != NULL)
        {
            length++;
        }
        char **strs = malloc((length + 1) * sizeof(char *));
        int i = 0;
        int size = length - 1;
        while (0 <= size)
        {
            strs[i++] = string[size--];
        }
        strs[i] = 0;
        char *str = ft_strjoin(length, strs, ' ');
        i = 0;
        while (str[i] != '\0')
        {
            write(1, &str[i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}
*/
int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
    {
        i++;
    }
    return i;
}
void rev_wstr(char *str, int size)
{
    int index = 0;
    int start = size - 1;
    while (size)
    {
        while (start && str[start] != ' ')
        {
            start--;
        }
        if (str[start] == ' ')
        {
            index = start + 1;
        }
        else
            index = start;
        while (index < size)
        {
            write(1, &str[index++], 1);
        }
        if (start != 0 && start-- != 0)
        {
            write(1, " ", 1);
            size = start + 1;
        }
        else
        {
            break;
        }
    }
}
int main(int argc, char **av)
{
    if (argc == 2)
    {
        int len = ft_strlen(av[1]);
        rev_wstr(av[1], len);
    }
    write(1, "\n", 1);
}