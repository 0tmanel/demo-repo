void ft_putendl_fd(char const *s, int fd)
{
    int i = 0;
    while (s[i] != '\0')
    {
        write(fd, &s[i], 1);
        i++;
    }
    write(fd, "\n", 1);
}