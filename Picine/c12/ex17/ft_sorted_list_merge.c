#include <stdio.h>
#include "ft_list.h"
#include <stdlib.h>
#include <string.h>
int acsending(void* a, void* b)
{
    return (*(int*)a - *(int*)b);
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
 t_list* ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)())
 {
    t_list *list = malloc(sizeof(t_list));
     t_list *temp = list;
    t_list *list_ptr = *begin_list1;
    t_list* list_other_ptr = begin_list2;
    while(list_ptr && list_other_ptr)
    {
        if(list_ptr->data < list_other_ptr->data)
        {
            list->next = list_ptr;
            list_ptr = list_ptr->next;
        }
        else if(list_ptr->data > list_other_ptr->data)
        {
            list->next = list_other_ptr;
            list_other_ptr = list_other_ptr->next;
        }
        list = list->next;
    }
    if(list_ptr!=NULL) list->next=list_ptr;
    else list->next=list_other_ptr;
    return temp->next;
 }
int main()
{
    int *a = malloc(sizeof(int));
    *a = 1;
    int *b = malloc(sizeof(int));
    *b = 3;
    int *c = malloc(sizeof(int));
    *c = 5;
    t_list *head = ft_create_elem(a);
    head->next = ft_create_elem(b);
    head->next->next = ft_create_elem(c);
    int *d = malloc(sizeof(int));
    *d = 2;
    int *e = malloc(sizeof(int));
    *e = 4;
    int *f = malloc(sizeof(int));
    *f = 6;
    t_list *head2 = ft_create_elem(d);
    head2->next = ft_create_elem(e);
    head2->next->next = ft_create_elem(f);
    t_list* temp = ft_sorted_list_merge(&head, head2, acsending);
    while(temp->next)
    {
        printf("%d\n", *(int*)temp->data);
       temp = temp->next;
    }
}