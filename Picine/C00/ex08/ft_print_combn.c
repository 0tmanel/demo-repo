#include <unistd.h>
/*
void ft_putchar(char c)
{
    write(1, &c, 1);
}
void print_comb(char *buffer, int n)
{
    int i = 0;

    while (i < n)
    {
        ft_putchar(buffer[i]);
        i++;
    }
    if (buffer[0] != '9' - n + 1)
    {
        write(1, ", ", 2);
    }
}

void backtrack(int n, int index, char *buffer, int start)
{
    // This is the base case of the recursion
    if (index == n)
    {
        print_comb(buffer, n);
        return;
        // since we are inside a recursive function (backtrack), returning means we go back to the previous recursive call where index == n - 1 (in this case, index == 1).
    }
    int num = start;
    while (num <= 9)
    {
        buffer[index] = num + '0';
        backtrack(n, index + 1, buffer, num + 1);
        num++;
    }
}

void ft_print_combn(int n)
{
    if (n <= 0 || n >= 10) // Ensure valid input
        return;

    char buffer[n]; // Store current combination
    backtrack(n, 0, buffer, 0);
}
*/
#include <unistd.h>

void print_comp(char *buff, int n)
{
    int i = 0;
    while (i < n)
    {
        write(1, &buff[i], 1);
        i++;
    }
    // If buffer[0] is not '7', it means we haven't reached the last valid combination yet, so we print ", " after the number.
    if (buff[0] != '9' - (n - 1))
    {
        write(1, ", ", 2);
    }
}
void ft_while(char *buffer, int n)
{
    while (1)
    {
        print_comp(buffer, n);
        int i = n - 1;
        while (i >= 0 && buffer[i] == '9' - (n - i - 1))
        {
            i--;
        }
        if (i < 0)
            break;
        buffer[i]++;
        int j = i + 1;
        while (j < n)
        {
            buffer[j] = buffer[j - 1] + 1;
            j++;
        }
    }
}
void ft_print_compn(int n)
{
    char buffer[n];
    int i = 0;
    while (i < n)
    {
        buffer[i] = i + '0';
        i++;
    }
    ft_while(buffer, n);
   
}

int main()
{
    ft_print_combn(4);
    write(1, "\n", 1);
}