#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct LIST *next;
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

LIST *OddList(LIST *h)
{
    while (h != NULL && h->data % 2 == 0)
    {
        h = h->next;
    }
    if (h == NULL)
    {
        return NULL;
    }
    else
    {
        LIST *curr = h;
        LIST *prev = NULL;
        while (curr != NULL)
        {
            if (curr->data % 2 == 0)
            {
                prev->next = curr->next;
            }
            else
            {
                prev = curr;
            }
            curr = curr->next;
        }
    }
    return h;
}

void main()
{
    LIST *head = NULL;
    for (int i = 0; i < 14; i++)
    {
        head = insertFirst(head, rand() / 100000000);
        print(head);
    }

    head = OddList(head);
    printf("After remove even numbers:\n");
    print(head);
}