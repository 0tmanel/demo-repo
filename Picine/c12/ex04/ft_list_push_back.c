#include "ft_list.h"
#include <stdio.h> 
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
void ft_list_push_back(t_list **begin_list, void *data)
{
    t_list *last;
    t_list *temp;
    if(*begin_list == NULL)
    {
        *begin_list = ft_create_elem(data);
        return;
    }
    temp = *begin_list;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    last = ft_create_elem(data);
    temp->next = last;//next was pointing to null and now it point to another node  
}
int main() 
{
  t_list *head;
  t_list *original;

  int a = 13;
  int b = 3;
  int c = 7;
  void *d = &a;
  void *e = &b;
  void *f = &c;

  head = (t_list *)malloc(sizeof(t_list));
  head = ft_create_elem(d);
  head->next = ft_create_elem(e);
  head->next->next =ft_create_elem(f);
  original = head; //we same the first of the list 

  int value = 30;
 ft_list_push_back(&original, &value);
 while (head != NULL)
 {
    printf("%d\n", *(int*)head->data);
    head = head->next;
 }
  return 0;
}