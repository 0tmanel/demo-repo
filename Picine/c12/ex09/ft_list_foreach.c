#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"
void ft_f(void* data)
{

   *(int*)data += 5;
}
void ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    t_list* list_ptr;
    while (begin_list != NULL)
    {
        list_ptr = begin_list;
        f(list_ptr->data);
        begin_list = begin_list->next;
    }
}
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
    ft_list_foreach(original, &ft_f);
    while (original != NULL)
    {
        printf("%d\n", *(int*)original->data);
        original = original->next;
    }
}