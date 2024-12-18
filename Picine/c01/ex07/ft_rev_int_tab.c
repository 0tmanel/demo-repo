#include <stdio.h>
 void ft_rev_int_tab(int *tab, int size)
 {
    //******TWO POINTER (IN PLACE REVERSE)******\\\\\\
    This approach only requires O(n) time and O(1) extra 
    //space (since no additional arrays are used).
    int first = 0;
    int last = size - 1;
    
       
    
    while (first < last)
    {
        int temp = tab[first];
        tab[first] = tab[last];
        tab[last] = temp;
        first++;
        last--;
    }
    
   //******TEMPORARY ARRAY******\\\\\\
   
   //int len = size - 1;
   //int arr[size];
   //You're declaring int arr[size]; inside the function. 
   //This can be fine in most cases, but note that it creates a local array
   // on the stack. It’s generally better to dynamically allocate this 
   // temporary array if you want to be sure it's allocated properly. 
   // In this case, it's okay because it's within the scope of the function, 
   // but it’s a good practice to use malloc() if 
    //you want more flexibility in a larger scope. 
    //but as long as you still just in c01 use just local array because malloc() is forbiden for now
   /*int i = 0;
   int j = 0;
   while (len >= i)
   {
    arr[j] = tab[len];
    j++;
    len--;
   }
   int l = 0;
   while (l < size)
   {
    tab[l] = arr[l];
    l++;
   }
   */

 }
 //The two-pointer approach is the best in terms of space because it doesn't
  //require additional memory. If possible, use it as the primary method and only
   //fall back to the temporary array approach when needed for specific
   // requirements (like in situations where in-place reversal is not possible).
 int main ()
 {
    int tab[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = 10;
    ft_rev_int_tab(tab, size);
    int k = 0;
   while (k < size)
    {
        printf("%d", tab[k]);
        k++;
    }
    printf("\n");

    
 }