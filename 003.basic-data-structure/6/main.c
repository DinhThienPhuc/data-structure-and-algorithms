#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
} Circle;

Circle *tail = NULL;

void makeCircle(Circle *head, Circle *tail)
{
    tail->next = head;
}

Circle *insertFirst(Circle *head, int data)
{
    Circle *newNode = (Circle *)malloc(sizeof(Circle));
    newNode->data = data;
    if (head == NULL)
    {
        tail = newNode;
    }
    else
    {
        newNode->next = head;
    }
    head = newNode;
    makeCircle(head, tail);
    return head;
}

int countNodesInCircle(Circle *head)
{
    int numberOfNodes = 0;
    Circle *i = head;
    do
    {
        numberOfNodes++;
        i = i->next;
    } while (i != head);
    return numberOfNodes;
}

void print(Circle *head)
{
    if (head != NULL)
    {
        printf("Circle List: [ ");
        Circle *i = head;
        do
        {
            printf("%d ", i->data);
            i = i->next;
        } while (i != head);
        printf("]\n");
    }
    else
    {
        printf("Circle List is Empty\n");
    }
}

void main()
{
    Circle *head = NULL;
    for (int i = 0; i < 11; i++)
    {
        head = insertFirst(head, rand() / 100000000);
    }
    print(head);
    printf("Number of Node in Circle List: %d\n", countNodesInCircle(head));
}