  #include "ft_btree.h"
  #include <stdio.h>
  #include <stdlib.h>
  t_btree *btree_create_node(void *item)
  {
    t_btree *node;
    node = malloc(sizeof(t_btree));
    if(node == NULL)
    {
        return NULL;
    }
    node->item = item;
    node->left = NULL;
    node->right = NULL;
    return node ;
  }
  int main ()
  {
    int num = 9;
    void * item = &num;
    t_btree* node = btree_create_node(item);
    printf("%d", *(int*)node->item);
  }