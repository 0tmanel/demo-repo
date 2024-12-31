
#include <unistd.h>
/*
void ft_putchar(char c)
{
    write(1, &c, 1);
}

int ft_increment(char *arr, int n)
{
    int i = n - 1;
    while (i >= 0)
    {
        if (arr[i] < '9' - (n - 1 - i)) // Correct check for incrementing
        {
            arr[i]++;
            while (i < n - 1)  // Reset subsequent digits
            {
                arr[i + 1] = arr[i] + 1;
                i++;
            }
            return 1;
        }
        i--;
    }
    return 0;  // No more combinations to generate
}

void ft_combn(int n)
{
    if (n <= 0 || n > 9)  // Validate n within the range
        return;

    char arr[n];  // Array only of size n
    int i = 0;

    // Initialize array with first combination
    while (i < n)
    {
        arr[i] = '0' + i;  // '0' + i gives the character '0', '1', ..., based on i
        i++;
    }

    while (1)
    {
        // Print the current combination
        for (i = 0; i < n; i++)
        {
            ft_putchar(arr[i]);
        }

        // Check if it's not the last combination and print ", "
        if (arr[0] != '9' - (n - 1))
        {
            write(1, ", ", 2);
        }

        // Try to increment the combination, break if no more combinations
        if (!ft_increment(arr, n))
        {
            break;
        }
    }
}

int main()
{
    ft_combn(2);  // Test with n = 2
    return 0;
}
*/



//Dynamic Iterative Approach:
//The idea here is to use a vector-like mechanism
 //(which is achievable using an array) to generate the combinations. 
/*
 void ft_print_combn(int n)
{
char arr[n];
int i = 0;
while (i < n)
{
  
  arr[i] = i + '0';
  
  i++; 
}
// {"01"}
   while (1) {// boolean = true or false
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
}*/

#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void print_comb(int a, int b, int c)
{
    ft_putchar(a + '0');
    ft_putchar(b + '0');
    ft_putchar(c + '0');
}

void ft_print_combn(int n)
{
    if (n == 3) // for simplicity, we are only doing n=2
    {
        int a = 0;
        int b;
        int c;
        while (a < 8)
        {
            b = a + 1;
            while (b < 9)
            {
              c = b + 1;
              while(c < 10)
              {
                print_comb(a, b, c);
                if (!(a == 8 && b == 9 && c == 10)) // don't print a comma for the last one
                    write(1, ", ", 2);
                    c++;
              }
                b++;
            }
            a++;
        }
    }
}

int main()
{
    ft_print_combn(3); // You can change this for different values of n (though it's simplified for n=2)
    write(1, "\n", 1);
    return 0;
}