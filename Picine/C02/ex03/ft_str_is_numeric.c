#include <stdio.h>
#include <unistd.h>


    int ft_str_is_numeric(char *str)
    {
        int i = 0;
        while (str[i] != '\0')
        {
            if(! (str[i] >= '0' && str[i] <= '9'))
            //be carefull to not write  if(! str[i] >= '0' && str[i] <= '9')
        // In C, the ! (logical NOT) operator has higher precedence than
        //the comparison operators (>= and <=). So, the expression 
         //! str[i] >= '0' is being evaluated differently than you might expect.
            {
                return 0;
            }
            i++;
        }
        return 1;
    }
    int main()
    {
        char str[] = "123a";
       int ret = ft_str_is_numeric(str);
       printf("%d\n", ret);
    }