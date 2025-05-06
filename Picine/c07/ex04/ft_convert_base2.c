int ft_len(char *str)
 {
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
 }
 //The function ft_nbr_len calculates the length (number of digits) required to represent a given number in a specified base.

 /*
 Example 1: ft_nbr_len(349, "0123456789ABCDEF", 0)
Base length (base_lenght):

The base is 0123456789ABCDEF, so base_lenght = 16 (base 16).
Number check:

The number is positive (349), so we use nb = 349.
Counting digits:

349 >= 16:
//349 / 16 = 21 (remainder 13), so we increment lenght by 1.
21 >= 16:
21 / 16 = 1 (remainder 5), so we increment lenght by 1.
1 < 16:
We stop. We increment lenght by 1 for the last digit (the 1).
Final length (lenght) = 3.

Return value: The function will return 3, indicating that 349 in base 16 takes 3 digits: 15D.*/

 int ft_nbr_len(int number, char *base_to_len, int lenght)
 {
    int base_lenght = ft_len(base_to_len);
    unsigned int nb;
    if(number < 0)
    {
       
        nb = (unsigned int)(-number);
        lenght++;
        //Instead of modifying number, we directly assign the positive value of number to nb. This ensures nb is correctly initialized as an unsigned integer.The sign is accounted for by incrementing lenght..
    }
    else
        nb = (unsigned int) number;
        while (nb >= (unsigned)base_lenght)
        {
            nb /= base_lenght;
            lenght++;
        }
        lenght++;
        // the lenght counter is incremented one more time to account for the last digit of the number, because the final digit is processed when nb becomes less than base_lenght and the loop exits.
        return lenght;
 }
 
char *ft_putnbr_base(int result, char*finalNumber, char *base_to)
{
    int lenght_base = ft_len(base_to);
    int len_finalNumber = ft_nbr_len(result, base_to, 0);
    long nb = result;
    int i = 0;
    if(nb < 0)
    {
        finalNumber[0] = '-';
        nb *= -1;
        i = 1;
        //here we printf the sign because the number is negative , then we turn it to a positive by * = 1
    }
    len_finalNumber--;
    while(nb >= lenght_base)
    {
        finalNumber[len_finalNumber] = base_to[nb % lenght_base];
        nb /= lenght_base;
       len_finalNumber--;
    }
    if(nb < lenght_base)
    {
       finalNumber[i] = base_to[nb];  
    }
    return finalNumber;
}

/*
To make the linker aware of the function in file2.c, you need to declare it in file1.c. This is why the line void helper_function(); appears in file1.c — it tells the compiler that helper_function() exists and will be defined somewhere (in this case, in file2.c).

Linking Multiple Files:
When you compile file1.c file2.c, GCC compiles both files separately and then links them together. As long as you provide the correct declarations in file1.c (e.g., void helper_function();), GCC will link everything properly. There’s no need to worry about which file contains which function — the linker will resolve the references as long as they are declared and defined correctly.
*/