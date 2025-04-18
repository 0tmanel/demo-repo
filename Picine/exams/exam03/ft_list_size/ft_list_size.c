#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>
void linked_list(t_list *s, int num)
{
    t_list *temp, *r;
    if(s == NULL)
    {
        temp = malloc(sizeof(t_list));
        temp->next = NULL;
        temp->data = num;
        s = temp;
    }
    else{
        temp = s;
        while(temp->next != NULL)
            temp = temp->next;
        r = malloc(sizeof(t_list));
        r->next = NULL;
        r->data = num;
        temp->next = r;  
    }

}
int	ft_list_size(t_list *begin_list)
{
    int index = 0;
    while(begin_list->next != NULL)
    {
        index++;
        begin_list = begin_list->next;
    }
    return index;

}
int main ()
{
    t_list p;
    p.next = NULL;
    linked_list(&p, 1);
    linked_list(&p, 2);
    linked_list(&p, 3);
    linked_list(&p, 4);
    linked_list(&p, 5);
   printf("%d\n", ft_list_size(&p));
}