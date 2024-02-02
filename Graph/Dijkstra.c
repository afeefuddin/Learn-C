#include <stdio.h>
#include <stdlib.h>

#define INFIN 9999

int shortestDistance(int n, int graph[n+1][n+1],int v){
    int cost[n][n],int vis[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cost[i][j] = INFIN;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cost[i][j]
        }
    }
}

int main(){
    int n,e,a,b,wt;
    printf("Enter the number of vertex of the graph\n");
    scanf("%d",&n);
    printf("Enter the number of edges of the graph\n");
    scanf("%d",&e);
    int graph[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            graph[i][j] = 0;
        }
    }
    for(int i=0;i<e;i++){
        printf("Enter the edge a->b and wt in the form a b wt");
        scanf("%d %d",&a,&b);
        graph[a][b] = wt;
    }
}