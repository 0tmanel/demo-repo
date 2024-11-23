#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"
#include <string.h>
int ft_strcmp(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] == s2[i] && s1[i]!= 0 && s2[i] != '\0')
    {    
        i++;
    }
    return s1[i] - s2[i];
}
void ft_f(void* data)
{
   printf("%s", (char*)data);
}
void ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void
*data_ref, int (*cmp)())
{
     t_list* list_ptr;
    while (begin_list != NULL)
    {
        list_ptr = begin_list;
        if(cmp(list_ptr->data, data_ref) == 0)
        {
        f(list_ptr->data);
        }
        begin_list = begin_list->next;
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
    ft_list_foreach_if(original, &ft_f, data_ref, &ft_strcmp);
   
}