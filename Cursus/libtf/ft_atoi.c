 //The atoi() function processes the string pointed to by str, interpreting its initial characters as a numerical value. It skips any leading whitespace characters and then converts the subsequent characters to an integer until a non-numeric character is encountered. The conversion stops at that point, and the resulting integer is returned.​


 #include <stdio.h>
 int ft_atoi(const char *str)
 {
    int result = 0;
    int sign = 1;
    int i = 0;
    //better to use bracket for clarity, and without them it is ok , because  || has a lower precedance 
    while((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
    i++;
    if(str[i] == '-' || str[i] == '+')
    {
        if(str[i] == '-')
            sign = -1;
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9')
    {
        result = (result * 10 ) + str[i] - '0';
        //result += str[i] - '0';
        i++;
    }
    return result * sign;

 }
 int main()
 {
    const char *str = "64";
    printf("%d\n", ft_atoi(str));
 }