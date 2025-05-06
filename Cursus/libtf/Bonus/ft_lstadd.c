#include "ft_list.h"
#include <stdio.h>
t_list *ft_creat_elm(void *data, size_t size)
{
    t_list *new_node = (t_list *)malloc(sizeof(t_list));
    if (new_node == NULL)
        return NULL;
    new_node->content = data;
    new_node->content_size = size;
    new_node->next = NULL;

    return new_node;
}
void ft_lstadd(t_list **alst, t_list *new)
{
    new->next = *alst;
    *alst = new;
 }
int main (){
    int a = 10;
    int b = 11;
    t_list *head = ft_creat_elm(&a, 4);
    t_list* new = ft_creat_elm(&b, 4);
   ft_lstadd(&head, new);
   while(head != NULL)
   {
   printf("%d\n", *(int *)head->content);
    head = head->next;
   }
}