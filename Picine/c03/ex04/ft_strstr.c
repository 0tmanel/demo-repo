 //The outer loop checks each position in str 
 //to see if it can be the start of a match.
//The inner loop checks if the characters from to_find 
//match those in str starting from that position.
//If a match is found, return the starting position of the match.
//If no match is found after checking all possible positions, return NULL.

 #include <stdio.h>
 #include <string.h>
 /*
 char *ft_strstr(char *str, char *to_find)
 {
    if(to_find[0] == '\0')
    {
        return str;
    }
    int i = 0;
    int j;
   
    while (str[i] != '\0')
    {
        j = 0;
        
         while (to_find[j] == str[i + j] && to_find[j] != '\0')
         {
            j++;
         }
            if(to_find[j] == '\0')
            {
                return str + i;
            }
         i++;
    }
    return 0;

 }*/
 int main ()
 {
    char str[] = "hello";
    char to_find[] = "el";
   //char *result = ft_strstr(str, to_find);
   char *result = strstr(str, to_find);
   printf("%s\n", result);
 }