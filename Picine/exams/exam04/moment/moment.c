#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
void ft_putchar(char c)
{
    write(1, &c, 1);
}
int calcu(unsigned int nbr)
{
    int index = 0;
    while(nbr != 0)
    {
        nbr /= 10;
        index ++;
    }
    return index;
}
void putnbr(unsigned int nbr, char* string)
{
    int i = 0;
    if(nbr <= 9)
    {
       string[i++] = nbr % 10 + '0';
    }
    while(nbr > 9)
    {
       string[i++] = nbr / 10 + '0';
        string[i++] = nbr % 10 + '0';
       nbr /= 10;
    }
}
char* moment(unsigned int duration)
{
    if (duration <= 59)
    {
         int nbr = calcu(duration);
          int i = nbr;
         char *string = malloc((nbr + 12)* sizeof(char));
         putnbr(duration, string);
        if (duration == 1)
         {
           char str[12] = " second ago.";
          // int i = nbr;
           int j = 0;
           while(str[j] != '\0')
            string[i++] = str[j++];
         }else {
         char str[13] = " seconds ago.";
           int i = nbr;
           int j = 0;
           while(str[j] != '\0')
            string[i++] = str[j++];
         }
          return string;
    }
    else if (duration >= 60 && duration <= 3599)
    {
        duration /= 60;
       int nbr = calcu(duration);
        int i = nbr;
         char *string = malloc((nbr + 13)* sizeof(char));
         putnbr(duration, string);
         return string;
         if (duration == 1)
         {
           char str[11] = "minute ago.";
           int i = nbr;
           int j = 0;
           while(str[j] != '\0')
            string[i++] = str[j++];
         }else {
         char str[12] = "minutes ago.";
           int j = 0;
           while(str[j] != '\0')
            string[i++] = str[j++];
         }
         string[i]  = '\0';
          return string;
    }
    else if (duration >= 3600 && duration <= 86399)
    {
        duration /= 3600;
        int nbr = calcu(duration);
        int i = nbr;
         char *string = malloc((nbr + 12)* sizeof(char));
         putnbr(duration, string);
         if (duration == 1)
         {
           char str[10] = " hour ago.";
           
           int j = 0;
           while(str[j] != '\0')
            string[i++] = str[j++];
         }else {
         char str[11] = " hours ago.";
           int i = nbr;
           int j = 0;
           while(str[j] != '\0')
            string[i++] = str[j++];
         }
                  string[i]  = '\0';
          return string;
    }
    else if (duration >= 86400 && duration <= 2629745)
    {
        duration /= 86400;
        int nbr = calcu(duration) ;
        int i = nbr;
         char *string = malloc((nbr + 11)* sizeof(char));
         putnbr(duration, string);
         if (duration == 1)
         {
           char str[9] = " day ago.";
           int i = nbr;
           int j = 0;
           while(str[j] != '\0')
            string[i++] = str[j++];
         }else {
         char str[10] = " days ago.";
           int i = nbr;
           int j = 0;
           while(str[j] != '\0')
            string[i++] = str[j++];
         }
                  string[i]  = '\0';
          return string;
    }
    return NULL;
}
int main()
{
   
//      char* string = moment(0);    // => 0 seconds ago.
//      printf("%s\n", string);
//     char* string = moment(1);    // => 0 seconds ago.
//      printf("%s\n", string);   // => 1 second ago.
//     char* string = moment(30);    // => 0 seconds ago.
//      printf("%s\n", string);   //=> 30 seconds ago.
//    char* string = moment(65);    // => 0 seconds ago.
//      printf("%s\n", string);   //=> 1 minute ago.
//     char* string = moment(120);    // => 0 seconds ago.
//      printf("%s\n", string); //=> 2 minutes ago.
//     char* string = moment(2400);    // => 0 seconds ago.
//      printf("%s\n", string); //=> 40 minutes ago.
   char* string = moment(3735);    // => 0 seconds ago.
     printf("%s\n", string); //=> 1 hour ago.
    // write(1, "\n", 1);
}