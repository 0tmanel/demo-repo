 #include <stdlib.h>
 #include <stdio.h>
 int ft_strlen(const char *str)
 {
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
 }
 char *ft_strdup(const char *s1)
 {
    int len = ft_strlen(s1);
    char* string = (char*)malloc((len + 1) * sizeof(char));
    if(!string)
    return NULL;
    int i = 0;
    //here i < len is better that s1[i] != '\0' in term of CPU and readibility
    while (i < len)
    {
        string[i] = s1[i];
        i++;
    }
    string[i] = '\0';
    return string;
 }
 int main ()
 {
    const char *s1 = "hello world";
    char* string = ft_strdup(s1);
    printf("%s\n", string);
 }