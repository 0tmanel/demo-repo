#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_list.h"
void ft_list_remove_if(t_list **begin_list, void*data_ref, int (*cmp)(), void (*free_fct)(*void));
int ft_strcmp(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] == s2[i] && s1[i]!= 0 && s2[i] != '\0')
    {    
        i++;
    }
    return s1[i] - s2[i];
}
void ft_clear(void *head)
{
    free(head);
}

void ft_list_remove_if(t_list **begin_list, void*data_ref, int (*cmp)(), void (*free_fct)(*void))
{
     t_list* list_ptr = *begin_list;
    while (list_ptr != NULL)
    {
       
        if(cmp(list_ptr->data, data_ref) == 0)
        {
        free_fct(list_ptr->data);
        free(begin_list);
        }
        list_ptr = list_ptr->next;
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
    char *s = malloc(sizeof(strlen(s)));
     char *s2 = malloc(sizeof(strlen(s2)));
      char *s3 = malloc(sizeof(strlen(s3)));

    s= "hi";
    s2 = "hello";
   s3 = "hillo";
   void* a = s;
   void* b = s2;
   void* c = s3;
    head = ft_create_elem(a);
    head->next = ft_create_elem(b);
    head->next->next = ft_create_elem(c);
    original = head;
    char data[] = "hi";
    void *data_ref = data;
     ft_list_remove_if(&original, data_ref, &ft_strcmp, &ft_clear);
    while (original != NULL)
    {
        printf("%s", original->data);
        original = original->next;
    }
   
}