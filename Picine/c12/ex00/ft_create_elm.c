#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>
t_list *ft_create_elem(void *data)
{
    t_list *new_node;
    new_node = malloc(sizeof(t_list));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
int main ()
{
    int value = 20;
    t_list *node = ft_create_elem(&value);
    printf("%d", node->next);
}
/*Recap of Ways to Create a List:
✅ 1. Dynamically allocated data + linked nodes (most flexible)

int *x = malloc(sizeof(int));
*x = 42;
t_list *node = ft_create_elem(x);
❌ 2. Stack variables as data (only if you don't plan to free data)

int x = 42;
t_list *node = ft_create_elem(&x); // Don't free node->data!
✅ 3. Array of strings or heap pointers (common in projects)

char *arr[] = {"hi", "there"};
t_list *head = NULL;
for (int i = 0; i < 2; i++) {
    t_list *node = ft_create_elem(arr[i]); // Points to string literals or heap-allocated strings
    node->next = head;
    head = node;
}
*/