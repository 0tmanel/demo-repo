#include "ft_list.h"
void ft_memdel(void *ap, size_t size)
{
    (void)size;
    //     You're not actually using the size parameter. That’s fine, but in C, when you declare a parameter and don’t use it, the compiler gives you a warning like:

    // warning: unused parameter ‘size’

    // So to tell the compiler:

    // "Yes, I know this variable is unused — it's intentional."

    // We write:

    // (void)size;
    // if (ap) → make sure the memory we're about to free is valid.
    if (ap)
        free(ap);
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
void ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
    if (*alst && alst)
    {
        del((*alst)->content, (*alst)->content_size);
        free(*alst);
        *alst = NULL; // BE CAREFULL TO DO TEMP = NULL;
        // // If we try to dereference a freed pointer, its behavior is undefined. As a result, some programmers will explicitly assign NULL to a pointer to designate the pointer as invalid.
    }
}
int main()
{
    int a = 10;

    t_list *head = ft_creat_elm(&a, 4);
    ft_lstdelone(&head, ft_memdel);
    printf("%d\n", *(int *)head->content);
}