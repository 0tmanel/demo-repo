#include <unistd.h>
/*
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


*/
//Dynamic Iterative Approach:
//The idea here is to use a vector-like mechanism
 //(which is achievable using an array) to generate the combinations. 
 void ft_print_combn(int n)
{
char arr[n];
int i = 0;
while (i < n)
{
  
  arr[i] = i + '0';
  
  i++;
}
   while (1) {
        // Print the current combination
        for (i = 0; i < n; i++) {
            write(1, &arr[i], 1);  // Output each character
        }

        // Check if it's the last combination (e.g., for n=2, the last combination is "89")
        if (arr[0] == '9' - n + 1) {
            break;
        }

        // Output a comma and a space unless it's the last combination
        write(1, ", ", 2);

        // Find the rightmost digit that can be incremented
        i = n - 1;
        while (i >= 0 && arr[i] == '9' - (n - 1 - i)) {
            i--;  // Decrement i to find the next position to increment
        }

        // If all digits are at their maximum values (e.g., "89" for n=2), we stop
        if (i < 0) {
            break;
        }

        // Increment the digit at position `i` and reset all digits to its right
        arr[i]++;
        for (int j = i + 1; j < n; j++) {
            arr[j] = arr[j - 1] + 1;  // Reset digits to maintain increasing order
        }
    }
}

int main()
{
  ft_print_combn(2);
  write(1, "\n", 1);
}