void ft_putstr_fd(char c, int fd)
{
    write(fd, &c, 1);
}