#include <stdio.h>
#include "ft_list.h"
#include <stdlib.h>
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
void ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
    t_list *current;
    t_list *new_node;
    new_node = ft_create_elem(data);
    t_list* prev = NULL;
   
    if(*begin_list == NULL || ft_strcmp(data, current->data) <= 0)
    {
        new_node->next = *begin_list;
        *begin_list = new_node; //Update the head of the list to point to new_node. 
        return;
    }
    current = *begin_list;
    while (current != NULL && ft_strcmp(data, current->data) > 0)
    {
        prev = current;
        current = current->next;
    }
    prev->next = new_node;
    new_node->next = current;
}
int main ()
{

     t_list *head;
    t_list *original;
    char *s = malloc(sizeof(strlen(s)));
     char *s2 = malloc(sizeof(strlen(s2)));
      char *s3 = malloc(sizeof(strlen(s3)));

    s= "hilloplkpo";
    s2 = "hello";
   s3 = "hi";
   void* a = s;
   void* b = s2;
   void* c = s3;
    head = ft_create_elem(a);
    head->next = ft_create_elem(b);
    head->next->next = ft_create_elem(c);
    char *s4 = malloc(sizeof(strlen(s4)) + 1);
    s4 = "hf";
    void *data = s4;
    original = head;
    ft_sorted_list_insert(&original, data, &ft_strcmp);
    while (original != NULL)
    {
        printf("%s\n", (char*)original->data);
        original = original->next;
    }
}