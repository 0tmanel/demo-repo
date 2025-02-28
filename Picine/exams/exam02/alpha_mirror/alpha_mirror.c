#include <unistd.h>
int conver(char arr[], char c)
{
    int i = 0;
    while (arr[i] != '\0')
    {
        if(arr[i] == c)
        {
            return i;
        }
        i++;
    }
    return 0;

}
int conver2(char arr2[], char c)
{
    int i = 0;
    while (arr2[i] != '\0')
    {
        if(arr2[i] == c)
        {
            return i;
        }
        i++;
    }
    return 0;

}
int main ()
{
    char array [13] = "abcdefghijklm";
    char array2[13] = "nopqrstuvwxyz";
    char string [] = "zyx";
    int len = 12;
    int i = 0;
    while (string[i] != '\0')
    {
        if((string[i] >= 'a' && string[i] <= 'm' )|| (string[i] >= 'A' && string[i] <= 'M'))
        {
            if(string[i] >= 'A' && string[i] <= 'M')
            {
                string[i] += 32;
                string[i] = array2[len - conver(array, string[i])];
                string[i] -=32;
            }
            else{
            string[i] = array2[len - conver(array, string[i])];

            }
        }
        else if((string[i] >= 'n' && string[i] <= 'z' )|| (string[i] >= 'N' && string[i] <= 'Z'))
        {
            if(string[i] >= 'N' && string[i] <= 'Z')
            {
                 string[i] += 32;
                  string[i] = array[len - conver2(array2, string[i])];
                  string[i] -= 32;
            }else{
             string[i] = array[len - conver2(array2, string[i])];
            }
        }
        write(1, &string[i], 1);
        i++;
    } 
    write(1, "\n", 1);
}