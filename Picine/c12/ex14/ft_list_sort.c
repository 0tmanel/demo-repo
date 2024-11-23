#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_list.h"
void ft_swap(t_list *a, t_list *b)
{
    void *temp = a->data;
    a->data = b->data;
    b->data = temp;
}
int ft_strcmp(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] == s2[i] && s1[i]!= 0 && s2[i] != '\0')
    {    
        i++;
    }
    return s1[i] - s2[i];
}
void ft_list_sort(t_list **begin_list, int (*cmp)())
{
    t_list *list_ptr = *begin_list;
    t_list* list_other_ptr ;
    while (list_ptr->next != NULL)//what do we call this algortihm
    {
        list_other_ptr = list_ptr->next;//how to decrement in the struct
        while (list_other_ptr != NULL)
        {
            if (cmp(list_ptr->data, list_other_ptr->data) > 0)
            {
           
                ft_swap(list_ptr, list_other_ptr);
            }
            
            list_other_ptr = list_other_ptr->next;
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
   char *s = malloc(strlen("hilloplkpo") + 1); // +1 for the null terminator
    char *s2 = malloc(strlen("hello") + 1);
    char *s3 = malloc(strlen("hi") + 1);

    if (s == NULL || s2 == NULL || s3 == NULL) {
        return 1; // Handle memory allocation failure
    }

    strcpy(s, "hilloplkpo");
    strcpy(s2, "hello");
    strcpy(s3, "hi");

    void* a = s;
    void* b = s2;
    void* c = s3;
    head = ft_create_elem(a);
    head->next = ft_create_elem(b);
    head->next->next = ft_create_elem(c);
    original = head;
    ft_list_sort(&original, &ft_strcmp);
    while (original != NULL)
    {
        printf("%s\n", (char*)original->data);
        original = original->next;
    }
}