#include<stdio.h>
#include<stdlib.h>

void DFS(int v, int start, int visited[], int adjMatrix[50][50])
{
    int i, j;

    visited[start] = 1;
    printf("%d ", start);

    for(i = 0; i < v; i++)
    {
        if(adjMatrix[start][i] > 0)
        {
            if(visited[i] == 0)
            {
                DFS(v, i, visited, adjMatrix);
            }
        }
    }
}

int main(int argc, const char* argv[])
{
    int i, j, k;
    int v;
    int adjMatrix[50][50];

    printf("Banyak Vertex : ");
    scanf("%d", &v);
    printf("\n");

    for(i = 0; i < v; i++)
    {
        for(j = 0; j < v; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }

    int src, dest;
    i = 0;
    while(1)
    {
        printf("Adjacency Matrix ke-%d\n", ++i);
        printf("Source : ");
        scanf("%d", &src);

        printf("Destination : ");
        scanf("%d", &dest);

        printf("\n");

        if(src <= -1 || dest <= -1)
        {
            break;
        }
        else
        {
            adjMatrix[src][dest] += 1;
            adjMatrix[dest][src] += 1;
        }
    }

    int visited[v];
    for(i = 0; i < v; i++)
    {
        visited[i] = 0;
    }

    int start;
    printf("Starting Node : ");
    scanf("%d", &start);
    DFS(v, start, visited, adjMatrix);
}
