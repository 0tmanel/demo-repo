#ifndef FT_BOOLEAN_H
#define FT_BOOLEAN_H
#define EVEN_MSG "I have an even number of arguments."
#define ODD_MSG  "I have an odd number of arguments."
#define EVEN(nbr) ((nbr) % 2 == 0)
#define SUCCESS 0
typedef enum
{
    FALSE = 0,
    TRUE = 1
} t_bool;
void ft_putstr(char *str);
t_bool ft_is_even(int nbr);
#endif
