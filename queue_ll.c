#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* start = NULL;

void enqueue();
void dequeue();
void display();

void main()
{
    int run = 0;
    while(run != 4)
    {
        printf("\n1. Enqueue"
               "\n2. Dequeue"
               "\n3. Display"
               "\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &run);
        if(run == 1)
        {
            enqueue();
        }
        else if(run == 2)
        {
            dequeue();
        }
        else if(run == 3)
        {
            display();
        }
        else if(run != 4)
        {
            printf("\nInvalid input!\n");
        }
    }
}

void enqueue()
{
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter the data: ");
    scanf("%d", &(t->data));
    t->next = NULL;
    if(start == NULL)
    {
        start = t;
        return;
    }
    struct Node* cur = (struct Node*)malloc(sizeof(struct Node));
    cur = start;
    while(cur->next != NULL)
    {
        cur = cur->next;
    } 
    cur->next = t;
}

void dequeue()
{
    if(start == NULL)
    {
        printf("\nUnderflow!\n");
        return;
    }
    struct Node* cur = (struct Node*)malloc(sizeof(struct Node));
    cur = start;
    start = start->next;
    printf("\nDeleted element: %d\n", cur->data);
    free(cur);
}

void display()
{
    if(start == NULL)
    {
        printf("\nStack Empty!\n");
        return;
    }
    printf("\nStack:\n");
    struct Node* cur = (struct Node*)malloc(sizeof(struct Node));
    cur = start;
    while(cur != NULL)
    {
        printf("%d\t", cur->data);
        cur = cur->next;
    }
    printf("\n");
}