#include <stdio.h>

int n;

void merge(int* a, int p, int q, int r)
{
    int l1 = p, l2 = q+1, i = p;
    int b[n];
    while(l1 <= q && l2 <= r)
    {
        if(a[l1] < a[l2])
        {
            b[i++] = a[l1++];  
        }
        else
        {
            b[i++] = a[l2++];
        }
    }
    while(l1 <= q)
    {
        b[i++] = a[l1++];
    }
    while(l2 <= r)
    {
        b[i++] = a[l2++];
    }

    for(int i=p; i<=r; i++)
    {
        a[i] = b[i];
    }
}

void mergeSort(int* a, int p, int r)
{
    int q;
    if(p<r)
    {
        q = (p+r)/2;
        mergeSort(a, p, q);
        mergeSort(a, q+1, r);
        merge(a, p, q, r);
    }
    else
    {
        return;
    }
}

int main()
{
    printf("Enter the value of n: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the values of the array:\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\nBefore Sorting:\n");
    for(int i=0; i<n; i++)
    {
        printf("%d ", a[i]);
    }
    mergeSort(a, 0, n-1);
    printf("\nAfter Sorting:\n");
    for(int i=0; i<n; i++)
    {
        printf("%d ", a[i]);
    }
}
