#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Polynom
{
    int base;
    int pow;
    struct Polynom *next;
} POLY;

POLY *insertFirst(POLY *head, int b, int p)
{
    POLY *newNode = (POLY *)malloc(sizeof(POLY));
    newNode->base = b;
    newNode->pow = p;
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

void addRest(POLY *previous, POLY *curr)
{
    while (curr != NULL)
    {
        POLY *newNode = (POLY *)malloc(sizeof(POLY));
        newNode->pow = curr->pow;
        newNode->base = curr->base;
        previous->next = newNode; //prev->next == current
        previous = previous->next;
        curr = curr->next;
    }
}

POLY *Sum(POLY *head_a, POLY *head_b)
{
    POLY *curr1 = head_a;
    POLY *curr2 = head_b;
    POLY *newHead = NULL;
    POLY *prev = NULL;
    while (curr1 != NULL && curr2 != NULL)
    {
        POLY *newNode = (POLY *)malloc(sizeof(POLY));
        if (curr1->pow > curr2->pow)
        {
            newNode->pow = curr1->pow;
            newNode->base = curr1->base;
            curr1 = curr1->next;
        }
        else if (curr1->pow < curr2->pow)
        {
            newNode->pow = curr2->pow;
            newNode->base = curr2->base;
            curr2 = curr2->next;
        }
        else
        {
            newNode->pow = curr1->pow;
            newNode->base = curr1->base + curr2->base;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        if (newHead == NULL)
        {
            newHead = newNode;
            prev = newHead;
        }
        else
        {
            prev->next = newNode;
            prev = prev->next;
        }
    }
    if (curr1 == NULL)
    {
        addRest(prev, curr2);
    }
    if (curr2 == NULL)
    {
        addRest(prev, curr1);
    }
    return newHead;
}

void print(POLY *head)
{
    if (head != NULL)
    {
        printf("Linked List: [ ");
        POLY *i = head;
        while (i != NULL)
        {
            printf("%dx^%d ", i->base, i->pow);
            i = i->next;
        }
        printf("]\n");
    }
    else
    {
        printf("Polynom is Empty\n");
    }
}

void main()
{
    POLY *head1 = NULL;
    POLY *head2 = NULL;

    for (int i = 6; i < 9; i++)
    {
        head1 = insertFirst(head1, rand() % 20, i);
    }

    for (int i = 1; i < 13; i += 2)
    {
        head2 = insertFirst(head2, rand() % 20, i);
    }

    print(head1);
    print(head2);

    POLY *head3 = Sum(head1, head2);
    print(head3);
}