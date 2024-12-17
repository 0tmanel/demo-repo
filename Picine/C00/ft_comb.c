//To print the values of i, j, and k as characters, you need to cast them
 //to characters. You can use the char type, or, if you're dealing with 
 //ASCII arr, you can convert the integer values to their corresponding 
 //character representation.Since i, j, and k are integers, but you want to 
 //output their ASCII values (for example, printing the number 1 as the 
 //character '1'), you need to convert them using the char type.
#include <unistd.h>
#include <stdio.h>
  void ft_print_comb(void)
  {
/*
    char j;
    char k;
    char i;
    i = '0';
    while (i <= '7')
    {
        j = i + 1;
        while (j <= '8')
        {
             k = j + 1;
            while (k <= '9')
            {
               write(1, &i, 1);
                write(1, &j, 1);
                 write(1, &k, 1);
//The write() function in C writes raw bytes (binary data)
//to a file descriptor, but when you pass a variable like
//i, j, or k to write(), you're passing an integer (a number,
//typically 4 bytes), not a character (1 byte). The write() 
//function expects a pointer to a buffer and the size of the data you're writing.
//However, when you write &i, &j, or &k, you're giving it the address 
//of the integer, not the integer value itself. This means that instead
 //of printing the character corresponding to the values of i, j, or k, 
 //it's trying to print the raw bytes of the memory address where i, j, or k are stored, 
 //which leads to unexpected results (and often doesn't work properly).
              
               if(i != '7' || j != '8' || k != '9')
               {
                write(1, ", ", 2);
               }
               
                k++;
            }
            j++;
        }
        i++;
    }*/
  ////////the Next Combination Algorithm:\\\\\\\\\
    
    char arr[3] = {'0', '1', '2'};  // Initialize first combination: 012

 while (arr[0] <= '7')
 {
    write(1, &arr[0], 1);
    write(1, &arr[1], 1);
    write(1, &arr[2], 1);
    if(arr[0] != '7' || arr[1] != '8' || arr[2] != '9')
    {
        write (1, ", ", 2);
    }
    if(arr[2] < '9')
    {
        arr[2]++;
    }else if (arr[1] < '8')
    {
        arr[1]++;
        arr[2] = arr[1] + 1;//reset 9 to become 3 and 
    }else
    {
        arr[0]++;
       arr[1] = arr[0] + 1;  // Reset the middle digit
        arr[2] = arr[1] + 1;
    }
 }
 write(1, "\n", 1);

  }
  int main ()
  {
    ft_print_comb();
    return 0;
  }