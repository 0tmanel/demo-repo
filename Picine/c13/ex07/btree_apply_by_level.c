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
  void ft_applyf(void* item, int current_level, int is_first_elem) {
    // Cast item to the appropriate type
    int data = current_level; // Example if item is an int

    // Check if this is the first element in the level
    if (is_first_elem) {
        // Format for the first element (e.g., start a new line)
        printf("%d", data);
    } else {
        // Format for subsequent elements (e.g., space or comma)
        printf(" %d", data);
    }
 
}

typedef struct s_queue_node {
    t_btree *node;            // Pointer to the tree node
    int level;                // Level of the node
    struct s_queue_node *next; // Pointer to the next node in the queue
} t_queue_node;

typedef struct s_queue {
    t_queue_node *front;  // Pointer to the front node of the queue
    t_queue_node *rear;   // Pointer to the rear node of the queue
    int size;             // Number of elements in the queue (optional)
} t_queue;
  void btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem))
  {
    if(root == NULL)
    {
        return ;
    }
    t_queue queue;
    queue.front = NULL;
    queue.size = 0;
    queue.rear = NULL;
   
    t_queue_node* current;
    current = malloc(sizeof(t_queue_node));
    if(current == NULL)
    {
        return;
    }
    current->node = root;
    current->level = 0;
    if(queue.front == NULL)
    {
        queue.front = current;
        queue.rear = current;
    }
    else
    {
        queue.rear->next = current;
          queue.rear = current;
    }
    queue.size++;
    int is_first_elem = 0;
    while (queue.front != NULL)
    {
    t_queue_node *temp = queue.front;
        queue.front = queue.front->next;
        queue.size--;
        applyf(temp->node->item, temp->level, is_first_elem);
        is_first_elem = 0;

        if (temp->node->left != NULL) {
        t_queue_node *new_node = malloc(sizeof(t_queue_node));
        if (new_node != NULL) {
            new_node->node = temp->node->left; // Set the left child
            new_node->level = temp->level + 1; // Increment level
            new_node->next = NULL;

    
 if (queue.front == NULL) {
                queue.front = new_node;
                queue.rear = new_node;
            } else {
                // Otherwise, add to the end of the queue
                queue.rear->next = new_node;
                queue.rear = new_node; // Move rear to the new node
            }
            queue.size++; // Increment queue size
        }
    }

    // 4. Check for right child (similar to left child)
    if (temp->node->right != NULL) {
        t_queue_node *new_node = malloc(sizeof(t_queue_node));
        if (new_node != NULL) {
            new_node->node = temp->node->right; // Set the right child
            new_node->level = temp->level + 1; // Increment level
            new_node->next = NULL; // New node points to NULL

            // If queue is empty, set front and rear to new node
            if (queue.front == NULL) {
                queue.front = new_node;
                queue.rear = new_node;
            } else {
                // Otherwise, add to the end of the queue
                queue.rear->next = new_node;
                queue.rear = new_node; // Move rear to the new node
            }
            queue.size++; // Increment queue size
        }
    }

    // 5. Free the temporary node if necessary
    free(temp);
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
     btree_apply_by_level(root, &ft_applyf);
    
}