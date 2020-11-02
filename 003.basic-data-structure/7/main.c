#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
} LIST;

LIST *insertFirst(LIST *head, int data)
{
    LIST *newNode = (LIST *)malloc(sizeof(LIST));
    newNode->data = data;
    if (head == NULL)
    {
        newNode->next = NULL;
    }
    else
    {
        newNode->next = head;
    }
    head = newNode;
    return head;
}

LIST *removeDuple(LIST *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    LIST *curr = head->next;
    LIST *prev = head;
    while (curr != NULL)
    {
        if (curr->data == prev->data)
        {
            prev->next = curr->next;
        }
        else
        {
            prev = curr;
        }
        curr = curr->next;
    }
    return head;
}

void print(LIST *head)
{
    if (head != NULL)
    {
        printf("Linked List: [ ");
        LIST *i = head;
        while (i != NULL)
        {
            printf("%d ", i->data);
            i = i->next;
        }
        printf("]\n");
    }
    else
    {
        printf("Linked List is Empty\n");
    }
}

void main()
{
    LIST *head = NULL;

    head = insertFirst(head, 3);
    head = insertFirst(head, 3);
    head = insertFirst(head, 6);
    head = insertFirst(head, 7);
    head = insertFirst(head, 7);
    head = insertFirst(head, 7);
    head = insertFirst(head, 11);
    head = insertFirst(head, 13);
    head = insertFirst(head, 17);
    head = insertFirst(head, 17);

    print(head);
    head = removeDuple(head);
    print(head);
}