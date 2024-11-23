#ifndef FT_BTREE_H
#define FT_BTREE_H

typedef struct TreeNode
{
    struct TreeNode *left;
    struct TreeNode *right;
    void *val;
}TreeNode;
#endif