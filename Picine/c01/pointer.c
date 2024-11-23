#include <unistd.h>
#include <stdio.h>

int *find_largest(int a[], int n)
{
  int i = 0;
  int *largest = &a[0];
}
int main ()
{
    int arr[] = {34, 87, 39, 46, 20, 65, 31, 90, 28, 2};
    int i = 10;
    int *largest = find_largest(arr, i);
    printf("%d", *largest);
    
}