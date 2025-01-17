#include <stdio.h>
#include <string.h>
 int ft_strcmp(char *s1, char *s2)
 {
while (*s1 && (*s1 == *s2))
{
s1++;
s2++;
}
return *s1 - *s2;
/*
This condition ensures that as long as both strings have 
characters that are equal, the loop continues.
It also ensures that if str1 reaches the null terminator ('\0'), 
the loop will stop because *str1 will be 0, which causes the condition 
to fail (even if str2 hasn't reached the null terminator yet).

    int i = 0;
    while (s1[i] == s2[i] && s1[i] != '\0' )
    {
        i++;
    }
    return s1[i] - s2[i];

*/
 }
int main ()
{
    char s1[] = "hello";
    char s2[] = "hello";
   int res =  ft_strcmp(s1, s2);
  // int res =  strcmp(s1, s2);
   printf("%d\n", res);
}
//Return Values of strcmp:

//If strcmp(str1, str2) returns 0:

//The strings are equal.
//The function compares the strings character by character, and if all characters match (including the null-terminator), it returns 0.

//If strcmp(str1, str2) returns a negative value (less than 0):

//The first string (str1) is lexicographically less than the second string (str2).
//This happens if, at the first differing character, the character in str1 has a lower ASCII value than the corresponding character in str2.
//For example, "apple" is less than "banana", so strcmp("apple", "banana") would return a negative value.

//If strcmp(str1, str2) returns a positive value (greater than 0):

//The first string (str1) is lexicographically greater than the second string (str2).
//This happens if, at the first differing character, the character in str1 has a higher ASCII value than the corresponding character in str2.
//For example, "banana" is greater than "apple", so strcmp("banana", "apple") would return a positive value.