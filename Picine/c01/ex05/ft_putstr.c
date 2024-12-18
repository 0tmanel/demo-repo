#include <unistd.h>
  void ft_putstr(char *str)
  {
    /*int i = 0;
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }*/
   while (*str)
   {
    write(1, str, 1);
 //In C, a string is simply a pointer to the first character of the string.
 //When you do something like write(1, str, 1), str points to the first
//character in the string, and write is called to write 1 byte from that address. 
    str++;
   }


  }
  int main ()
  {
    char str[] = "hello world";
    ft_putstr(str);
    write(1, "\n", 1);
  }