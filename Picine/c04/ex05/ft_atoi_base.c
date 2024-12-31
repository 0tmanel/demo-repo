#include <stdio.h>
#include <unistd.h>
int ft_strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}
// returns the length of the base or 0 if the base is invalid
int checkerror(char *str)
{
    int i;
    int j;
    int x;

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
    return (-1);
}
int char_to_value(char c, char *base)
{
    int i = 0;
    while (base[i] != '\0')
    {
        if(c == base[i])
        return i;
        i++;
    }
    return -1;
}
/*
int	calc_res(char *str, char *base, int i)// explain this /
{
	int	base_len;
	int	res;
	int	j;

	res = 0;
	base_len = ft_strlen(base);
	while (str[i])
	{
		j = 0;
		while (base[j])
		{
			if (str[i] == base[j])
				break ;
			j++;
		}
		if (base[j] == '\0')
			break ;
		res = res * base_len + j;
		i++;
	}
	return (res);
}*/
int ft_atoi_base(char *str, char *base)
{
    int i = 0;
    int sign = 1;
    int result = 0;
    int base_len = ft_strlen(base);
    int error = checkerror(base);
    if (error == 0)
    {
        return 0;
    }
       
            while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
            {
                i++;
            }
            while (str[i] == '-' || str[i] == '+')
            {
                if (str[i] == '-')
                {
                    sign *= -1;
                    //The sign variable is initialized to 1 (positive), and it is only modified when a '-' character is encountered in the string. It is not incremented or updated by any other value except when handling the + or - sign.
                    //so multiplying a number with -1 it flips that numbert, if it is positive it becmoes negative, and if it is negative it becomes positive
                }
               
                i++;
            }
            while (str[i] != '\0')
            {
               int value = char_to_value(str[i], base);
               if(value == -1)
               break;
               result = result * base_len + value;
                i++;
            }
            return (result * sign);
            
           //return (calc_res(str, base, i) * sign); 
           // we multiply the result by sign to account for the sign of the number (positive or negative) based on the + or - characters in the input string. This behavior is similar to how the standard atoi function works.
}
int main(void)
{
    printf("%d\n", ft_atoi_base("	+++++--133742", "0123456789"));
    printf("%d\n", ft_atoi_base("	     ---101010", "01"));
    printf("%d\n", ft_atoi_base(" 	+---539", "0123456789abcdef"));
}

