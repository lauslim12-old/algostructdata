#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <string.h>

struct Edge
{
    int dest;
    struct Edge *next;
}Edge;

struct Stack
{
    int data;
    struct Stack *next;
}Stack;

int top(struct Stack *stack)
{
    return stack->data;
}

int isEmpty(struct Stack *stack)
{
    if(stack == NULL) return 1;
    else return 0;
}

void pop(struct Stack **stack)
{
    struct Stack *hapus = *stack;
    *stack = (*stack)->next;
    free(hapus);
}

void push(struct Stack **stack, int v)
{
    struct Stack *node = (struct Stack*) malloc(sizeof(struct Stack));
    node->data = v;
    node->next = NULL;

    if(!isEmpty(*stack)) node->next = *stack;
    *stack = node;
}

void addEdge(struct Edge *adjList[], int src, int dest)
{
    struct Edge *tmp;

    tmp = (struct Edge *) malloc(sizeof(struct Edge));
    tmp->dest = dest;
    tmp->next = NULL;

    if(adjList[src] == NULL)
    {
        adjList[src] = tmp;
    }
    else
    {
        struct Edge *ptr = adjList[src];
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }

        ptr->next = tmp;
    }
}

void topologicalSort(int v, int visited[], struct Edge *adjList[], struct Stack **stack){
    visited[v] = 1;

    struct Edge *it;
    for(it = adjList[v]; it != NULL; it = it->next)
    {
        if(!visited[it->dest])
        {
            topologicalSort(it->dest, visited, adjList, stack);
        }
    }

    push(stack, v);
}

int main()
{
    struct Edge *adjList[50];
    struct Stack *stack = NULL;
    int banyakMateri, indexSrc, indexDest;
    int i, j;
    bool isSrcFound;
    bool isDestFound;
    char materi[50][50], src[50], dest[50];

    printf("Banyak Materi : ");
    scanf("%d", &banyakMateri);
    printf("\n");

    getchar();
    for(i = 0; i < banyakMateri; i++)
    {
        printf("Nama materi ke-%d : ", i+1);
        scanf("%[^\n]", &materi[i]);
        getchar();
    }

    system("cls");
    for(i = 0; i < 50; i++)
    {
        adjList[i] = NULL;
    }

    i = 0;
    while(1)
    {
        isSrcFound = false;
        isDestFound = false;
        printf("Hubungan materi Algoritma & Struktur Data ke-%d\n", ++i);
        printf("Materi yang harus dipelajari dulu : ");
        scanf("%[^\n]", &src);
        getchar();
        printf("Materi yang dapat dipelajari setelahnya : ");
        scanf("%[^\n]", &dest);
        getchar();
        printf("\n");

        if(strcmp(src, "done")==0 || strcmp(dest, "done")==0)
        {
            break;
        }
        else
        {
            for(j = 0; j < banyakMateri; j++)
            {
                if(strcmp(materi[j], src) == 0)
                {
                    indexSrc = j;
                    isSrcFound = true;
                }
            else if(strcmp(materi[j], dest) == 0)
                {
                    indexDest = j;
                    isDestFound = true;
                }
            }
            if(isSrcFound == true && isDestFound == true)
            {
                addEdge(adjList, indexSrc, indexDest);
            }
            else if(isSrcFound == false && isDestFound == false)
            {
                printf("Materi %s dan %s tidak dapat ditemukan\n", src, dest);
            }
            else if(isSrcFound == false)
            {
                printf("Materi %s tidak dapat ditemukan\n", src);
            }
            else
            {
                printf("Materi %s tidak dapat ditemukan\n", dest);
            }
        }
    }

    int visited[banyakMateri];
    for(i = 0; i < banyakMateri; i++)
    {
        visited[i] = 0;
    }

    for(i = 0; i < banyakMateri; i++)
    {
        if(!visited[i])
        {
            topologicalSort(i, visited, adjList, &stack);
        }
    }

    i = 1;
    printf("Urutan materi yang harus dipelajari :\n");
    while(!isEmpty(stack))
    {
        printf("%d. %s \n", i++, materi[top(stack)]);
        pop(&stack);
    }

    return 0;
}
