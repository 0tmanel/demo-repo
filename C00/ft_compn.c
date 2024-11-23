#include <unistd.h>

void ft_putchar(char c)
{
  write(1, &c, 1);
}

int ft_increment(char *arr, int n)
{
int i;
    i = n - 1;
    while (i >= 0)
    {
        if(i < '9' - (n - 1 - i))
        {
        arr[i]++;
        while (i < n -1)
        {
            arr[i + 1] = arr[i] + 1;
            i++;
        }
        return 1;
        }
        
        i--;
    }
        return 0;
}
void ft_combn(int n)
{

  char arr[10];
  int i ;
  if(n > 10 || n <= 0)
  return;
  i = 0;
  while (i < n)
  {
      arr[i] = i + '0';
      i++;
  }
 while (1)
 {
     i = 0;
  while(i < n )
  {
   ft_putchar(arr[i]);
    i++ ;
  
  }
  if (arr[0] != '9' - (n -1))
    write(1, ", ", 2);
  if (!ft_increment(arr, n));
  break;
 }

}
int main ()
{
  ft_combn(10);
}