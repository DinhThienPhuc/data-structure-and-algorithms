#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include <process.h>

typedef struct node
{
    char word[20];
    struct node *left;
    struct node *right;
} TreeNode;

TreeNode *createTreeNode(char *word)
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
    strcpy(newNode->word, word);

    return newNode;
}

TreeNode *randomInsert(TreeNode *tree, char *word)
{
    TreeNode *p;
    TreeNode *newNode = createTreeNode(word);
    if (tree == NULL)
        return newNode;
    if (random() % 2 == 0)
    {
        p = tree;
        while (p->left != NULL)
            p = p->left;
        p->left = newNode;
        printf("Node %s is left child of %s\n", p->left->word, p->word);
    }
    else
    {
        p = tree;
        while (p->right != NULL)
            p = p->right;
        p->right = newNode;
        printf("Node %s is right child of %s\n", word, (*p).word);
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

void printPreorder(TreeNode *tree)
{
    if (tree != NULL)
    {
        printf("%s ", tree->word);
        printPreorder(tree->left);
        printPreorder(tree->right);
    }
}

void printInorder(TreeNode *tree)
{
    if (tree != NULL)
    {
        printInorder(tree->left);
        printf("%s ", tree->word);
        printInorder(tree->right);
    }
}

void printPostorder(TreeNode *tree)
{
    if (tree != NULL)
    {
        printPostorder(tree->left);
        printPostorder(tree->right);
        printf("%s ", tree->word);
    }
}

int main()
{
    TreeNode *tree = NULL;
    char word[20] = "a";
    while (strcmp(word, "/") != 0)
    {
        printf("\nEnter word (press '/' to finish): ");
        scanf("%s", word);
        if (strcmp(word, "/") == 0)
            printf("Stop process...\n");
        else
            tree = randomInsert(tree, word);
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
}