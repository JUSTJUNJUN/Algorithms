

#include <stdio.h>
#include <string.h>


typedef struct tnode    tree_node;

struct tnode {
    int         node_value;
    int         tree_height;
    tree_node   *left_node;
    tree_node   *right_node;
};


/* Create a avl tree node */
tree_node *
new_avl_tree_node(int val)
{
    tree_node *new = NULL;

    new = (tree_node *)malloc(sizeof(tree_node));
    if (!new) {
        return NULL;
    }

    new->node_value = val;
    new->tree_height = 0;
    new->left_node = NULL;
    new->right_node = NULL;

    return new;
}


/* Get avl tree node height */
int
height_of_avl_tree_node(tree_node *node)
{
    if (node != NULL) {
        return node->tree_height;
    }

    return -1;
}


/* Update avl tree node height */
void
update_height_of_avl_tree_node(tree_node *node)
{
    if (!node) {
        return;
    }
    
    int left_height = height_of_avl_tree_node(node->left_node);
    int right_height = height_of_avl_tree_node(node->right_node);

    if (left_height > right_height) {
        node->tree_height = left_height + 1;
    } else {
        node->tree_height = right_height + 1;
    }

    return;
}


/* Get avl tree node balance factor */
int
balance_factor_of_avl_tree_node(tree_node *node)
{
    if (!node) {
        return 0;
    }

    return height_of_avl_tree_node(node->left_node) - height_of_avl_tree_node(node->right_node);
}


/* Right rotate */
tree_node *
right_rotate_avl_tree(tree_node *node)
{
    if (!node) {
        return;
    }

    tree_node *child = NULL, *grand_child = NULL;

    child = node->left_node;
    grand_child = child->right_node;

    child->right_node = node;
    node->left_node = grand_child;

    update_height_of_avl_tree_node(node);
    update_height_of_avl_tree_node(child);

    return child;
}


/* Left rotate */
tree_node *
left_rotate_avl_tree(tree_node *node)
{
    if (!node) {
        return;
    }

    tree_node *child = NULL, *grand_child = NULL;

    child = node->right_node;
    grand_child = child->left_node;

    child->left_node = node;
    node->right_node = grand_child;

    update_height_of_avl_tree_node(node);
    update_height_of_avl_tree_node(child);

    return child;
}


/* Todo: should handle grand child node is null */


/* Rotate according to balance factor */
tree_node *
rotate_tree_node_factor(tree_node *node)
{
    int bf = balance_factor_of_avl_tree_node(node);
    
    if (bf > 1) {
        if (balance_factor_of_avl_tree_node(node->left_node) >= 0) {
            return right_rotate_avl_tree(node);
        } else {
            node->left_node = left_rotate_avl_tree(node->left_node);
            return right_rotate_avl_tree(node);
        }
    }

    if (bf < -1) {
        if (balance_factor_of_avl_tree_node(node->right_node) <= 0) {
            return left_rotate_avl_tree(node);
        } else {
            node->right_node = right_rotate_avl_tree(node->right_node);
            return left_rotate_avl_tree(node);
        }
    }

    return node;
}


/* Insert new avl tree node */
tree_node *
insert_node_into_avl_tree(tree_node *root, int val)
{
    if (!root) {
        return new_avl_tree_node(val);
    }

    if (root->node_value > val) {
        root->left_node = insert_node_into_avl_tree(root->left_node, val);
    } else if (root->node_value < val) {
        root->right_node = insert_node_into_avl_tree(root->right_node, val);
    } else {
        return root;
    }

    update_height_of_avl_tree_node(root);
    root = rotate_tree_node_factor(root);

    return root;
}


/* Delete a avl tree node */
tree_node *
delete_node_off_avl_tree(tree_node *root, int val)
{
    if (!root) {
        return NULL;
    }

    tree_node *child = NULL, *grand_child = NULL;

    if (root->node_value > val) {
        root->left_node = delete_node_off_avl_tree(root->left_node, val);
    } else if (root->node_value < val) {
        root->right_node = delete_node_off_avl_tree(root->right_node, val);
    } else {
        if (root->left_node == NULL || root->right_node == NULL) {
            child = root->left_node == NULL? root->right_node : root->left_node;
            if (child == NULL) {
                return NULL;
            } else {
                root = child;
            }
        } else {
            tree_node *tmp = root->right_node;
            while (tmp->left_node != NULL) {
                tmp = tmp->left_node;
            }
            int tmp_val = tmp->node_value;
            root->right_node = delete_node_off_avl_tree(root->right_node, tmp_val);
            root->node_value = tmp_val;
        }
    }

    update_height_of_avl_tree_node(root);
    root = rotate_tree_node_factor(root);

    return root;
}


int main(int argc, char const *argv[])
{
    return 0;
}


