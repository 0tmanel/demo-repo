#include <stdio.h>
#include "ft_btree.h"
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
  
  int btree_level_count(t_btree *root)
  {
    int count = 0;
    int count2 = 0;
    if(root == NULL)
    {
        return 0;
    }
    
    count = btree_level_count(root->left);

    count2 = btree_level_count(root->right);


    if(count >= count2)
    {
        return count;
    }
    else
    return count2 ;

  }
int main ()
{
    int num = 1;
    void* nm = &num;
    t_btree *root = btree_create_node(nm);
    int num1 = 2;
    int num2 = 5;
    int num3 = 3;
    int num4 = 4;
    int num5 = 7;
    int num6 = 6;
    int num7 = 8;
    void *nm1 = &num1 ;
    void  *nm2 = &num2;
    void *nm3 = &num3;
    void *nm4 = &num4;
    void *nm5 = &num5;
    void *nm6 = &num6;
    void *nm7 = &num7;
   
    root->left = btree_create_node(nm1);
    root->right = btree_create_node(nm2);
    root->left->left = btree_create_node(nm3);
    root->left->right = btree_create_node(nm4);
     root->right->right = btree_create_node(nm5);
    root->right->left = btree_create_node(nm6);
    root->left->left->right = btree_create_node(nm7);
    int found = btree_level_count(root);
    printf("%d", found);
}