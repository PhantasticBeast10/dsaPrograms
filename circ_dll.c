#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* start = NULL;

void insert_at_beg();
void insert_at_end();
void insert_after();
void delete_beg();
void delete_end();
void delete_el();
void traverse();
void search();

int main()
{
    int c = 0;
    while(c != 9)
    {
        printf("\n1. Insert at beginning"
               "\n2. Insert at end"
               "\n3. Insert after an element"
               "\n4. Delete from beginning"
               "\n5. Delete from end"
               "\n6. Delete an element"
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
            insert_after();
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
            delete_el();
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
            printf("\nInvalid input! Try again\n");
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
        start = t;
        t->next = start;
        t->prev = start;
        return;
    }
    t->next = start;
    t->prev = start->prev;
    start->prev->next = t;
    start->prev = t;
    start = t;
}

void insert_at_end()
{
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter data: ");
    scanf("%d", &(t->data));
    if(start == NULL)
    {
        start = t;
        t->next = start;
        t->prev = start;
        return;
    }
    t->next = start;
    t->prev = start->prev;
    start->prev->next = t;
    start->prev = t;
}

void insert_after()
{
    if(start == NULL)
    {
        printf("\nList Empty!\n");
        return;
    }
    int el;
    printf("\nEnter the element after which data is to be inserted: ");
    scanf("%d", &el);
    struct Node* cur = (struct Node*)malloc(sizeof(struct Node));
    cur = start;
    while(cur->next != start)
    {
        if(cur->data == el)
        {
            struct Node* t = (struct Node*)malloc(sizeof(struct Node));
            printf("\nEnter data: ");
            scanf("%d", &(t->data));
            t->next = cur->next;
            t->prev = cur;
            cur->next->prev = t;
            cur->next = t;
            return;
        }
        cur = cur->next;
    }
    if(cur->data == el)
    {
        struct Node* t = (struct Node*)malloc(sizeof(struct Node));
        printf("\nEnter data: ");
        scanf("%d", &(t->data));
        t->next = cur->next;
        t->prev = cur;
        cur->next->prev = t;
        cur->next = t;
        return;
    }
    printf("\nElement not found!\n");
}

void delete_beg()
{
    if(start == NULL)
    {
        printf("\nList Empty!\n");
        return;
    }
    if(start->next == start)
    {
        printf("\nDeleted Element: %d\n", start->data);
        free(start);
        start = NULL;
        return;
    }
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    t = start;
    t->prev->next = t->next;
    t->next->prev = t->prev;
    printf("\nDeleted Element: %d\n", start->data);
    start = t->next;
    free(t);
}

void delete_end()
{
    if(start == NULL)
    {
        printf("\nList Empty!\n");
        return;
    }
    if(start->next == start)
    {
        printf("\nDeleted Element: %d\n", start->data);
        free(start);
        start = NULL;
        return;
    }
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    t = start->prev;
    t->prev->next = t->next;
    t->next->prev = t->prev;
    printf("\nDeleted Element: %d\n", t->data);
    free(t);
}

void delete_el()
{
    int el;
    printf("\nEnter the data to be deleted: ");
    scanf("%d", &el);
    if(start == NULL)
    {
        printf("\nList Empty!\n");
        return;
    }
    if(start->data == el)
    {
       delete_beg();
       return;
    }
    struct Node* cur = (struct Node*)malloc(sizeof(struct Node));
    cur = start;
    while(cur->next != start)
    {
        if(cur->next->data == el)
        {
            struct Node* t = (struct Node*)malloc(sizeof(struct Node));
            t = cur->next;
            cur->next = t->next;
            t->next->prev = cur;
            printf("\nDeleted Element: %d\n", t->data);
            free(t);
            return;
        }
        cur = cur->next;
    }
    printf("\nElement does not exist!\n");
}

void search()
{
    int el;
    printf("\nEnter the data to be searched: ");
    scanf("%d", &el);
    if(start == NULL)
    {
        printf("\nList Empty!\n");
        return;
    }
    if(start->data == el)
    {
       printf("\nData Found!\n");
       return;
    }
    struct Node* cur = (struct Node*)malloc(sizeof(struct Node));
    cur = start;
    while(cur->next != start)
    {
        if(cur->next->data == el)
        {
            printf("\nData Found!\n");
            return;
        }
        cur = cur->next;
    }
    printf("\nData Not Found!\n");
}

void traverse()
{
    if(start == NULL)
    {
        printf("\nList Empty!\n");
        return;
    }
    printf("\nPrinting Elements...\n");
    struct Node* cur = (struct Node*)malloc(sizeof(struct Node));
    cur = start;
    while(cur->next != start)
    {
        printf("%d\t", cur->data);
        cur = cur->next;
    }
    printf("%d\n", cur->data);
}