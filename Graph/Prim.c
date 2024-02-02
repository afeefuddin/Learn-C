#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,e,a,b,wt;
    printf("Enter the number of vertices present in the graph ");
    scanf("%d",&n);
    int graph[n][n];
    printf("Enter the number of edges present in the graph ");
    scanf("%d",&e);
    
        for(int j=0;j<e;j++){
            printf("Enter the edge of the graph in the form a b wt ");
            scanf("%d %d %d",&a,&b,&wt);
            graph[a][b] = wt;
            graph[b][a] = wt;
        }
    int selected[n];
    for(int i=0;i<n;i++){
        selected[i] = 0;
    }
    int i=0;
    selected[0] = 1;
    while(i<n-1){
        int x,y;
        int min = 9999;
        for(int j=0;j<n;j++){

        if(selected[j]==1){
            for(int k=0;k<n;k++){
                if(graph[j][k]!=0 && min>graph[j][k] && selected[k]!=1){
                    x=j;
                    y=k;
                    min = graph[j][k];
                }
            }
        }
        }
    selected[y] =1;
    printf("%d - %d : %d \n",x,y,graph[x][y]);
    i++;
    }
}