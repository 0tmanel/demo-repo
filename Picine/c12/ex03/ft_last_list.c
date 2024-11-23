#include <stdio.h>
#include "ft_list.h"
#include <stdlib.h>
t_list *ft_list_last(t_list *begin_list)
{
    t_list *node = begin_list;
 
    while (node->next != NULL)
    {
        node = node->next; 
    }
    
    return node;
}
/*
t_list *ft_create_elem(void *data)
{
	t_list* new_node;
	
	new_node = (t_list*)malloc(sizeof(t_list));
	if(new_node)
	{
		new_node->data = data;
		new_node->next = NULL;
	}
	return (new_node);
}
*/
int main ()
{
    t_list *head;
    head = malloc(sizeof(t_list));
    
    int a = 20;
    int b = 3;
    int c = 2;
    void *pa = &a;
    void *pb = &b;
    void *pc = &c;
    head = ft_create_elem(pa);
    head->next = ft_create_elem(pb);
    head->next->next = ft_create_elem(pc);
    t_list *last_list = ft_list_last(head);
    printf("%d", *(int*)last_list->data);

}