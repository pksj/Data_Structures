#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node
{
    int data;
    struct tree_node *left;
    struct tree_node *right;
} tree_node;

tree_node *create_node(int data)
{
    tree_node *new_node = (tree_node *)malloc(sizeof(tree_node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void preorder(tree_node *root)
{

    if (root == NULL)
    {
        return;
    }

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(tree_node *root)
{

    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(tree_node *root)
{

    if (root == NULL)
    {
        return;
    }

    printf("%d ", root->data);
    postorder(root->left);
    postorder(root->right);
}

int main(int argc, char const *argv[])
{

    tree_node *root = create_node(7);
    root->left = create_node(5);
    root->right = create_node(9);
    root->left->left = create_node(4);
    root->left->right = create_node(6);
    root->right->left = create_node(8);
    root->right->right = create_node(10);

    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");

    return 0;
}
