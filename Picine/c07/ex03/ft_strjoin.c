#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int ft_len(char *str)
 {
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
 }
 int strs_len(int size, char **strs)
 {
     int i = 0;
    int len = 0;
    while (i < size)
    {
        len += ft_len(strs[i]);
        i++;
    }
    
    return len;
 }
  ft_inner1(char **strs, char *arr, char *sep, int size, int i, int j)
  {
    int l = 0;
        while (strs[i][l] != '\0')
        {
            arr[j] = strs[i][l];
            j++;
            l++;
        }
        int r = 0;
        while (sep[r] != '\0' && i < size - 1)
        {
            arr[j] = sep[r];
            r++;
            j++;
        }
  }
 void ft_while(char **strs, char *arr, char *sep, int size)
 {
     int i = 0;
    int j = 0;
    while (i < size)
    {
        ft_inner1(strs, arr, sep, size, i, j);
        i++;
    }
    strs[i][j] = '\0';
 }
 char *ft_strjoin(int size, char **strs, char *sep)
 {
    //strs is an array of pointers to char. More specifically, it is an array where each element is a char*, which points to the first character of a string.
   //When you pass strs to a function, you're actually passing a pointer to the first element of the array, which is of type char*. This is because in C, arrays decay into pointers when passed to functions.
    int len = strs_len(size, strs);
    int sep_len = ft_len(sep) * (size - 1);
    //we calcultae the length of sep for all strings except for the last one
    int total_lent = len + sep_len;
    char *arr = (char *) malloc(total_lent + 1 * sizeof(char));
    if(arr == NULL)
    {
        return NULL;
    }
    if(size == 0)
    {
        arr[0] = '\0';
        return arr;
    }
        ft_while(strs, arr, sep, size);
        //you are not allowd to have more than 24 line in a function, so i am spliting them 
      
    return arr;
 }
 int main ()
 {
    char *strs[] ={"hello", "world", "how are", "you"};
    //char *strs[]: This declares strs as an array of pointers to char.
  //char * means a pointer to char, which is how we represent strings in C (since strings are essentially arrays of characters in C).
  //[] means you're declaring an array of these pointers. The size of the array is determined by the number of elements in the initializer, which in this case is 4.
  //= {"hello", "world", "how are", "you"}: This is the initializer list that contains 4 string literals, each of which is a pointer to the first character of a null-terminated string.
  char sep[] = ", ";

  int size = 4;
  
   char * arr = ft_strjoin(size, strs, sep);
   printf("%s", arr);
     printf("\n");
free(arr);
 }

//**********************VERSION 2******************************* */
//in this version we do not split the function 

/*
int ft_len(char**strs, int size, char *sep)
{
    int i = 0;
     int j = 0;
    int k = 0;
    int l = 0;

    while (i < size)
    {
      j = 0;
      while (strs[i][j] != '\0')
      {
        j++;
      }
      k += j;
      i++;
    }
    while (sep[l] != '\0')
    {
      l++;
    }

   
   return k + (l * size - 1) + 1;

}
char *ft_strjoin(int size, char **strs, char *sep)
{
 
   char* str =  malloc((ft_len(strs, size, sep) ) * sizeof(char));
    if(str == NULL)
    return NULL;
    
    char *tem = str;
    if(size == 0)
    {
      tem[0] = '\0';
      return tem;
    }
    int i = 0;
    int j = 0;
    int k = 0;
 
    while (i < size)
    {
     j = 0;
      
        while (strs[i][j] != '\0')
        {
          str[k] = strs[i][j];
          k++;
          j++;
        }  
        if(i < size - 1)
        {
          j = 0;
          while (sep[j] != '\0')
          {
            str[k] = sep[j];
            k++;
            j++;
          }
        }
        i++;
    }
     str[k] = '\0';
    return tem;

}
int main ()
{
    char* strs[]= { "hello", "world" };
    char *sep = ", ";
    int size = 2;
    
  char *result = ft_strjoin(size, strs, sep);
  printf("%s", result);
  printf("\n");
  free(result);
}
*/