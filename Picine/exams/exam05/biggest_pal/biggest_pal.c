#include <stdio.h>
#include <string.h>
#include <unistd.h>
int expandAroundCenter(char* s, int right, int left, int len)
{
    int L = left;
    int R = right;
    while(L >= 0  && R < len && s[L] == s[R])
    {
        L--;
        R++;
    }
    return R - L - 1;
}
int longestPalindrom(char* s)
{
    if(!s )
        return 0;
    int slen = strlen(s);
    if(slen < 1)
    return 0;
    int start = 0;
    int end = 0;
    int i = 0;
    while(s[i] != '\0')
    {
       int len1 =  expandAroundCenter(s, i, i, slen);
       int len2 = expandAroundCenter(s, i, i + 1, slen);
       int len = (len1 > len2) ? len1 : len2;

       if(len > end - start)
       {
        start = i - (len - 1) / 2;
        end = i + len / 2;
       }
       i++;
    }
    return end - start + 1;
}
    //    while(start <= end)
    //    {
    //     write(1, &s[start], 1);
    //     start++;
    //    }
    //    write(1, "\n", 1);
int main (int argc, char** av)
{
   //int num = longestPalindrom(av[1]);
   char* str = "abccccdd";
    int num = longestPalindrom(str);
   printf("%d\n", num);
}