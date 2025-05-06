#include "ft_list.h"
t_list *ft_lstnew(void const *content, size_t content_size)
{
    t_list *new_link = (t_list *)malloc(sizeof(t_list));
    if (new_link == NULL)
        return NULL;
    if (!content)
    {
        new_link->content = NULL;
        new_link->content_size = 0;
    }
    else
    {
        new_link->content = content;
        new_link->content_size = content_size;
    }
    new_link->next = NULL;
    return new_link;
}