/*
strcspn is a standard C library function that calculates the length of the initial segment of a string that does not contain any characters from a given set.

Prototype:
size_t strcspn(const char *s, const char *reject);
Parameters:
s → The input string to be scanned.
reject → A set of characters to check against.
Return Value:
Returns the number of characters in s before encountering any character from reject.
If no characters from reject are found, it returns the length of s.
Example Usage:

strcspn("hello, world", "ow");  // Returns 4 (stops at 'o')
strcspn("abcdef", "xyz");       // Returns 6 (no match, full length)*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int research( char *reject, char c)
{
    int i = 0;
    while (reject[i] != '\0')
    {
        if(reject[i] == c)
        {
            return 1;
        }
        i++;
    }
    return 0;
}
size_t ft_strcspn(const char *s, const char *reject)
{
    int i = 0;
    size_t index = 0;
    while (s[i] != '\0')
    {
        int j = 0;
        if (search(reject, s[i]))
            return index;
        else
        {
            index++;
            i++;
        }
    }
    return index;
}

int main()
{
    char *s = "hello world";
    const char *reject = "wo";
    size_t len = ft_strcspn(s, reject);
    printf("%zu\n", len);
}
/*

char			*ft_strchr(const char *str, int firstc)
{
	while (*str)
	{
		if (*str == (char)firstc)
			return ((char *)str);
		str++;
	}
	if (*str == (char)firstc)
		return ((char *)str);
	return (NULL);
}

size_t			ft_strcspn(const char *s, const char *reject)
{
	size_t ret;

	ret = 0;
	while (*s)
	{
		if (ft_strchr(reject, *s))
			return (ret);
		else
		{
			s++;
			ret++;
		}
	}
	return (ret);
}*/
/*
size_t ft_strcspn(const char *s, const char *reject)
{
    int i = 0;
    while (reject[i] != '\0')
    {
        int j = 0;
        while (s[j] != '\0')
        {
            if (s[j] == reject[i])
            {
                return j;
            }
            j++;
        }
        i++;
    }
    return strlen(s);
}*/
