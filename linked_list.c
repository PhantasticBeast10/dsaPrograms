#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

struct Node* start = NULL;

void insert_at_beg();
void insert_at_end();
void insert_at_ind();
void delete_beg();
void delete_end();
void delete_ind();
void traverse();
void search();

int main()
{
    int c = 0;
    while(c != 9)
    {
        printf("\n1. Insert at beginning"
               "\n2. Insert at end"
               "\n3. Insert at an index"
               "\n4. Delete from beginning"
               "\n5. Delete from end"
               "\n6. Delete from an index"
               "\n7. Display Linked List"
               "\n8. Search an element"
               "\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        if(c == 1)
        {
            insert_at_beg();
        }
        else if(c == 2)
        {
            insert_at_end();
        }
        else if(c == 3)
        {
            insert_at_ind();
        }
        else if(c == 4)
        {
            delete_beg();
        }
        else if(c == 5)
        {
            delete_end();
        }
        else if(c == 6)
        {
            delete_ind();
        }
        else if(c == 7)
        {
            traverse();
        }
        else if(c == 8)
        {
            search();
        }
        else if(c != 9)
        {
            printf("Invalid input! Try again\n");
        }
    }
}

void insert_at_beg()
{
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter data: ");
    scanf("%d", &(t->data));
    if(start == NULL)
    {
        t->next = NULL;
        start = t;
    }
    else
    {
        t->next = start;
        start = t;
    }
}

void insert_at_end()
{
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter data: ");
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

void insert_at_ind()
{
    int ind;
    printf("\nEnter the index at which you wish to insert node: ");
    scanf("%d", &ind);
    if(ind == 1)
    {
        insert_at_beg();
        return;
    }
    struct Node* cur = (struct Node*)malloc(sizeof(struct Node));
    cur = start;
    for(int i=2; i<ind; i++)
    {
        if(cur->next == NULL)
        {
            printf("\nLess elements!\n");
            return;
        }
        cur = cur->next;
    }
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter data: ");
    scanf("%d", &(t->data));
    t->next = cur->next;
    cur->next = t;
}

void delete_beg()
{
    if(start == NULL)
    {
        printf("\nList Empty!\n");
        return;
    }
    struct Node* cur = (struct Node*)malloc(sizeof(struct Node));
    cur = start;
    start = start->next;
    printf("\nDeleted element: %d\n", cur->data);
    free(cur);
}

void delete_end()
{
    if(start == NULL)
    {
        printf("\nList Empty!\n");
        return;
    }
    if(start->next == NULL)
    {
        printf("\nDeleted element: %d\n", start->data);
        free(start);
        start = NULL;
        return;
    }
    struct Node* cur = (struct Node*)malloc(sizeof(struct Node));
    cur = start;
    while(cur->next->next != NULL)
    {
        cur = cur->next;
    }
}

void delete_ind()
{
    int ind;
    printf("\nEnter the index of the node which you wish to delete: ");
    scanf("%d", &ind);
    if(ind == 1)
    {
        delete_beg();
        return;
    }
    struct Node* cur = (struct Node*)malloc(sizeof(struct Node));
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    cur = start;
    for(int i=2; i<ind; i++)
    {
        if(cur->next == NULL)
        {
            printf("\nThe given index does not exist!\n");
            return;
        }
        cur = cur->next;
    }
    t = cur->next;
    cur->next = t->next;
    printf("\nDeleted element: %d\n", t->data);
    free(t);
}

void traverse()
{
    if(start == NULL)
    {
        printf("\nList is Empty!\n");
        return;
    }

    printf("\nThe Linked List:\n");
    struct Node* cur = (struct Node*)malloc(sizeof(struct Node));
    cur = start;
    while(cur != NULL)
    {
        printf("%d\t", cur->data);
        cur = cur->next;
    }
    printf("\n");

}

void search()
{
    if(start == NULL)
    {
        printf("\nList is Empty!\n");
        return;
    }

    int ele;
    printf("\nEnter the element to be searched: ");
    scanf("%d", &ele);
    struct Node* cur = (struct Node*)malloc(sizeof(struct Node));
    cur = start;
    while(cur != NULL)
    {
        if(cur->data == ele)
        {
            printf("\nData Found!\n");
            return;
        }
        cur = cur->next;
    }
    printf("\nData Not Found!\n");
}