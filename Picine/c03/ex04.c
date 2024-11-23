#include <stdio.h>
#include <string.h>
int romanToInt(char* s) 
{
    typedef struct {
        char sympol;
        int value;
    }romanInt;

    romanInt romanNum[] ={ 
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000},
    };
   
    int i = 0;
    int total = 0;
 
   while (s[i] != 0)
   {
    int currentv = 0;
    int nextv = 0;
    int j = 0;
    int find = 0;
    while (j < sizeof(romanNum) / sizeof(romanNum[0]))
    {
        if(s[i] == romanNum[j].sympol)
        {
            currentv = romanNum[j].value;
            find = 1;
            break;
        }
        j++;
    }
    if(find)
    {
        if(s[i + 1] != 0)
        {
            j = 0;

        while (j < sizeof(romanNum) / sizeof(romanNum[0]))
    {
        if(s[i + 1] == romanNum[j].sympol)
        {
            nextv = romanNum[j].value;
            break;
        }

    }
    if (currentv < nextv)
    {
        total -= currentv;
    }else
    total += currentv;
        }
    }
    i++;
   }
   return total;
} 
int main ()
{
 char s[] = "MCMXCIV";
 int result = romanToInt(s);
 printf("%d", result);
 

}
