#include <stdio.h>
#include <unistd.h>
int main (int argc, char* argv[])
{
    int i = 0;
    int j = 1;
    int rev = argc - 1;
 
  if(argc >= 1)
  {
    while (j <= rev)
    {
        i = 0;
      while (argv[rev] [i] != '\0')
      {
      write(1, &argv[rev] [i], 1);
      i++;
      }
      write(1, "\n", 1);
      rev--;
    }
    }
     
}
