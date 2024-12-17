  //Printable characters are characters in the character encoding system 
  //(like ASCII) that can be visually displayed or printed. In other words, 
  //they are characters that represent visible symbols, letters, numbers, 
  //punctuation marks, and special characters that can be seen on a screen or
   //printed on paper. These characters are part of the character set that is 
  // rendered as part of the content we interact with on computers, websites,
   // and in printed materials. the printable characters in the ascii table 
   // range from 32 to 126


  #include <stdio.h>
  int ft_str_is_printable(char *str)
    {
        if(str[0] == '\0')
        {
            return 1;
        }
        int i = 0;
        while (str[i] != '\0')
        {
            if(!(str[i] >= 32 && str[i] <= 126))
            // if(!(str[i] >= ' ' && str[i] <= '~')) the same as number
            {
                return 0;
            }
            i++;
        }
        return 1;
    }
    int main()
    {
        char str[] = "hello";
       int ret = ft_str_is_printable(str);
       printf("%d\n", ret);
    }