#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char data;
    struct node *left, *right, *next;
};

struct node *top = NULL;

struct node *createNode(char data);
void Inorder(struct node *node);
void Preorder(struct node *node);
void Postorder(struct node *node);
void push(struct node *root);
struct node *pop();

int main()
{
    struct node *p, *q, *root;

    int n;
    printf("Enter length of expression : ");
    scanf("%d", &n);

    char s[n];
    printf("Enter the expression : ");
    scanf("%s", s);

    for (int i = 0; i < n; i++)
    {

        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')
        {
            root = createNode(s[i]);
            p = pop();
            q = pop();
            root->left = q;
            root->right = p;
            push(root);
        }
        else
        {
            root = createNode(s[i]);
            push(root);
        }
    }

    printf("\nInorder expression : ");
    Inorder(root);
    printf("\nPostorder expression : ");
    Postorder(root);
    printf("\nPreorder expression : ");
    Preorder(root);

    return 0;
}

struct node *createNode(char data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));

    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->next = NULL;

    return (node);
}

void Inorder(struct node *node)
{
    if (node == NULL)
    {
        return;
    }

    Inorder(node->left);
    printf("%c ", node->data);
    Inorder(node->right);
}

void Preorder(struct node *node)
{
    if (node == NULL)
    {
        return;
    }

    printf("%c ", node->data);
    Preorder(node->left);
    Preorder(node->right);
}

void Postorder(struct node *node)
{
    if (node == NULL)
    {
        return;
    }

    Postorder(node->left);
    Postorder(node->right);
    printf("%c ", node->data);
}

void push(struct node *root)
{
    if (top == NULL)
        top = root;
    else
    {
        root->next = top;
        top = root;
    }
}

struct node *pop()
{

    struct node *p = top;
    top = top->next;
    return p;
}
