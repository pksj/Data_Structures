#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tree_node
{
    int data;
    struct tree_node *left;
    struct tree_node *right;
} tree_node;

typedef struct stack_node
{
    tree_node *t_node;
    struct stack_node *next;
} stack_node;

stack_node *top_of_stack = NULL;

void push(tree_node *t_node)
{
    stack_node *new_node = (stack_node *)malloc(sizeof(stack_node));
    new_node->t_node = t_node;
    new_node->next = top_of_stack;
    top_of_stack = new_node;
}

void pop()
{
    if (top_of_stack != NULL)
    {
        stack_node *temp_node = top_of_stack;
        top_of_stack = top_of_stack->next;
        free(temp_node);
    }
}

tree_node *top() // to get top of stack
{
    return top_of_stack->t_node;
}

bool is_empty()
{
    return top_of_stack ? false : true;
}

tree_node *create_node(int data)
{
    tree_node *new_node = (tree_node *)malloc(sizeof(tree_node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void preorder_iteratively(tree_node *root)
{

    if (root == NULL)
    {
        return;
    }

    push(root);

    while (is_empty() != true)
    {
        tree_node *temp_node = top();
        pop();

        printf("%d ", temp_node->data);
        if (temp_node->right != NULL)
        {
            push(temp_node->right);
        }

        if (temp_node->left != NULL)
        {
            push(temp_node->left);
        }
    }
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

    printf("\n");
    preorder_iteratively(root);
    printf("\n");

    return 0;
}
