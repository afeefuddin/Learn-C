#include <stdio.h>
#include <stdlib.h>


#define MAX_SIZE 20

int n;

typedef struct queue{
    int arr[20];
    int sizeofQueue;
    int front;
    int rear;

}queue;

void enqueue(queue* q,int data){
    if (q->sizeofQueue >= MAX_SIZE) {
        printf("Queue overflow\n");
        return;
    }
    q->arr[q->rear] = data;
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->sizeofQueue = q->sizeofQueue + 1;
}

int dequeue(queue* qu){
  if (qu->sizeofQueue <= 0) {
        printf("Queue is already empty\n");
        return -1; 
    }
    int ans = qu->arr[qu->front];
    qu->front = (qu->front + 1) % MAX_SIZE;
    qu->sizeofQueue = qu->sizeofQueue - 1;
    return ans;
}

int isEmpty(queue* qu){
    if(qu->sizeofQueue==0){
        return 1;
    }
    return 0;
}

void bfs(int n , int graph[n+1][n+1]){
    int vis[n];
    queue qu;
    qu.front =0;
    qu.rear =0;
    qu.sizeofQueue = 0;
    for(int i=0;i<n;i++){
        vis[i]=0;
    }
    enqueue(&qu,0);
        vis[0] = 1;
    while (!isEmpty(&qu))
    {
        int cur = dequeue(&qu);
        for(int i = 0;i<n+1;i++){
            if(graph[cur][i]==1 && vis[i]!=1){
                enqueue(&qu,i);
                vis[i] = 1;
            }
        }
        printf("%d ", cur);
    }
    

}

int main(){
    int edges,a,b;
    printf("Enter the number of vertices present in the graph : ");
    scanf("%d",&n);
    int graph[n+1][n+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            graph[i][j] = 0;
        }
    }
    printf("Enter the number of edges present in the graph : ");
    scanf("%d",&edges);
    for(int i=0;i<edges;i++){
        printf("Enter the edges of the graph a->b in the the format a b : ");
        scanf("%d %d",&a,&b);
        graph[a][b] = 1;
    }
    bfs(n,graph);
}