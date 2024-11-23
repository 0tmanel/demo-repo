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
  int ft_strcmp(void *s1, void *s2)
{
   
    return *(int*)s1 - *(int*)s2;
}

 void *btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *))
 {
    if (root == NULL)
    {
        return NULL;
    }
    if(cmpf(root->item, data_ref)== 0)
    {
        return root->item;
    }
    t_btree *current = root;
    void* found = btree_search_item(current->left, data_ref, cmpf);
    if(found != NULL)
    {
        return found;
    } 
        return btree_search_item(current->right, data_ref, cmpf);
    
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
    int num7 = 11;
    void* data = &num7;
    void* found = btree_search_item(root, data, &ft_strcmp);
    if(found != NULL)
    {

    printf("%d", *(int*)found);
    }else {
        return 0;
    }
}
    