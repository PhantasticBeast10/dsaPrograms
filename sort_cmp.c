#include <stdio.h>
#include <string.h>

struct student
{
    int regno;
    char name[20];
    int yr;
};

void bubble_Sort(struct student s[], int n)
{
    int c = 0;
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            c++;
            if(s[j].regno > s[j+1].regno)
            {
                struct student temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }

    printf("\nBUBBLE SORT:");
    for(int i=0; i<n; i++)
    {
        printf("\n%d. %s\t\t%d\t%d", i+1, s[i].name, s[i].regno, s[i].yr);
    }
    printf("\nNo. of comparisons = %d\n", c);
}

void selection_Sort(struct student s[], int n)
{
    int c = 0;
    for(int i=0; i<n-1; i++)
    {
        int min_ind = i;
        for(int j = i+1; j<n; j++)
        {
            c++;
            if(s[j].regno > s[min_ind].regno)
            {
                min_ind = j;
                struct student temp = s[j];
                s[j] = s[min_ind];
                s[min_ind] = temp;
            }
        }
    }

    printf("\nSELECTION SORT:");
    for(int i=0; i<n; i++)
    {
        printf("\n%d. %s\t\t%d\t%d", i+1, s[i].name, s[i].regno, s[i].yr);
    }
    printf("\nNo. of comparisons = %d\n", c);
}

void insertion_Sort(struct student s[], int n)
{
    int c = 0;
    for(int i=1; i<n; i++)
    {
        struct student key = s[i];
        int j = i-1;
        while(j >= 0 && s[j].regno > key.regno)
        {
            c++;
            s[j+1] = s[j];
            j--;
        }
        c++;
        s[j+1] = key;
    }

    printf("\nINSERTION SORT:");
    for(int i=0; i<n; i++)
    {
        printf("\n%d. %s\t\t%d\t%d", i+1, s[i].name, s[i].regno, s[i].yr);
    }
    printf("\nNo. of comparisons = %d\n", c);
}

int main()
{
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    struct student S[n];
    for(int i=0; i<n; i++)
    {
        printf("Name: ");
        scanf("%s", S[i].name);
        printf("Reg no: ");
        scanf("%d", &S[i].regno);
        printf("Year: ");
        scanf("%d", &S[i].yr);
    }
    bubble_Sort(S, n);
    selection_Sort(S, n);
    insertion_Sort(S, n);
}