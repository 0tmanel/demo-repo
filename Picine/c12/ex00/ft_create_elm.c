#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>
t_list *ft_create_elem(void *data)
{
    t_list *new_node;
    new_node = malloc(sizeof(t_list));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
int main ()
{
    int value = 20;
    t_list *node = ft_create_elem(&value);
    printf("%d", node->next);
}