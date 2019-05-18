#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int data;
    struct Queue *next;
};

void enqueue(struct Queue **queue, int v)
{
    struct Queue *curr;
    struct Queue *tmp = (struct Queue*) malloc(sizeof(struct Queue));
    tmp->data = v;
    tmp->next = NULL;

    if(*queue == NULL)
    {
        *queue = tmp;
    }
    else
    {
        curr = *queue;
        while(1){
            if(curr->next == NULL)
            {
                curr->next = tmp;
                break;
            }
            else
            {
                curr = curr->next;
            }
        }
    }
}

void dequeue(struct Queue **queue)
{
    struct Queue *hapus = *queue;
    *queue = (*queue)->next;
    free(hapus);
}

int isEmpty(struct Queue *queue)
{
    if(queue == NULL) return 1;
    else return 0;
}

int front (struct Queue *queue)
{
    return queue->data;
}

void BFS(int v, int start, int visited[], int adjMatrix[50][50])
{
    struct Queue *queue = NULL;
    int i;

    visited[start] = 1;
    enqueue(&queue, start);

    while(!isEmpty(queue))
    {
        int start = front(queue);
        printf("%d ", start);
        dequeue(&queue);

        for(i = 0; i < v; i++)
        {
            if(adjMatrix[start][i] > 0)
            {
                if(visited[i] == 0)
                {
                    visited[i] = 1;
                    enqueue(&queue, i);
                }
            }
        }
    }
}

int main(int argc, const char* argv[])
{
    int i, j, v;
    int adjMatrix[50][50];

    printf("Banyak Vertex : ");
    scanf("%d", &v);
    printf("\n");

    for(i = 0; i < v; i++)
    {
        for(j = 0; j < 2; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }

    int src, dest;
    i = 0;
    while(1){
        printf("Adjacency List ke-%d\n", ++i);
        printf("Source : ");
        scanf("%d", &src);

        printf("Destination : ");
        scanf("%d", &dest);

        printf("\n");

        if(src <= -1 || dest <= -1){
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
    BFS(v, start, visited, adjMatrix);

    return 0;
}
