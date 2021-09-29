#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define n 8

struct Edge
{
    int src;
    int dest;
    //int weight;
};

struct Node
{
    int data;
    int dest;
    int w;
    struct Node *next;
};

struct Node *start[n];

void createGraph(struct Edge edges[], int w[], int p)
{
    for(int i=0; i<n; i++)
    {
        start[i] = NULL;
    }

    for(int i=0; i<p; i++)
    {
        struct Node *t = (struct Node *)malloc(sizeof(struct Node));
        int src = edges[i].src;
        t->data = src;
        t->dest = edges[i].dest;
        t->w = w[i];
        t->next = NULL;
        if(start[src-1] == NULL)
        {
            start[src-1] = t;
        }
        else
        {
            struct Node *cur = (struct Node *)malloc(sizeof(struct Node));
            cur = start[src-1];
            while(cur->next != NULL)
            {
                cur = cur->next;
            }
            cur->next = t;
        }

    }
}

void printGraph()
{
    for(int i=0; i<n; i++)
    {
        struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
        ptr = start[i];
        while(ptr != NULL)
        {
            printf("(%d->%d)(%d)\t", ptr->data, ptr->dest, ptr->w);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

void prims()
{
    int a;
    int k[n], visited[n], w[n];
    struct Node *pi[n];
    printf("\nEnter source vertex: ");
    scanf("%d", &a);
    int mst[n];
    int ptr = 0;
    for(int i=0; i<n; i++)
    {
        if(i+1 != a)
        {
            k[i] = 10000;
            visited[i] = 0;
        }
        else
        {
            k[i] = 0;
            visited[i] = 1;
        }
        pi[i] = start[i];
    }
    struct Node *v = (struct Node *)malloc(sizeof(struct Node));
    mst[0] = a;
    ptr++;
    int sum = 0;
    v = start[a-1];
    while(ptr<n-1)
    {
        while(v != NULL)
        {
            if(k[v->dest - 1] > v->w && visited[v->dest - 1] == 0)
            {
                k[v->dest - 1] = v->w;
                pi[v->dest - 1] = start[v->data - 1];
            }
            v = v->next;
        }
        int min = 10000;
        int idx;
        for(int i=0; i<n; i++)
        {
            if(k[i] < min && visited[i] == 0)
            {
                min = k[i];
                idx = i;
            }
        }
        sum += min;
        visited[idx] = 1;
        mst[ptr] = idx+1;
        ptr++;
        v = start[idx];
    }

    printf("\nMST:\n");
    for(int i=0; i<n-2; i++)
    {
        printf("%d, ", mst[i]);
    }
    printf("%d", mst[n-2]);

    printf("\n\nEdges included:\n");
    for(int i=0; i<n-1; i++)
    {
        if(mst[i] != a)
        {
            printf("%d--%d\n", pi[mst[i]-1]->data, mst[i]);
        }
    }

    printf("\nTotal Cost Of Spanning Tree: %d\n", sum);
}

int main()
{
    struct Edge edges[] = {{1, 2}, {1, 3}, {2, 1}, {2, 4}, {2, 7}, {3, 1}, {3, 6}, {4, 2}, {4, 5}, {4, 7}, {5, 4}, {5, 6}, {6, 3}, {6, 5}, {6, 7}, {7, 2}, {7, 4}, {7, 6}};
    int w[] = {1, 5, 1, 4, 2, 5, 2, 4, 7, 3, 7, 5, 2, 5, 6, 2, 3, 6};
    int p = sizeof(w)/sizeof(int);
    createGraph(edges, w, p);
    printf("ADJACENCY LIST:\n");
    printGraph();
    prims();
}