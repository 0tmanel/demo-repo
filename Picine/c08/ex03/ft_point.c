#include "ft_point.h"
#include <stdio.h>
void set_point(t_point *point)
{
    point->x = 42;
    point->y = 21;

    printf("%d", point->x);
}
int main (void)
{
    t_point point;
    set_point(&point);
    return (0);
}