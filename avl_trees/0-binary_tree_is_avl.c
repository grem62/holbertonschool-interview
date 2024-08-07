#include "binary_trees.h"
#include <limits.h>

int is_bst(const binary_tree_t *tree, int min, int max);
int is_avl(const binary_tree_t *tree);
int height(const binary_tree_t *tree);

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    /* Check if tree is a valid BST */
    if (!is_bst(tree, INT_MIN, INT_MAX))
        return (0);

    /* Check if tree is a valid AVL Tree */
    if (!is_avl(tree))
        return (0);

    return (1);
}

/**
 * is_bst - Checks if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree to check
 * @min: Minimum value allowed in the tree
 * @max: Maximum value allowed in the tree
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
    if (tree == NULL)
        return (1);

    if (tree->n < min || tree->n > max)
        return (0);

    return (is_bst(tree->left, min, tree->n - 1) &&
            is_bst(tree->right, tree->n + 1, max));
}

/**
 * is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int is_avl(const binary_tree_t *tree)
{
    int left_height, right_height, diff;

    if (tree == NULL)
        return (1);

    left_height = height(tree->left);
    right_height = height(tree->right);
    diff = left_height - right_height;

    if (diff > 1 || diff < -1)
        return (0);

    return (is_avl(tree->left) && is_avl(tree->right));
}

/**
 * height - Computes the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: The height of the tree
 */
int height(const binary_tree_t *tree)
{
    int left_height, right_height;

    if (tree == NULL)
        return (0);

    left_height = height(tree->left);
    right_height = height(tree->right);

    return (1 + (left_height > right_height ? left_height : right_height));
}
