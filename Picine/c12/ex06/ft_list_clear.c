#include <stdio.h>
#include "ft_list.h"
#include <stdlib.h>
void ft_clear(void *head)
{
    free(head);
}
void ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
    t_list *temp;
    while (begin_list != NULL)
    {
        temp = begin_list->next;
        free_fct(begin_list->data);
        free(begin_list);
        begin_list = temp;
    }

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
int main ()
{
    t_list *head;
    t_list *original;
    int *a = malloc(sizeof(int));
    int *b = malloc(sizeof(int));
    int *c = malloc(sizeof(int));
    if(a == NULL || b == NULL | c==NULL)
    {
        return 1;
    }
     *a = 20;
     *b = 3;
     *c = 2;
    head = ft_create_elem(a);
    head->next = ft_create_elem(b);
    head->next->next = ft_create_elem(c);
    original = head;
      ft_list_clear(original, &ft_clear);      
   
}
/*Testing whether a list (or any allocated memory) has been successfully freed in C can be tricky because, once memory is freed, it is no longer valid. Attempting to access a freed pointer results in undefined behavior (memory corruption, crashes, etc.).

That said, there are a few ways you can check and confirm that memory was freed, but they require careful techniques and tools since C doesn't have automatic memory management or garbage collection like higher-level languages.*/