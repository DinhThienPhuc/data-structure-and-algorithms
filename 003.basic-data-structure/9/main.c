#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} DLIST;

DLIST *insertFirst(DLIST *head, int value)
{
    DLIST *newNode = (DLIST *)malloc(sizeof(DLIST));
    newNode->data = value;
    if (head != NULL)
    {
        newNode->next = head;
        head->prev = newNode;
    }
    head = newNode;
    return head;
}

DLIST *deleteNode(DLIST *head, DLIST *node)
{
    if (node == head)
    {
        return head->next;
    }
    if (node->next == NULL)
    {
        node->prev->next = NULL;
        node->prev = NULL;
        return head;
    }
    node->prev->next = node->next;
    node->next->prev = node->prev;
    return head;
}

DLIST *removeDefinedNode(DLIST *head, int key)
{
    if (head == NULL)
    {
        printf("Double Linked List has no elements!\n");
        return NULL;
    }
    DLIST *curr = head;
    DLIST *newHead = head;
    while (curr != NULL)
    {
        if (curr->data == key)
        {
            newHead = deleteNode(newHead, curr);
        }
        curr = curr->next;
    }
    return newHead;
}

void print(DLIST *head)
{
    if (head != NULL)
    {
        printf("Double Linked List: [ ");
        DLIST *i = head;
        while (i != NULL)
        {
            printf("%d ", i->data);
            i = i->next;
        }
        printf("]\n");
    }
    else
    {
        printf("Double Linked List is Empty\n");
    }
}

void main()
{
    DLIST *head = NULL;
    DLIST *tail = NULL;

    head = insertFirst(head, 1);
    tail = head;
    head = insertFirst(head, 7);
    head = insertFirst(head, 4);
    head = insertFirst(head, 7);
    head = insertFirst(head, 9);
    head = insertFirst(head, 11);
    head = insertFirst(head, 7);
    head = insertFirst(head, 13);
    head = insertFirst(head, 4);
    head = insertFirst(head, 1);
    head = insertFirst(head, 6);
    head = insertFirst(head, 9);
    head = insertFirst(head, 6);
    head = insertFirst(head, 6);
    printf("Originaritie ");
    print(head);
    head = removeDefinedNode(head, 6);
    printf("After remove ");
    print(head);
}