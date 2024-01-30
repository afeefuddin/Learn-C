#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node* next;
}node;
typedef struct queue{
    node* front;
    node* rear;
} Queue;

void enqueue(int data, Queue *qu){
    if(qu->rear==NULL){
        node* new = malloc(sizeof(node));
        new->val = data;
        qu->rear = new;
        qu->front = new;
        qu->rear->next = qu->front;
    }
    else{
        node* new = malloc(sizeof(node));
        new->val = data;
        qu->rear->next = new;
        qu->rear = new;
        qu->rear->next = qu->front;
    }
}
int dequeue(Queue* qu){
    int ans;
    if(qu->rear==NULL){
        printf("Queue is Empty");
        exit(1);
    }
    if(qu->front==qu->rear){
        node* temp = qu->front;
        ans = qu->front->val;
		qu->front = NULL;
		qu->rear = NULL;
		free(temp);
		return ans;
    }
    node* temp = qu->front;
    ans = temp->val;
    qu->front = qu->front->next;
    qu->rear->next = qu->front;
    free(temp);
    return ans;
}

void josephus(int n,int k){
    Queue qu;
    qu.front = NULL;
    qu.rear = NULL;
    for(int i=1;i<=n;i++){
        enqueue(i,&qu);
    }
    int ans = 0;
    printf("The Order of elimination is : ");
    while(qu.front!=qu.rear){
        for(int i=0;i<k-1;i++){
            enqueue(dequeue(&qu),&qu);
        }
        printf("%d ",dequeue(&qu));
    }
    printf("\nThe position of josephus is %d",dequeue(&qu));
}
int main(){
    int n,k;
    printf("Enter the value of n and k\n");
    scanf("%d %d",&n,&k);
    josephus(n,k);
}