#include "ft_list.h"
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
void ft_memdel(void *ap, size_t size)
{
    (void)size;
    if (ap)
        free(ap);
}
void ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
    t_list*temp = *alst;
    t_list* next;
    while(temp != NULL)
    {
        next = temp->next;
        del((temp)->content, (temp)->content_size);
        free(temp);
        temp = next;
    }
        *alst = NULL;

}
int main()
{
    int a = 10;
    int b = 11;
    int c = 12;
    t_list *head = ft_creat_elm(&a, 4);
    head->next = ft_creat_elm(&b, 4);
     head->next->next = ft_creat_elm(&c, 4);
    ft_lstdel(&head, ft_memdel);
    while(head != NULL)
    {
    printf("%d\n", *(int *)head->content);
    head = head->next;
    }
}