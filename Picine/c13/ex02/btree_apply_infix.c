#include <stdio.h>
#include <stdlib.h>
#include "ft_btree.h"
void ft_apply(void* item)
{
  printf("%d\n", *(int*)item);
}
void btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
  if(root == NULL)
  {
    return;
  }
    btree_apply_prefix(root->left, applyf);
   applyf(root->item);
    btree_apply_prefix(root->right, applyf);
}
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
    void* nm = &num;
    t_btree *root = btree_create_node(nm);
    int num1 = 8;
    int num2 = 7;
    int num3 = 6;
    int num4 = 5;
    int num5 = 4;
    int num6 = 3;
    void *nm1 = &num1 ;
    void  *nm2 = &num2;
    void *nm3 = &num3;
    void *nm4 = &num4;
    void *nm5 = &num5;
    void *nm6 = &num6;
   
    root->left = btree_create_node(nm1);
    root->right = btree_create_node(nm2);
    root->left->left = btree_create_node(nm3);
    root->left->right = btree_create_node(nm4);
     root->right->right = btree_create_node(nm5);
    root->right->left = btree_create_node(nm6);
    btree_apply_prefix(root, &ft_apply);
}