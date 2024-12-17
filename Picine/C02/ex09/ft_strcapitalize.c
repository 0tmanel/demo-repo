//Alphanumeric refers to characters that are letters (A-Z, a-z)
// and numbers (0-9). These characters are used to form words, sentences, 
// and other types of data in text form.
//Alphanumeric characters do not include special symbols 
//or punctuation marks, such as !, @, #, or spaces.
#include <stdio.h>

 char *ft_strcapitalize(char *str)
 {
    int i = 0;
    int beg_of_word = 1;
    while (str[i] != '\0')
    {
       if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9'))
       {
        if(beg_of_word)
        {
            if(str[i] >= 'a' && str[i] <= 'z')
            {
                str[i] -= 32;
            }
            else{
                if(str[i] >= 'A' && str[i] <= 'Z')
                {
                    str[i] +=32;
                }
            }
            beg_of_word = 0;
        }
       }
       else{
        beg_of_word = 1;
       }
       i++;
    }
    return str;

 }
int main ()
{
    char str[] = " salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
   char *retu =  ft_strcapitalize(str);
   printf("%s\n", retu);

}