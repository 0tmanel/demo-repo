#include "ft_list.h"
void free_node(t_list* elem)
{
   printf("%d\n", *(int *)elem->content);
}
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
void ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
    while(lst != NULL)
    {
        f(lst);
        lst = lst->next;
    }
}
int main()
{
    int a = 10;
    int b = 11;
    int c = 12;
    t_list *head = ft_creat_elm(&a, 4);
    head->next = ft_creat_elm(&b, 4);
     head->next->next = ft_creat_elm(&c, 4);
    ft_lstiter(head, free_node);
   
}
