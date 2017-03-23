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

int Multi(POLY *head1, POLY *head2)
{
    return head1->pow + head2->pow;
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

    int x = Multi(head1, head2);
    printf("%d\n", x);
}