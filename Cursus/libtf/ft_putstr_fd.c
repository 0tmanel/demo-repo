void ft_putstr_fd(char const *s, int fd)
{
    int i = 0;
    while (s[i] != '\0')
    {
        write(fd, &s[i], 1);
        i++;
    }
}