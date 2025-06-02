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
/*Let’s say the tree is:

mathematica
Copy
Edit
        A
       / \
      B   C
     / \
    D   E
Nodes:

root = A

root->left = B

root->right = C

root->left->left = D

root->left->right = E

🔍 What happens with this code:
c
Copy
Edit
int left = maxDepth(root->left);
int right = maxDepth(root->right);
Suppose you're at root = A.

This means:

First, the line int left = maxDepth(root->left); is executed.

This pauses execution of the current function (A).

It goes into a new call: maxDepth(B).

Inside maxDepth(B):

Again, it hits int left = maxDepth(root->left); → calls maxDepth(D).

Inside maxDepth(D):

D has no children, so both maxDepth(NULL) return 0, and it returns 1.

Now back in maxDepth(B), it executes:

int right = maxDepth(root->right); → calls maxDepth(E)

Inside maxDepth(E):

E has no children → returns 1.

Back in maxDepth(B):

Now it can compute max(1, 1) + 1 = 2 and return to maxDepth(A).

Now back in maxDepth(A):

It executes int right = maxDepth(root->right); → calls maxDepth(C)

C has no children → returns 1.

Finally, maxDepth(A) computes: max(2, 1) + 1 = 3.

*/