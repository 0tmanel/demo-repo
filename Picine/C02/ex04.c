#include <unistd.h>
char *ft_strcapitalize(char *str)
{
  int i = 0;
  int l = 0;

  while (str[i] != '\0')
  {
     
   if(str[i] >= 'a' && str[i] <= 'z' || str[i] >= '0' && str[i] <= '9')
   {
    if(!l)
    {
      if(str[i] >= 'a' && str[i] <= 'z')

      str[i] -=32;
      l = 1;
    } 
   }else 
   {
    l = 0;
   }
    i++;
  }
}
int main()
{
  char str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";

  ft_strcapitalize(str);
  int i = 0;
  while (str[i] != 0)
  {
    write(1, &str[i], 1);
    i++;
  }
}