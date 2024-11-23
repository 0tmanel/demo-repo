#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_list.h"
void ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
    if(*begin_list1 == NULL)
    {
        *begin_list1 = begin_list2;
        return 1;
    }
    t_list* temp = *begin_list1;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
  
    temp->next = begin_list2;
   
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
    t_list *head2;
    int *a = malloc(sizeof(int));
    int *b = malloc(sizeof(int));
    int *c = malloc(sizeof(int));
    if(a == NULL || b == NULL | c==NULL)
    {
        return 1;
    }
     *a = 20;
     *b = 3;
     *c = 2;
    head = ft_create_elem(a);
    head->next = ft_create_elem(b);
    head->next->next = ft_create_elem(c);

    int *d = malloc(sizeof(int));
    int *e = malloc(sizeof(int));
    int *f = malloc(sizeof(int));
    if(d == NULL || e == NULL | f==NULL)
    {
        return 1;
    }
     *d = 40;
     *e = 30;
     *f = 20;
    head2 = ft_create_elem(d);
    head2->next = ft_create_elem(e);
    head2->next->next = ft_create_elem(f);
    ft_list_merge(&head, head2);
    while (head != NULL)
    {
        printf("%d\n", *(int*)head->data);
        head = head->next;
    }
}