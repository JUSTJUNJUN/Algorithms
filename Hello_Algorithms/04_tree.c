

#include <stdio.h>


#define MAX_SIZE 256


typedef struct tree_node TreeNode;


struct tree_node {
    TreeNode *left;
    TreeNode *right;
    int val;
};


int *tree_level_order(TreeNode *root, int *size)
{
    int front = 0, rear = 0;
    int index = 0, *arr;
    TreeNode *node;
    TreeNode **queue;

    /* Alloc queue memory */
    queue = (TreeNode **)malloc(sizeof(TreeNode *) * MAX_SIZE);
    queue[rear++] = root;

    /* Alloc array memory */
    arr = (int *)malloc(sizeof(int) * MAX_SIZE);

    while (front < rear) {
        /* Take out node from queue */
        node = queue[front++];
        /* Storage node value */
        arr[index++] = node->val;
        /* Put left node into queue */
        if (node->left != NULL) {
            queue[rear++] = node->left;
        }
        /* Put right node into queue */
        if (node->right != NULL) {
            queue[rear++] = node->right;
        }
    }

    /* Update array size and realloc array memory */
    *size = index;
    arr = realloc(arr, sizeof(int) * (*size));

    /* Free queue */
    free(queue);

    return arr;
}


void tree_pre_order(TreeNode *root, int *size)
{
    if (root == NULL) {
        return;
    }

    arr[(*size)++] = root->val;
    preOrder(root->left, size);
    preOrder(root->right, size);

    return;
}


void tree_in_order(TreeNode *root, int *size)
{
    if (root == NULL) {
        return;
    }

    inOrder(root->left, size);
    arr[(*size)++] = root->val;
    inOrder(root->right, size);

    return;
}


void tree_post_order(TreeNode *root, int *size)
{
    if (root == NULL) {
        return;
    }

    postOrder(root->left, size);
    postOrder(root->right, size);
    arr[(*size)++] = root->val;

    return;
}