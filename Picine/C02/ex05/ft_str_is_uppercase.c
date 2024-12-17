  #include <stdio.h>
  int ft_str_is_uppercase(char *str)
    {
        if(str[0] == '\0')
        {
            return 1;
        }
        int i = 0;
        while (str[i] != '\0')
        {
            if(!(str[i] >= 'A' && str[i] <= 'Z'))
            {
                return 0;
            }
            i++;
        }
        return 1;
    }
    int main()
    {
        char str[] = "HELLO";
       int ret = ft_str_is_uppercase(str);
       printf("%d\n", ret);
    }