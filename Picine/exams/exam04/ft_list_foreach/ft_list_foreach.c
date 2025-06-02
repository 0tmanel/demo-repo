#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>
t_list* ft_creat_elem(void * data)
{
    t_list* head = malloc(sizeof(t_list));
    if(!head)
    return NULL;
    else{
    head->data = data;
    head->next = NULL;
    }
    return head;

}
void print_elem(void * data)
{
    printf("%d\n", *(int*)data);
}
void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
   t_list* list_ptr = begin_list;
   while(list_ptr)
   {
    (*f)(list_ptr->data);
    list_ptr = list_ptr->next;
   }
}
int main ()
{
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    t_list * head =  ft_creat_elem(&a);
    head->next = ft_creat_elem(&b);
    head->next->next = ft_creat_elem(&c);
     head->next->next->next = ft_creat_elem(&d);
     ft_list_foreach(head, print_elem);
}