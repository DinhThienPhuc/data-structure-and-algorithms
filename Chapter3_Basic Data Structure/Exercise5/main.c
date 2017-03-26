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

LIST *OddPositionList(LIST *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    head = head->next;
    LIST *curr = head;
    while (curr != NULL)
    {
        curr->next = curr->next->next;
        curr = curr->next;
    }
    return head;
}

void main()
{
    LIST *head = NULL;
    for (int i = 0; i < 9; i++)
    {
        head = insertFirst(head, rand() / 100000000);
        print(head);
    }

    head = OddPositionList(head);
    printf("After remove numbers in odd position:\n");
    print(head);
}