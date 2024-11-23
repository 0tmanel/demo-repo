#include <unistd.h>
void ft_print_comb(void)
{
  int i = '0';
 
  while (i <= '7')
  {
    
  int j = i + 1;
    while (j <= '8')
    {
     
  int l = j + 1;
      while(l <= '9')
      {
        write(1, &i, 1);
        write(1, &j, 1);
        write(1, &l, 1);
        write(1, ", ", 2);
      ++l;
      }
      j++;
    }
    i++;
  }
  write(1, "\n", 1);

}
int main ()
{
   ft_print_comb();
}