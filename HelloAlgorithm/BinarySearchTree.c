

#include <stdio.h>
#include <string.h>


typedef struct tnode    tree_node;

struct tnode {
    int         node_value;
    tree_node   *left_node;
    tree_node   *right_node;
};


typedef struct {
    tree_node   *root;
} BinarySearchTree;


tree_node *
find_node_in_tree(BinarySearchTree *bst, int value)
{
    tree_node *tmp = bst->root;

    while (tmp != NULL) {
        if (tmp->node_value < value) {
            tmp = tmp->right_node;
        } else if (tmp->node_value > value) {
            tmp = tmp->left_node;
        } else {
            break;
        }
    }

    return tmp;
}


void
insert_node_into_tree(BinarySearchTree *bst, int value)
{
    if (!bst->root) {
        bst->root = (tree_node *)malloc(sizeof(tree_node));
        bst->root->node_value = value;
        return;
    }

    tree_node *cur = bst->root, *pre = NULL;
    while (cur != NULL) {
        /* 值为value的节点已存在,直接返回 */
        if (cur->node_value == value) {
            return;
        }

        pre = cur;

        if (cur->node_value < value) {
            cur = cur->right_node;
        } else if (cur->node_value > value) {
            cur = cur->left_node;
        }
    }
    
    tree_node *new = (tree_node *)malloc(sizeof(tree_node));
    new->node_value = value;

    if (pre->node_value < value) {
        pre->right_node = new;
    } else if (pre->node_value > value) {
        pre->left_node = new;
    }

    return;
}


void
delete_node_off_tree(BinarySearchTree *bst, int value)
{
    if (!bst->root) {
        return;
    }

    tree_node *cur = bst->root, *pre = NULL;

    while (cur != NULL) {
        if (cur->node_value == value) {
            break;
        }
        
        pre = cur;

        if (cur->node_value < value) {
            cur = cur->right_node;
        } else if (cur->node_value > value) {
            cur = cur->left_node;
        }
    }
    
    if (!cur) {
        return;
    }

    if (!cur->left_node || !cur->right_node) {
        tree_node *child = cur->left_node != NULL ? cur->left_node : cur->right_node;
        if (pre->left_node == cur) {
            pre->left_node = child;
        } else {
            pre->right_node = child;
        }
    } else {
        tree_node *tmp = cur->right_node;
        while (tmp->left_node != NULL) {
            tmp = tmp->left_node;
        }
        
        int tmp_val = tmp->node_value;
        delete_node_off_tree(bst, tmp_val);
        cur->node_value = tmp_val;
    }

    return;
}


int main(int argc, char const *argv[])
{
    return 0;
}


