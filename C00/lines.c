#include <stdio.h>
#define MAX_LINES 100

int shortest_line_index(int lines[], int n) 
{
int j;
int shortest = 0;
for (j = 1; j < n; j++)
if (lines[j] < lines[shortest])
shortest = j;
return shortest;
}
void solve(int lines[], int n, int m) {
int i, shortest;
for (i = 0; i < m; i++) {
shortest = shortest_line_index(lines, n);
printf("%d\n", lines[shortest]);
 lines[shortest]++;
}
}
int main(void) 
{
int lines[MAX_LINES];
int n, m, i;
scanf("%d%d", &n, &m);
for (i = 0; i < n; i++)
scanf("%d", &lines[i]);
solve(lines, n, m);
return 0;
}
char num[3];
    int  number = 0;
     char num2[3];
    int  number2 = 0;
    if(number < 10)
    {
      num[0] = '0';
    num[1] = '0' + number;
    num[2] = '\0';
    }
    else
    {
    num[0] = '0' + (number / 10);
    num[1] = '0' + (number % 10);
    num[2] = '\0';
    }
    if(number2 < 10)
    {
      num2[0] = '0';
    num2[1] = '0' + number2;
    num2[2] = '\0';
    }
    else
    {
    num2[0] = '0' + (number2 / 10);
    num2[1] = '0' + (number2 % 10);
    num2[2] = '\0';
    }
    char i = num[0];
    char l = num[1];
    char j = num2[0];
    char k = num2[1];
    while (i <= '9')
    {
     while (l <= '9')
     {
          while (j <= '9')
          {
               while (k <= '9')
               {
                     write(1, &i, 1);
                     write(1, &l, 1);
                     write(1, " ", 1);
                     write(1, &j, 1);
                     write(1, &k, 1);
                     write(1, " ", 1);
                     
                     k++;
               }
               j++;
          }
          l++;
     }
     i++;
    }


}
int main ()
{
    ft_comp2();
}