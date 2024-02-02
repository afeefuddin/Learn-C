#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int vertex;
    struct node* next;
}node;

int numVertices;

node* createNode(int v){
    node* new = malloc(sizeof(node));
    new->vertex = v;
    new->next = NULL;
    return new;
}
void addNode(int a, int b, node* adjList[]){
    if (adjList[a] == NULL) {
        adjList[a] = createNode(a);
    }

    node* new = createNode(b);
    new->next = adjList[a]->next;
    adjList[a]->next = new;
    
}

void printList(node* adjList[]){
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
int main(){
    int edges;
    printf("Enter the number of vertices in the graph : ");
    scanf("%d",&numVertices);
    node* adjList[numVertices];
    for(int i=0;i<numVertices;i++){
        adjList[i] = NULL;
    }
    printf("Enter the number of edges present in the graph : ");
    scanf("%d",&edges);
    for(int i=0;i<edges;i++){
        int a,b;
        printf("Enter the edge like a->b so enter a b ");
        scanf("%d %d",&a,&b);
        addNode(a,b,adjList);
    }
    printList(adjList);
}