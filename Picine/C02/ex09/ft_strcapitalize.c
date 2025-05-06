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
//  int check(char c)
// {
//     if(!((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') ))
//     {
//         return 1;
//     }
//     return 0;
// }
// int is_lower(char c)
// {
//     if((c >= 'a' && c <= 'z'))
//     {
//         return 1;
//     }
//     return 0;
// }
//  char *ft_strcapitalize(char *str)
//  {
//     int i = 0;
    
//     while(str[i] != '\0')
//     {
//         if((is_lower(str[i]) && check(str[i - 1])))
//         {
//             str[i] -= 32;
//         }
//         i++;
//     }
//     return str;
//  }
int main ()
{
    char str[] = " salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
   char *retu =  ft_strcapitalize(str);
   printf("%s\n", retu);

}