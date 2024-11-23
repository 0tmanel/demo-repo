#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_list.h"
int ft_strcmp(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] == s2[i] && s1[i]!= 0 && s2[i] != '\0')
    {    
        i++;
    }
    return s1[i] - s2[i];
}
t_list *ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
     t_list* list_ptr;
    while (begin_list != NULL)
    {
        list_ptr = begin_list;
        if(cmp(list_ptr->data, data_ref) == 0)
        {
       return begin_list;
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
    char *s = malloc(sizeof(strlen(s) + 1));
     char *s2 = malloc(sizeof(strlen(s2) + 1));
      char *s3 = malloc(sizeof(strlen(s3) + 1));
      strcpy(s, "hello");
      strcpy(s2, "hell");
      strcpy(s3, "hi");

   void* a = s;
   void* b = s2;
   void* c = s3;
    head = ft_create_elem(a);
    head->next = ft_create_elem(b);
    head->next->next = ft_create_elem(c);
    original = head;
    char data[] = "hell";
    void *data_ref = data;
   t_list* adrr = ft_list_find(original, data_ref, &ft_strcmp);
   printf("%s", (char*)adrr->data);
   
}