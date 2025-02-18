// Non-printable characters are characters that do not have a visual
// representation when printed to the screen or displayed on a monitor.
// These characters are often used for control purposes (e.g., formatting
// text, controlling devices, etc.) rather than being part of the visible
//  output. In the ASCII (American Standard Code for Information Interchange)
//  character set, non-printable characters typically have ASCII values
// between 0 and 31 (decimal) and the ASCII value 127.
#include <unistd.h>
void ft_putstr_non_printable(char *str)
{
    int i = 0;
    // char hex[] = "0123456789abcdef";
    // int num;

    while (str[i] != '\0')
    {
        /*
        if ((str[i] >= 0 && str[i] <= 31) || str[i] == 127) {
        write(1, "\\", 2);  // YOU have to write two "\\"" because one is considered an escape character
        write(1, &"0123456789abcdef"[str[i] >> 4], 1);  // High nibble
        write(1, &"0123456789abcdef"[str[i] & 0xF], 1);  // Low nibble
    //To extract the high nibble (the upper 4 bits), you right-shift the bits by 4 positions,
    // and then you can apply & 0xF to ensure that any excess bits are discarded.

      */

        if ((str[i] >= 0 && str[i] <= 31) || str[i] == 127)
        {
            write(1, "\\", 1);                             // Write the escape sequence "\\"
            write(1, &"0123456789abcdef"[str[i] / 16], 1); // High nibble
            write(1, &"0123456789abcdef"[str[i] % 16], 1); // Low nibble
        }
        /*
    }
            if ((str[i] >= 0 && str[i] <= 31) || str[i] == 127) {
        write(1, "\\", 2);  // Write the escape sequence "\\x"
         num = str[i] / 16 ;
         write(1, &hex[num], 1);// High nibble str[i] / 16 divides the ASCII value
       num = str[i] % 16 ; // of the current character by 16 to get the high nibble (most significant 4 bits).
        write(1, &hex[num], 1);  // Low nibble
    */

        else
        {

            write(1, &str[i], 1);
        }

        i++;
    }
}
int main()
{
    char str[] = "Coucou\ntu vas bien ?";
    ft_putstr_non_printable(str);
    write(1, "\n", 1);
}