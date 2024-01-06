

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


int
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


int main(int argc, char const *argv[])
{
    return 0;
}


