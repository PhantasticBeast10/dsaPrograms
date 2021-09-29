#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
};

struct Node *start = NULL;

void insert();
void delete (struct Node *cur, struct Node *prev, int el);
void search();
void traverse();
void inorder(struct Node *root);
void preorder(struct Node *root);
void postorder(struct Node *root);
void levelorder(struct Node *root);
struct Node *findMin(struct Node *cur);
struct Node *findMax(struct Node *cur);

int main()
{
    int c = 1;
    while (c != 5)
    {
        printf("\n1. Insert\n"
               "2. Delete\n"
               "3. Search\n"
               "4. Traverse\n"
               "5. Exit\n"
               "Which Operation do you wish to Perform?\n");
        scanf("%d", &c);
        if (c == 1)
        {
            insert();
        }
        else if (c == 2)
        {
            if (start != NULL)
            {
                int el;
                printf("\nEnter element to be deleted: ");
                scanf("%d", &el);
                delete (start, start, el);
            }
            else
            {
                printf("\nTree Empty!\n");
            }
        }
        else if (c == 3)
        {
            search();
        }
        else if (c == 4)
        {
            traverse();
        }
        else if (c != 5)
        {
            printf("Invalid Input! Try again...");
        }
    }
}

void insert()
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter data to be inserted: ");
    scanf("%d", &(t->data));
    t->right = NULL;
    t->left = NULL;
    if (start == NULL)
    {
        start = t;
        return;
    }
    struct Node *cur = (struct Node *)malloc(sizeof(struct Node));
    cur = start;
    while (1)
    {
        if (t->data > cur->data)
        {
            if (cur->right != NULL)
            {
                cur = cur->right;
            }
            else
            {
                cur->right = t;
                break;
            }
        }
        else
        {
            if (cur->left != NULL)
            {
                cur = cur->left;
            }
            else
            {
                cur->left = t;
                break;
            }
        }
    }
}

void delete (struct Node *cur, struct Node *prev, int el)
{
    if (cur == NULL)
    {
        printf("\nElement Not in the Tree!\n");
        return;
    }
    if (el < cur->data)
    {
        delete (cur->left, cur, el);
    }
    else if (el > cur->data)
    {
        delete (cur->right, cur, el);
    }
    else if (cur->right != NULL && cur->left != NULL)
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp = findMax(cur->left);
        cur->data = temp->data;
        delete (cur->left, cur, temp->data);
    }
    else
    {
        if (cur->left == NULL && cur->right == NULL)
        {
            if (cur == start)
            {
                free(start);
                start = NULL;
            }
            else if (prev->left == cur)
            {
                free(prev->left);
                prev->left = NULL;
            }
            else
            {
                free(prev->right);
                prev->right = NULL;
            }
        }
        else if (cur->left != NULL)
        {
            struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
            temp = findMax(cur->left);
            cur->data = temp->data;
            delete(cur->left, cur, temp->data);
        }
        else
        {
            printf("1");
            struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
            temp = findMin(cur->right);
            cur->data = temp->data;
            delete(cur->right, cur, temp->data);
        }
    }
}

void search()
{
    int el;
    printf("\nEnter element to be searched: ");
    scanf("%d", &el);
    struct Node *cur = (struct Node *)malloc(sizeof(struct Node));
    cur = start;
    while(1)
    {
        if(cur == NULL)
        {
            printf("\nElement Not Found!\n");
            return;
        }
        if(cur->data == el)
        {
            printf("\nElement Found!\n");
            return;
        }
        if(cur->data < el)
        {
            cur = cur->right;
        }
        else
        {
            cur = cur->left;
        }
    }
}

void traverse()
{
    if (start == NULL)
    {
        printf("\nTree Empty!\n");
        return;
    }
    printf("\nInorder Traversal...\n");
    inorder(start);
    printf("\nPreorder Traversal...\n");
    preorder(start);
    printf("\nPostorder Traversal...\n");
    postorder(start);
    printf("\nLevel-order Traversal...\n");
    levelorder(start);
    printf("\n");
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        inorder(root->left);
        inorder(root->right);
    }
}

void postorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        inorder(root->right);
        printf("%d ", root->data);
    }
}

void printLevel(struct Node *root, int level)
{
    if(root == NULL)
    {
        return;
    }
    if(level == 1)
    {
        printf("%d ", root->data);
    }
    else
    {
        printLevel(root->left, level-1);
        printLevel(root->right, level-1);
    }
}

int height(struct Node *node)
{
    if(node == NULL)
    {
        return 0;
    }
    else
    {
        int l = height(node->left);
        int r = height(node->right);

        if(l > r)
        {
            return(l+1);
        }
        else
        {
            return(r+1);
        }
    }
}

void levelorder(struct Node *root)
{
    int h = height(root);
    for(int i=1; i<=h; i++)
    {
        printLevel(root, i);
    }
}

struct Node *findMin(struct Node *cur)
{
    while (cur->left != NULL)
    {
        cur = cur->left;
    }
    return cur;
}

struct Node *findMax(struct Node *cur)
{
    while (cur->right != NULL)
    {
        cur = cur->right;
    }
    return cur;
}