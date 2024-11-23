#include <stdio.h>
char *ft_strstr(char *str, char *to_find)
{
    
  while (str[i] != 0)
       {
             while  (str[i + j] == to_find[j] && to_find[j ] != 0)
             {
                j++;
                
             }
             if(to_find[j]== 0)
             {
                return &str[i];
             }
             i++;
        }

}
int main ()
{
    char str[] = "hello world";
    char to_find[] = "wo";
    char * find = ft_strstr(str, to_find);
    printf("%c", *find);
}