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
int compare(const void *a, const void* b)
{
    return (*(int*)a - *(int*)b);
}
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list * prv = NULL;
    t_list* list_ptr = *begin_list;
    while(list_ptr != NULL)
    {
        if((*cmp)(list_ptr->data, data_ref) == 0)
        {
            t_list* next = list_ptr->next;
            if(!prv)
            {
                *begin_list = next;
            }
            else{
            prv->next = next;
            }
            break;
        }
        prv = list_ptr;
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
     int data = 1;
     ft_list_remove_if(&head, &data, compare);
     while(head) 
     {
        printf("%d\n", *(int*)head->data);
        head = head->next;
     }
}