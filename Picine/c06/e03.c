#include <unistd.h>
void ft_swap(char **a, char **b)
{
     char* t;
    t = *a;
    *a = *b;
    *b = t;
}
void ft_sort(int argc, char *argv[])
{
    int i = 0;
    int j = 1;
    while (i < argc - 1)
    {
       j = 1;
        while (j < argc - 1)
        {
         if (argv[j] [0] > argv[j + 1] [0])
        {
           ft_swap(&argv[j], &argv[j + 1]);
            
        }
            j++;
        }
        i++;
    }
  
}
int main (int argc, char* argv[])
{
    int i = 0;
     int j = 1;
     if(argc > 1)
  {
    while (argc >= j)
    {
      i = 0;
      while (argv[j] [i] != '\0')
      {
        ft_sort(argc, argv);
       
      write(1, &argv[j] [i], 1);
      i++;
      }
      write(1, "\n", 1);
      j++;

    }
  }
}