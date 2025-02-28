  #include <stdlib.h>
  #include <stdio.h>
  int num(int num)
  {
    return num;
  }
  int *ft_map(int *tab, int length, int(*f)(int))
  {
    int* array = malloc(length * sizeof(int));
    if(!array)
    {
        return NULL;
    }
    int i = 0;
    while (i < length)
    {
        array[i] = f(tab[i]);
        i++;
    }
    return array;
  }
  int main ()
  {
    int tab[] = {1, 2, 3, 4, 5};
    int length = 5;
   int* array =  ft_map(tab, length, num);// here we can pass the name of the function or add &

   int i = 0;
   while (i < length)
   {
    printf("%d", array[i]);
    i++;
   }
    printf("\n");
  }