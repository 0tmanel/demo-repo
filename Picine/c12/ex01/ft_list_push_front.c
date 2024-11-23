#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>
t_list *ft_create_elem(void *data)
{
    t_list *new_node;
    new_node = malloc(sizeof(t_list));
    // The check ensures that you don’t 
    //attempt to use or manipulate the invalid pointer.
    if(!new_node)
    return NULL;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
void ft_list_push_front(t_list **begin_list, void *data)
{
   t_list *first = ft_create_elem(data);
    first->next = *begin_list;
    *begin_list = first;
    

}
int main ()
{
    t_list *begin_list = NULL;
    int value = 20;
    ft_list_push_front(&begin_list, &value);
    printf("%d", begin_list->next);//it is very imprtant to cast to 
}