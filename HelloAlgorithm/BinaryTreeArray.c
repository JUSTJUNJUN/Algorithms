

#include <stdio.h>
#include <string.h>


typedef struct tnode    tree_node;
struct tnode {
    int         node_value;
    tree_node   *left_node;
    tree_node   *right_node;
};


#define MAX_BINARYTREE_NODE 30
tree_node binary_tree_array[MAX_BINARYTREE_NODE];


typedef struct {
    tree_node   *tree;
    int         *size;
} ArrayBinaryTree;


/* Create Array Binary Tree */
ArrayBinaryTree *
new_array_binary_tree(tree_node *node, int size)
{
    ArrayBinaryTree *new = (ArrayBinaryTree *)malloc(sizeof(ArrayBinaryTree));
    new->tree = malloc(sizeof(tree_node) * size);
    new->size = size;

    return new;
}


/* Delete Array Binary Tree */
void
del_array_binary_tree(ArrayBinaryTree *abt)
{
    free(abt->tree);
    free(abt);

    return;
}


int
size_of_array_binary_tree(ArrayBinaryTree *abt)
{
    return (abt->size);
}


int
value_of_array_binary_tree_node(ArrayBinaryTree *abt, int idx)
{
    if (idx < 0 || idx >= size_of_array_binary_tree(abt)) {
        return __INT_MAX__;
    }

    return (abt->tree[idx].node_value);
}


int *
level_order_array_binary_tree(ArrayBinaryTree *abt, int *ret_size)
{
    int *res = (int *)malloc(sizeof(int) * size_of_array_binary_tree(abt));
    int index = 0;

    for (int i = 0; i < size_of_array_binary_tree(abt); i++) {
        if (value_of_array_binary_tree_node(abt, i) != __INT_MAX__) {
            res[index++] = value_of_array_binary_tree_node(abt, i);
        }
    }
    
    *ret_size = index;
    return res;
}


typedef enum order_type {
    pre,
    in,
    post,
} order_t;


int
left_index_of_tree_node(int idx)
{
    return (2 * idx + 1);
}


int
right_index_of_tree_node(int idx)
{
    return (2 * idx + 2);
}


void
dfs_order_array_binary_tree(ArrayBinaryTree *abt, int i, order_t type, int *idx, int *res)
{
    if (abt->tree[i].node_value == __INT_MAX__) {
        return;
    }

    if (type == pre) {
        res[*(idx)++] = abt->tree[i].node_value;
    }

    dfs_order_array_binary_tree(abt, left_index_of_tree_node(i), type, idx, res);

    if (type == in) {
        res[*(idx)++] = abt->tree[i].node_value;
    }

    dfs_order_array_binary_tree(abt, right_index_of_tree_node(i), type, idx, res);

    if (type == post) {
        res[*(idx)++] = abt->tree[i].node_value;
    }

    return;
}


int *
pre_order_array_binary_tree(ArrayBinaryTree *abt, int *ret_size)
{
    int *res = (int *)malloc(sizeof(int) * size_of_array_binary_tree(abt));
    int index = 0;

    dfs_order_array_binary_tree(abt, 0, pre, &index, res);

    *ret_size = index;
    return res;
}


int *
in_order_array_binary_tree(ArrayBinaryTree *abt, int *ret_size)
{
    int *res = (int *)malloc(sizeof(int) * size_of_array_binary_tree(abt));
    int index = 0;

    dfs_order_array_binary_tree(abt, 0, in, &index, res);

    *ret_size = index;
    return res;
}


int *
post_order_array_binary_tree(ArrayBinaryTree *abt, int *ret_size)
{
    int *res = (int *)malloc(sizeof(int) * size_of_array_binary_tree(abt));
    int index = 0;

    dfs_order_array_binary_tree(abt, 0, post, &index, res);

    *ret_size = index;
    return res;
}


int
main(int argc, char const *argv[])
{
    return 0;
}