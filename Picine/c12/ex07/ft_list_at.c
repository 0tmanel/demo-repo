#include <stdio.h>
#include "ft_list.h"
#include <stdlib.h>
t_list *ft_list_at(t_list *begin_list, unsigned int nbr)
{
 
    int count = 0;
    while (begin_list != NULL)
    {
        if(count == nbr)
        {
            return begin_list;
        }
        begin_list = begin_list->next;
        count++;
    }
    return NULL;
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
void ft_clear(void* data)
{
    free(data);
}
void ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
    t_list *temp;
    while (begin_list != NULL)
    {
        temp = begin_list->next;
        free_fct(begin_list->data);
        free(begin_list);
        begin_list = temp;
    }

}
int main ()
{
    t_list *head;
    t_list *original;
    int *a = malloc(sizeof(int));
    int *b = malloc(sizeof(int));
    int *c = malloc(sizeof(int));
    if(a == NULL || b == NULL || c==NULL)
    {
        return 1;
    }
     *a = 20;
     *b = 3;
     *c = 2;
    head = ft_create_elem(a);
    head->next = ft_create_elem(b);
    head->next->next = ft_create_elem(c);
    original = head;
    unsigned int nbr = 1;
    t_list *list = ft_list_at(original, nbr);
    printf("%d", *(int*)list->data);
   ft_list_clear(original, &ft_clear);
}*/