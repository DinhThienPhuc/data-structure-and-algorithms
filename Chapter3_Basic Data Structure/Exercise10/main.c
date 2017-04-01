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

LIST *shuffle(LIST *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    int pos = 1;
    LIST *curr = head;
    LIST *oddHead = NULL;
    LIST *evenHead = NULL;
    LIST *prevOdd = NULL;
    LIST *prevEven = NULL;
    while (curr != NULL)
    {
        if (pos % 2 != 0)
        {
            if (oddHead == NULL)
            {
                oddHead = curr;
                prevOdd = oddHead;
            }
            else
            {
                prevOdd->next = curr;
                prevOdd = prevOdd->next;
            }
        }
        else
        {
            if (evenHead == NULL)
            {
                evenHead = curr;
                prevEven = evenHead;
            }
            else
            {
                prevEven->next = curr;
                prevEven = prevEven->next;
            }
        }
        pos++;
        curr = curr->next;
    }
    if (evenHead == NULL)
    {
        return oddHead;
    }
    prevEven->next = oddHead;
    printf("even head: %d & odd head: %d\n", evenHead->data, oddHead->data);
    printf("prev even: %d & prev odd: %d\n", prevEven->data, prevOdd->data);
    printf("prev even next: %d\n", evenHead->next->data);

    return evenHead;
    // return NULL;
}

void main()
{
    LIST *head = NULL;
    for (int i = 0; i < 8; i++)
    {
        head = insertFirst(head, rand() / 100000000);
    }
    print(head);
    head = shuffle(head);
    print(head);
    // shuffle(head);
}