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

bool isLeaf(TreeNode *node)
{
    if (node->left == NULL && node->right == NULL)
        return true;
    return false;
}

bool isSame(TreeNode *node1, TreeNode *node2)
{
    if (isLeaf(node1) && isLeaf(node2))
        return true;
    if (!isLeaf(node1) && !isLeaf(node2))
        return true;
    return false;
}

bool isomorphous(TreeNode *tree1, TreeNode *tree2, bool f)
{
    bool flag = f;
    if (tree1 != NULL && tree2 != NULL)
    {
        if (!isSame(tree1, tree2))
            flag = false;
        isomorphous(tree1->left, tree2->left, flag);
        isomorphous(tree1->right, tree2->right, flag);
    }
    return flag;
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
    TreeNode *tree1 = NULL;
    TreeNode *tree2 = NULL;
    int num = 1;

    // Create the first tree with root name: tree1
    while (num != 0)
    {
        printf("\nEnter number (press '/' to finish): ");
        scanf("%d", &num);
        if (num == 0)
            printf("Stop process...\n");
        else
            tree1 = insert(tree1, num);
    }

    num = 1;
    // Second tree: tree2
    while (num != 0)
    {
        printf("\nEnter number (press '/' to finish): ");
        scanf("%d", &num);
        if (num == 0)
            printf("Stop process...\n");
        else
            tree2 = insert(tree2, num);
    }

    printf("Tree1 in preorder:\n");
    printPreorder(tree1);
    printf("\n**************************************\n");

    printf("Tree2 in preorder:\n");
    printPreorder(tree2);
    printf("\n**************************************\n");

    // printf("The Tree in inorder:\n");
    // printInorder(tree1);
    // printf("\n**************************************\n");

    // printf("The Tree in postorder:\n");
    // printPostorder(tree1);
    // printf("\n**************************************\n");

    bool isomorph = true;
    isomorph = isomorphous(tree1, tree2, isomorph);
    if(isomorph) printf("They are isomorphous!!!");
    else printf("They are NOT isomorphous :(((");
}