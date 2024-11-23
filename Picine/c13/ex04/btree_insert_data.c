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
   
    return (int*)s1 - (int*)s2;
}
 
void btree_apply_prefix(t_btree *root)
{
  if(root == NULL)
  {
    return;
  }
  
   printf("%d\n", *(int*)root->item);
    btree_apply_prefix(root->left);
    btree_apply_prefix(root->right);
}
  void btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *))
 { 
   if(*root == NULL)
   {
    *root = btree_create_node(item);
    return;
   }
   t_btree *node = *root;
   
    if(cmpf(item, (*root)->item) < 0)
    {
      if(node->left)
      {
        btree_insert_data(&(*root)->left, item, cmpf);

      }
      else 
      node->left = btree_create_node(item);
       
      
    }else 
    {
      if(node->right)
      {

        btree_insert_data(&(*root)->right, item, cmpf);
      }
      else
      node->right = btree_create_node(item);
    }
  
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
    int num7 = 9;
    void* data = &num7;
    btree_insert_data(&root, data, &ft_strcmp);
    btree_apply_prefix(root);

   
}