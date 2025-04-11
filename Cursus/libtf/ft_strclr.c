void ft_strclr(char *s)
{
    if(!s)
    return;
    
    //ft_memset(s, '\0', ft_strlen(s));
    int i = 0;
    while(s[i] != '\0')
    {
        s[i] = '\0';
        i++;
    }
}
