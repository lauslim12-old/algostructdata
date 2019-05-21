#include <stdio.h>

void takeInput(int ary[][10], int *completed, int *n)
{
    int i, j, village;

    printf("Enter the number of villages : ");
    scanf("%d", &village);
    *n = village;

    printf("\nEnter the Cost Matrix\n");

    for(i = 0; i < *n; i++)
    {
        printf("\nEnter Elements of Row : %d\n", i+1);

        for(j = 0; j < *n; j++)
            scanf("%d", &ary[i][j]);

        completed[i] = 0;
    }

    printf("\n\nThe cost list is : ");

    for(i = 0; i < *n; i++)
    {
        printf("\n");

        for(j = 0; j < *n; j++)
            printf("\t%d", ary[i][j]);
    }
}

int least(int c, int ary[][10], int *completed, int *cost, int n)
{
    int i, nc = 999;
    int min = 999, kmin;

    for(i = 0; i < n; i++)
    {
        if((ary[c][i] != 0) && (completed[i] == 0))
            if(ary[c][i] + ary[i][c] < min)
            {
                min = ary[i][c] + ary[c][i];
                kmin = ary[c][i];
                nc = i;
            }
    }

    if(min != 999)
        *cost +=kmin;

    return nc;
}

void mincost(int city, int ary[][10], int *completed, int *cost, int n)
{
    int i, ncity;

    completed[city] = 1;

    printf("%d--->", city+1);
    ncity = least(city, ary, completed,  cost, n);

    if(ncity == 999)
    {
        ncity = 0;
        printf("%d", ncity+1);
        *cost += ary[city][ncity];

        return;
    }

    mincost(ncity, ary, completed, cost, n);
}

int main()
{
    int ary[10][10], completed[10], n, cost = 0;

    takeInput(ary, completed, &n);

    printf("\n\nThe Path is :\n");
    mincost(0, ary, completed, &cost, n);

    printf("\n\nMinimum cost is %d\n ", cost);

    return 0;
}
