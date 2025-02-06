#include <stdio.h>
 int ft_strlen(char *str)
 {
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
 }

char    *ft_strrev(char *str)
{
    int i = 0;
    char t;
    int len = ft_strlen(str) - 1;
    
   while (len > i)
   {
    t = str[i];
    str[i] = str[len];
    str[len] = t;
    i++;
    len--;
   }
    return str;
}
int main ()
{
    //char *str = "hello";

/*if you declare the string as this above a bus error will happen because of how you're working with the string. Specifically, you are trying to modify a string literal, which is stored in a read-only section of memory.

In this line:

char* str = "hello";
The string "hello" is a string literal and typically stored in a read-only section of memory, meaning it can't be modified. So, when you try to modify str in your ft_strrev() function, you're trying to change read-only memory, which causes undefined behavior — often resulting in a bus error.
, 
to avoid this , you have to declare it as an array notation  bellow
*/
    char str[] = "hello";

    char *string = ft_strrev(str);
    printf("%s\n", string);

}
/*

char* ft_strrev(char *str)
{
    int i = 0;
    int len = ft_strlen(str) - 1;
    char string[len];
   while (0 <= len)
   {
     string[i] = str[len];
     len--;
     i++;
   }
   char *temp = string;
    return temp;
}*/