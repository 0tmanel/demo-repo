 #include <stdio.h>
 #include <unistd.h>
 #include <stdlib.h>
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
    int len = ft_strlen(str);
   char string[len];

    int i = 0;

    while (0 < len)
    {
        string[i] = str[len - 1];
        i++;
        len--;
    }
   string[i] = '\0';
   char *temp = string;
   return temp;
}
int main()
{
    char str[] = "hello";
   char *string = ft_strrev(str);
  printf("%s\n", string);
   
}