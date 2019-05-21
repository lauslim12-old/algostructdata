#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INT_MAX 999999

int V = 0;
int src;

int minDistance(int dist[], int sptSet[])
{
    int min = INT_MAX, min_index;
    int v;
    for(v = 0; v < V; v++)
        if(sptSet[v] == 0 && dist[v] <= min)
        min = dist[v], min_index = v;

    return min_index;
}

int printSolution(int dist[], int n)
{
    int i;
    char k1;
    char k2 = src+97;
    printf("\n\n");
    for(i = 0; i < V; i++)
    {
        k1 = i+97;
        printf("Untuk mencapai kota %c dari kota %c membutuhkan jarak terpendek %d\n", k1, k2, dist[i]);
    }
}

void dijkstra(int graph[30][30], int src)
{
    int i, v, count, dist[V];
    int sptSet[V];
    for(i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = 0;
        dist[src] = 0;
        for(count = 0; count < V-1; count++)
        {
            int u = minDistance(dist, sptSet);
            sptSet[u] = 1;

            for(v = 0; v < V; v++)
                if(!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                    dist[v] = dist[u] + graph[u][v];
        }
        printSolution(dist, V);
}

int main()
{
    char input[10], tempWeight[5], source;
    int indexK1, indexK2, weight, graph[30][30], i, j;

    for(i = 0; i < 30; i++)
    {
        for(j = 0; j < 30; j++)
        {
            graph[i][j] = 0;
        }
    }

    while(1){
        scanf("%[^\n]", &input);
        getchar();

        if(input[0] == '-' || input[2] == '-')
        {
            break;
        }

        indexK1 = input[0] - 97;
        indexK2 = input[2] - 97;

        if(indexK1 >= V)
        {
            V = indexK1+1;
        }

        if(indexK2 >= V)
        {
            V = indexK2+1;
        }

        strcpy(tempWeight, "0");
        for(i = 4; i < strlen(input); i++)
        {
            tempWeight[i-4] = input[i];
        }
        weight = atoi(tempWeight);

        if(graph[indexK1][indexK2] == 0)
        {
            graph[indexK1][indexK2] = weight;
            graph[indexK2][indexK1] = weight;
        }
        else if(graph[indexK1][indexK2] > weight)
        {
            graph[indexK1][indexK2] = weight;
            graph[indexK2][indexK1] = weight;
        }
    }

    printf("\nSource : ");
    scanf("%c", &source);
    src = source - 97;

    dijkstra(graph, src);

    return 0;
}
