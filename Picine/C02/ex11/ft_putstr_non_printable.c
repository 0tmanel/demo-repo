 //Non-printable characters are characters that do not have a visual 
 //representation when printed to the screen or displayed on a monitor. 
 //These characters are often used for control purposes (e.g., formatting
  //text, controlling devices, etc.) rather than being part of the visible
  // output. In the ASCII (American Standard Code for Information Interchange) 
  // character set, non-printable characters typically have ASCII values 
   //between 0 and 31 (decimal) and the ASCII value 127.
 #include <unistd.h>
 void ft_putstr_non_printable(char *str)
 {
    int i = 0;
    while (str[i] != '\0')
    {
        if((str[i] >= 0 && str[i] <= 31) || str[i] == 127) 
        {
            

        }
        write(1, &str[i], 1);
        i++;
    }

 }
 int main ()
 {
    char str[] = "Coucou tu vas bien ?";
    ft_putstr_non_printable(str);
    write(1, "\n", 1);
 }