#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"
t_list *global = NULL;
void ft_list_reverse_fun(t_list *begin_list)
{
    t_list* current = begin_list;//what do we assign here , the adreess of the struct as whole or just the data
    t_list *prev = NULL;
    t_list *next;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    global = prev;
    
   
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
    t_list *reversed_head;
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
   
     ft_list_reverse_fun(head);
  
 
    while (global != NULL) {
        printf("%d\n", *(int *)global->data);
       global = global->next;
    }
}