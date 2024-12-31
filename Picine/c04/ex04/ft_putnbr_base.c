 
 #include <unistd.h>
 #include <stdio.h>
  
   int ft_strlen(char *str)
 {
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
 }
 /*

 
 /************************** FIRST************************
 

int	checkerror(char *str)
{
	int	i;
	int	j;
	int	x;
	
	x = ft_strlen(str);
	i = 0;
	if (str[0] == '\0' || x == 1)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] <= 32 || str[i] == 127 || str[i] == 43 || str[i] == 45)
			return (0);
		j = i + 1;
		while (j < ft_strlen(str))
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
void	ft_putnbr_base(int nbr, char *base)
  {
    int error = checkerror(base);
    long n = (long) nbr;
    //This line casts the integer nbr to a long type and stores it in the variable n. The reason for this is to handle the case of negative integers and to prevent overflow when working with large numbers. Since nbr is an integer, it may have trouble storing large values, so using long ensures we can safely handle negative numbers and larger values.
    int len = ft_strlen(base);
    if(error)
    {

    if(n < 0)
    {
       write(1, "-", 1);
        n *= -1;
        //After printing the minus sign, the function converts n to a positive value by multiplying it by -1. This allows the rest of the function to deal with only positive numbers.
    }
    if(n < len)
    {
       write(1, &base[n], 1);
       //If n is smaller than the length of the base (len), it means the number is small enough to be directly represented by a single digit in the base. For example, in base 16, if n is 10, it will print 'A' (the 10th character in the base string).
//write(1, &base[n], 1);: This line writes the character corresponding to n to the standard output. &base[n] gets the pointer to the n-th character in the base string. This prints the "digit" of the number in the base.

    }
    
    if(n >= len)
    {
        ft_putnbr_base(n / len, base);
        ft_putnbr_base(n % len, base);
    }
    }
  }
 /****************************** SECOND************** */
 
   void ft_decimal(int n)
 {
     if (n < 0)
		{
			write(1, "-", 1);
			n *= -1;
		}
    if(n < 9)
    {
        write(1, &"0123456789"[n % 10], 1);
    }
    
    if(n > 9)
    {
        ft_decimal(n / 10);
       write(1, &"0123456789"[n % 10], 1);
    }
 }
 void ft_binary(int n)
 {
     if (n < 0)
		{
			write(1, "-", 1);
			n *= -1;
		}
    int result = n;
    char binary;
    if(result != 0)
    {
    binary = result % 2 + '0';
   ft_binary(result / 2);
    write(1, &binary, 1);
    }

 }
 void ft_hex(int n)
 {
    if (n < 0)
		{
			write(1, "-", 1);
			n *= -1;
		}
     if(n < 9)
    {
        write(1, &"0123456789ABCDEF"[n % 16], 1);
    }
    if(n > 9)
    {
        ft_hex(n / 16);
        write(1, &"0123456789ABCDEF"[n % 16], 1);
    }
 }
 void ft_octal(int n)
 {
     if (n < 0)
		{
			write(1, "-", 1);
			n *= -1;
		}
 if(n < 9)
    {
        write(1, &"poneyvif"[n % 8], 1);
    }
    if(n > 9)
    {
        ft_octal(n / 8);
        write(1, &"poneyvif"[n % 8], 1);
    }
 }
 void ft_putnbr_base(int nbr, char *base)
 {
    long n = (long) nbr;
    int len = ft_strlen(base);
    if(len == 16)
    {
        ft_hex(n);
    }
     if(len == 8)
    {
        ft_octal(n);
    }
    if(len == 2)
    {
        ft_binary(n);
    }
    if(len == 10)
    {
        ft_decimal(n);
    }
  }
 int main ()
 {
   ft_putnbr_base(-12, "01");
	printf("\n");
	ft_putnbr_base(40, "poneyvif");
	printf("\n");
	ft_putnbr_base(894867, "0123456789");
	printf("\n");
	ft_putnbr_base(53, "0123456789abcdef");
    printf("\n");
    //1010101010001.
 }
 /*if(n < 0)
    {
        ft_putchar('-');
        n = -n;
    }
    if(n < 9)
    {
        //To get the ones place (the last digit) of a number, 
        //you can use the modulo operator (%).
         //This operator gives the remainder of a division.
        ft_putchar(n % 10 + '0');
    }
    
    if(n > 9)
    {
        ft_putnbr(n / 10);
        ft_putchar(n % 10 + '0');
    }*/