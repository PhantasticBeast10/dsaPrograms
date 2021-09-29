#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push();
void pop();
void display();

void main()
{
    int run = 0;
    while(run != 4)
    {
        printf("\n1. Push"
               "\n2. Pop"
               "\n3. Display"
               "\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &run);
        if(run == 1)
        {
            push();
        }
        else if(run == 2)
        {
            pop();
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

void push()
{
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter the data: ");
    scanf("%d", &(t->data));
    t->next = NULL;
    if(top == NULL)
    {
        top = t;
        return;
    }
    struct Node* cur = (struct Node*)malloc(sizeof(struct Node));
    cur = top;
    while(cur->next != NULL)
    {
        cur = cur->next;
    } 
    cur->next = t;
}

void pop()
{
    if(top == NULL)
    {
        printf("\nStack Underflow!\n");
        return;
    }
    if(top->next == NULL)
    {
        printf("\nDeleted element: %d\n", top->data);
        free(top);
        top = NULL;
        return;
    }
    struct Node* cur = (struct Node*)malloc(sizeof(struct Node));
    cur = top;
    while(cur->next->next != NULL)
    {
        cur = cur->next;
    }
    printf("\nDeleted Element: %d\n", cur->next->data);
    free(cur->next);
    cur->next = NULL;
}

void display()
{
    if(top == NULL)
    {
        printf("\nStack Empty!\n");
        return;
    }
    printf("\nStack:\n");
    struct Node* cur = (struct Node*)malloc(sizeof(struct Node));
    cur = top;
    while(cur != NULL)
    {
        printf("%d\t", cur->data);
        cur = cur->next;
    }
    printf("\n");
}