#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#define SIZE 4

int minCost;

struct Edge
{
    int src, dest, weight;
};

struct Graph
{
    int V, E;
    struct Edge* edge;
};

struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;

    graph->edge = (struct Edge*) malloc(sizeof(struct Edge) * E);

    return graph;
};

struct subset
{
    int parent;
    int rank;
};

int find(struct subset subsets[], int i)
{
    if(subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if(subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if(subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int myComp(const void* a, const void* b)
{
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1 -> weight > b1 -> weight;
}

void kruskalMST(struct Graph* graph)
{
    int V = graph->V;
    struct Edge result[V];
    int e = 0;
    int i = 0;
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);
    struct subset *subsets =
        (struct subset*) malloc(V * sizeof(struct subset));

    int v;
    for(v = 0; v < V; v++)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while(e < V - 1)
    {
        struct Edge next_edge = graph->edge[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if(x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    printf("\nFollowing are the edges in the constructed MST\n");
    for(i = 0; i < e; ++i)
    {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
        minCost += result[i].weight;
    }
    printf("\nMinimum Cost: %d\n\n", minCost);

    return;
}

int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;
    int v;

    for(v = 0; v < SIZE; v++)
    {
        if(mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    }

    return min_index;
}

int printMST(int parent[], int n, int graph[SIZE][SIZE])
{
    printf("\nFollowing are the edges in the constructed MST\n");
    int i;
    for(i = 1; i < SIZE; i++)
    {
        printf("%d -- %d == %d \n", parent[i], i, graph[i][parent[i]]);
        minCost += graph[i][parent[i]];
    }
    printf("\nMinimum Cost: %d\n\n", minCost);
}

void primMST(int graph[SIZE][SIZE])
{
    int parent[SIZE];
    int key[SIZE];
    bool mstSet[SIZE];
    int i;
    for(i = 0; i < SIZE; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1;
    int count;
    for(count = 0; count < SIZE-1; count++)
    {
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        int v;

        for(v = 0; v < SIZE; v++)
        if(graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
            parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, SIZE, graph);
}

int main()
{
    int tunjuk, i, j;
    int V, E;
    int adjMatrix[SIZE][SIZE];
    struct Graph* graphKruskal;

    printf("Adjacency Matrix size: %dx%d\n\n", SIZE, SIZE);
    for(i = 0; i < SIZE; i++)
    {
        for(j = 0; j < SIZE; j++)
        {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    while(1)
    {
        system("cls");
        minCost = 0;

        printf("1. Algoritma Kruskal\n");
        printf("2. Algoritma Prim\n");
        printf("3. Exit\n");
        printf("Pilihan : ");
        scanf("%d", &tunjuk);
        if(tunjuk == 1)
        {
            V = SIZE;
            E = 0;

            for(i = 0; i < SIZE; i++)
            {
                for(j = i+1; j < SIZE; j++)
                {
                    if(adjMatrix[i][j] != 0)
                    {
                        E += 1;
                    }
                }
            }

            graphKruskal = createGraph(V, E);

            int tempIndex = 0;
            for(i = 0; i < SIZE; i++)
            {
                for(j = i+1; j < SIZE; j++)
                {
                    if(adjMatrix[i][j] != 0)
                    {
                        graphKruskal->edge[tempIndex].src = i;
                        graphKruskal->edge[tempIndex].dest = j;
                        graphKruskal->edge[tempIndex++].weight = adjMatrix[i][j];
                    }
                }
            }

            kruskalMST(graphKruskal);
        }
        else if(tunjuk == 2)
        {
            primMST(adjMatrix);
        }
        else if(tunjuk == 3)
        {
            break;
        }

        system("pause");
    }
    return 0;
}

