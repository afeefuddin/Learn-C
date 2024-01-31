#include <stdio.h>
#include <stdlib.h>
// Max first

typedef struct PQ{
    int arr[20];
    int size;
} PQ;

void printOptions(){
    printf("1--> Insertion\n2-->Deletion\n0-->Exit\n");
}

void swap(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(PQ* pq){
    if(pq->size>=20){
        printf("Queue is already full \n");
        return;
    }
    int elem;
    printf("Enter the element you want to insert");
    scanf("%d",&elem);
    pq->arr[(pq->size)+1] = elem;
    pq->size = pq->size + 1;
    int index = (pq->size);
    while(index>1){
        int par = index/2;
        if(pq->arr[par]<pq->arr[index]){
            swap(&(pq->arr[par]),&(pq->arr[index]));
        }
        index = par;
    }
}
void delete(PQ* pq){
    if(pq->size==0){
        printf("Queue is already empty\n");
        return;
    }
    int ans = pq->arr[1];
    swap(&(pq->arr[1]),&(pq->arr[pq->size]));
    pq->size = pq->size-1;
    int i = 1;
    int size = pq->size;
    while(i<size){
        int left = 2*i;
        int right = (2*i) +1;
        if(left<size && pq->arr[left] > pq->arr[i]){
            swap(&(pq->arr[left]),&(pq->arr[i]));
            i = left;
        }
        else if(right<size && pq->arr[right] > pq->arr[i]){
            swap(&(pq->arr[right]),&(pq->arr[i]));
            i = right;
        }
        else{
            printf("%d Deleted from Priotiy Queue\n",ans);
            return;
        }


    }
    printf("%d Deleted from Priotiy Queue\n",ans);

}
int main(){
    PQ* pq;
    pq = malloc(sizeof(PQ));
    pq->size = 0;
    int options;
    printOptions();
    printf("Enter your choice \n");
    scanf("%d",&options);
    while(options){
        switch(options){
            case 1:
                insert(pq);
                break;
            case 2:
                delete(pq);
                break;
            default:
                break;
        }
        printOptions();
        printf("Enter your choice\n");
        scanf("%d",&options);
    }
}