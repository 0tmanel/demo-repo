 #include <unistd.h>
 void  ft_addr(void *addr)
 {
     unsigned long long address = (unsigned long long)addr;
    char hex[] = "0123456789abcdef";
    char output[16];
    int i = 15;
   
    while (0 <= i)
    {
        output[i] = hex[address % 16];
        //The reason we fill the output array from behind (starting from the last index 
       // and moving backward) when converting the memory address to hexadecimal is due to 
        //the way division and remainders work when converting a number to a different
        // base (like hexadecimal). 
       // So the remainders are collected in reverse order: the first remainder is the least
        // significant digit (rightmost), and the last remainder corresponds to the most
          //significant digit (leftmost).
        address /= 16;
        i--;
    }
    write(1, output, 16);
    write(1, ": ", 2);
 }
 void ft_hex(char* hex)
 {
   
   
    write(1, &"0123456789abcdef"[ *hex/ 16], 1);
    write(1, &"0123456789abcdef"[ *hex % 16], 1);
    write (1, " ", 1);
 }
 void *ft_print_memory(void *addr, unsigned int size)
 {
    char *ptr = (char *)addr;
    if(size == 0)
    {
        return addr;
    }
   unsigned int i = 0;
    while (i < size)
    {
         
            ft_addr(ptr + i); // Print address of the current line
        
        ft_hex(ptr + i );
       
        if ((ptr[i] >= 0 && ptr[i] <= 31) || ptr[i] == 127) 
         {
        write(1, ".", 1);
          }
    else{
        write(1, &ptr[i], 1);

         }
       
            write(1, "\n", 1);
        
        i++;
    }

return addr;
 }
 int main ()
 {
    char str[16] = "hello w\nrld";
    unsigned int size = 13;
   ft_print_memory(str, size);
   write(1, "\n", 1);
 }