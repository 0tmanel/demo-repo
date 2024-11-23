#include <stdio.h>
#include "ft_list.h"
#include <stdlib.h>
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
t_list *ft_list_push_strs(int size, char **strs)
{
 
    t_list *head = NULL;
   t_list *current = NULL;
    t_list *node;
    int i = 0;
    while (i < size)
    {
        node = ft_create_elem(strs[i]);
        if(node == NULL)
        {
            return node;
        }
       if (head == NULL)
       {
        head = node;
        current = node;
       }else
       {

       current->next = node;
      current = node;
       }
        i++;
    }
   
    return head;
}
int main ()
{
    char* strs[] = {"bannana", "tomato", "carrot"};
    int size = 3;
    t_list *node = ft_list_push_strs(size, strs);
    printf("%s", (char*)node->next);

}