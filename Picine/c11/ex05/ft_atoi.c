int ft_atoi(char *str)
  {
    int i = 0;
    int result = 0;
    int sign = 0;
        while((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        {
            i++;
        }
        while(str[i] == '-' || str[i] == '+')
        {
            if(str[i]== '-')
            {
                sign++;
            }
            i++;
        }
        while(str[i] >= '0' && str[i] <= '9')
        {
            result = result * 10;
            result += str[i] - '0';
            i++;
        }
    if (!sign % 2 == 0)
    {
        return -result;
    }
   return result;
  }