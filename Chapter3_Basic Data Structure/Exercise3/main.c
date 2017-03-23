#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
} LIST;

LIST *insertFirst(LIST *h, int data)
{
    LIST *newNode = (LIST *)malloc(sizeof(LIST));
    newNode->data = data;
    if (h == NULL)
    {
        newNode->next = NULL;
    }
    else
    {
        newNode->next = h;
    }
    h = newNode;
    return h;
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

int countEvens = 0;
int countOdds = 0;
void OddEven(LIST *h)
{

    if (h == NULL)
    {
        return;
    }
    LIST *curr = h;
    while (curr != NULL)
    {
        if (curr->data % 2 == 0)
        {
            countEvens++;
        }
        else
        {
            countOdds++;
        }
        curr = curr->next;
    }
}

void main()
{
    LIST *head = NULL;
    for (int i = 0; i < 14; i++)
    {
        head = insertFirst(head, rand() / 100000000);
        print(head);
    }

    OddEven(head);
    printf("Number of Evens: %d\n", countEvens);
    printf("Number of Odds: %d\n", countOdds);
}