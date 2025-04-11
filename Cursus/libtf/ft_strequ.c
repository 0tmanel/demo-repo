#include <stdio.h>
int ft_strequ(char const *s1, char const *s2)
{
    int i = 0;
    while(s1[i] == s2[i]  )
    {
       if(s1[i] != '\0')
       return 1;
        i++;
    }
    return 0;
}
int main()
{
    char const* s1 = "hello";
    char const *s2 = "hellok";
    printf("%d\n",ft_strequ(s1, s2));

}