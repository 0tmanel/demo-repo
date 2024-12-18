#include <stdio.h>
 void ft_sort_int_tab(int *tab, int size)
 {
    //int i = 1;
    ////******BUBBLE SORT******\\\\\*
   
    /*int j;
    while (i < size - 1 )
    {
        j = 0;
        while (j < size - 1 - i )
// if you used j < size you need also use the same 
 //structure in the outer loop (i < size), there is also the other way 
 // (j <= size - 1) , note, the structure that you did 
 //in the inner loop it must be in the outer loop
        {
            if(tab[j] > tab[j + 1])
            {
            int temp = tab[j];
            tab[j] = tab[j + 1];
            tab[j+1] = temp;
            }
            j++;
        }
        i++;
        //Why Use i < size - 1 in Sorting Algorithms?
//In sorting algorithms like Bubble Sort, the reason we use i < size - 1 
//(or similar conditions) is because each pass through the array places at least 
//one element in its correct final position. By the end of the first pass, 
//the largest element is placed at the end of the array; on the second pass, 
//the second largest element is placed at the second-to-last position, and so on.
//Here’s why i < size - 1 is useful:

//After each pass of the inner loop 
//(comparison and possible swapping), the largest element 
//that hasn't been sorted yet gets placed at the end of the array. 
//This means the last element of the array is correctly positioned,
 //so you don't need to compare it again.

//After the first pass, you know that the largest element is at the last position,
 //so the number of elements to compare in the next pass can be reduced by one.
  //Therefore, you don't need to perform a full loop for 
  //i = size - 1 because the last element is already sorted.
    }*/
   ////*******SELECTION SORT****** **\\\\\*  It is 60 per cent more efficient than bubble sort.
//Selection sort is a sorting algorithm that has a quadratic running 
//time complexity of O(n2), thereby making it inefficient
// to be used on large lists.Selection sort is generally used for sorting files
//with very large objects (records) and small keys.
/*while (i < size)
{
    if (smallest > tab[i])
    {
        smallest = tab[i];
    }
    i++;
}*/
int small;
int temp;
int i = 0;
while (i < size)
{
    small = i;
    int j = i + 1;
    while (j < size)
    {
        //{5, 3, 6, 7}
        if(tab[j] < tab[small])
        {
            small = j;
            temp = tab[i];
            tab[i] = tab[j];
            tab[j] = temp;
        }
        j++;
    }
    i++;

}


 }
int main ()
{
    int tab[] = {2, 5, 4, 3, 1, 6};
    int size = 6;
    ft_sort_int_tab(tab, size);
    int i = 0;
    while (i < size)
    {
        printf("%d", tab[i]);
        i++;
    }
    printf("\n");
}