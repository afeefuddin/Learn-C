#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
} node;

void dfs(node *adjList[], int vis[], int cur)
{
    if (vis[cur] == 1)
    {
        return;
    }
    printf("%d ", cur);
    node *temp;
    if(adjList[cur]!=NULL)
    temp = adjList[cur]->next;
    else
    temp = NULL;
    vis[cur] = 1;
    while (temp != NULL)
    {
        dfs(adjList, vis, temp->val);
        temp = temp->next;
    }
}
node *createNode(int a)
{
    node *new = malloc(sizeof(node));
    new->val = a;
    new->next = NULL;
    return new;
}
void printList(node *adjList[], int n)
{
    for (int i = 0; i < n; i++){
        printf("%d ->", i);
        if (adjList[i] != NULL){
            node *temp;
            temp = adjList[i]->next;
            printf("[");
            while (temp != NULL){
                printf("%d ,", temp->val);
                temp = temp->next;
            }
            printf("]\n|\n");
        }
        else{
            printf("[]\n|\n");
        }
    }
}
void addEdge(node *adjList[], int a, int b)
{
    if (adjList[a] == NULL){
        adjList[a] = createNode(a);
    }
    node *n = createNode(b);
    n->next = adjList[a]->next;
    adjList[a]->next = n;
}

int main()
{
    int n, e, a, b;
    printf("Enter the number of vertex present in the graph\n");
    scanf("%d", &n);
    node *adjList[n];
    int vis[n];
    for (int i = 0; i < n; i++)
    {
        adjList[i] = NULL;
    }
    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
    }
    printf("Enter the number of edges present in the graph");
    scanf("%d", &e);
    for (int i = 0; i < e; i++)
    {
        printf("Enter the edge a->b in the form a b ");
        scanf("%d %d", &a, &b);
        addEdge(adjList, a, b);
    }
    dfs(adjList, vis, 0);
    printList(adjList, n);
}