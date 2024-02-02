#include <stdio.h>
#include <stdlib.h>

typedef struct Edge{
    int a;
    int b;
    int wt;
}Edge;
typedef struct EdgeList{
    Edge data[100];
    int n;
}
EdgeList el;
void sort(){
    for(int i=0;i<el.n;i++){
        for(int j=0;j<el.n-i-1;j++){
            if(el.data[j].wt > el.data[j+1].wt){
                Edge temp = el.data[i];
                el.data[i] = el.data[j];
            }
        }
    }
}

int applyUnion(int par[],int rank[],int a, int b){
    if(par[a]==par[b]){
        return 0;
    }
    if(rank[a]>rank[b]){
        par[b] = par[a];
    }
    else if(rank[a]<rank[b]){
        par[a] = par[b];
    }
    else{
        par[a] = par[b];
        rank[b]++;
    }
    return 1;
}
int main(){
    int e,v,a,b,wt;
    printf("Enter the number of vertex present : ");
    scanf("%d",&v);
    printf("Enter the number of edges present : ");
    scanf("%d",&e);
    int rank[v+1];
    int par[v+1];
    el.n =0;
    for(int i=0;i<e;i++){
        Edge ed;
        scanf("%d %d %d",&a,&b,&wt);
        ed.a = a;
        ed.b = b;
        ed.wt = wt;
        el.data[el.n] = e;
        el.n++;
    }
    sort();
    int ans =0;
    for(int i=0;i<el.n;i++){
        if(applyUnion(par,rank,el.data[i].u,el.data[i].v)==1){
            ans+=el.data[i].wt;
        }
    }
}