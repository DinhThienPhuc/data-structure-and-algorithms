#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
// #include <process.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} TreeNode;

TreeNode *createTreeNode(int data)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    if (newNode == NULL)
    {
        printf("Out of memory!!!\n");
        exit(1);
        return NULL;
    }
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = data;

    return newNode;
}

TreeNode *insert(TreeNode *tree, int data)
{
    TreeNode *newNode = createTreeNode(data);
    if (tree == NULL)
        return newNode;
    TreeNode *p = tree;

    if (random() % 2 == 0)
    {
        while (p->left != NULL)
            p = p->left;
        if (p->right == NULL)
        {
            p->right = newNode;
            printf("Node %d is right child of %d\n", newNode->data, p->data);
        }
        else if (p->left == NULL)
        {
            p->left = newNode;
            printf("Node %d is left child of %d\n", newNode->data, p->data);
        }
    }
    else
    {
        while (p->right != NULL)
            p = p->right;
        if (p->left == NULL)
        {
            p->left = newNode;
            printf("Node %d is left child of %d\n", newNode->data, p->data);
        }
        else if (p->right == NULL)
        {
            p->right = newNode;
            printf("Node %d is right child of %d\n", newNode->data, p->data);
        }
    }
    return tree;
}

int countNodes(TreeNode *tree)
{
    if (tree == NULL)
        return 0;
    int leftNodes = countNodes(tree->left);
    int rightNodes = countNodes(tree->right);
    return 1 + leftNodes + rightNodes;
}

int countDepth(TreeNode *tree)
{
    if (tree == NULL)
        return 0;
    int leftDepth = countDepth(tree->left);
    int rightDepth = countDepth(tree->right);
    if (leftDepth > rightDepth)
        return 1 + leftDepth;
    else
        return 1 + rightDepth;
}

void freeTree(TreeNode *tree)
{
    if (tree == NULL)
        return;
    freeTree(tree->left);
    freeTree(tree->right);
    free(tree);
    return;
}

// Count the number of node with data is greater than k
int calculate(TreeNode *tree, int numberOfNode, int k)
{
    int count = numberOfNode;
    if (tree != NULL)
    {
        if (tree->data > k)
        {
            printf("value: %d\n", tree->data);
            count++;
        }
        count = calculate(tree->left, count, k);
        count = calculate(tree->right, count, k);
    }
    return count;
}

void printPreorder(TreeNode *tree)
{
    if (tree != NULL)
    {
        printf("%d ", tree->data);
        printPreorder(tree->left);
        printPreorder(tree->right);
    }
}

void printInorder(TreeNode *tree)
{
    if (tree != NULL)
    {
        if (tree->left != NULL)
        {
            printInorder(tree->left);
            printf("%d ", tree->data);
            printInorder(tree->right);
        }
        else
        {
            printInorder(tree->right);
            printf("%d ", tree->data);
        }
    }
}

void printPostorder(TreeNode *tree)
{
    if (tree != NULL)
    {
        printPostorder(tree->left);
        printPostorder(tree->right);
        printf("%d ", tree->data);
    }
}

int main()
{
    TreeNode *tree = NULL;
    int num = 1;
    while (num != 0)
    {
        printf("\nEnter number (press '/' to finish): ");
        scanf("%d", &num);
        if (num == 0)
            printf("Stop process...\n");
        else
            tree = insert(tree, num);
    }

    printf("The Tree in preorder:\n");
    printPreorder(tree);
    printf("\n**************************************\n");

    printf("The Tree in inorder:\n");
    printInorder(tree);
    printf("\n**************************************\n");

    printf("The Tree in postorder:\n");
    printPostorder(tree);
    printf("\n**************************************\n");

    int numberNodes = 0;
    int k = 7;
    numberNodes = calculate(tree, numberNodes, k);
    printf("Number of satified node(s): %d\n", numberNodes);
}