#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int val;
    struct node* next;
    struct node* prev;
} node;

void printOptions(){
    printf("1-->Insertion\n2-->Deletion\n3-->Display");
}
int sizeofLinkedList(node* head){
    if(head==NULL){
        return 0;
    }
    int ans=1;
    node* temp = head->next;
    while(temp!=head){
        ans++;
        temp=temp->next;
    }
    return ans;
}
void insertInACircularLL(node** head){
    int index,elem;
    printf("Enter the position you want to insert\n");
    scanf("%d",&index);
    printf("Enter the element you want to insert\n");
    scanf("%d",&elem);
    if((*head)==NULL){
        node* new = malloc(sizeof(node));
        new->val = elem;
        new->next = new;
        new->prev = new;
        *head =  new;
    }else{
    int size = sizeofLinkedList(*head);
    if(size>=index){
        index = size-1;
    }
    node* temp = *head;
    while(index>0){
        index--;
        temp = temp->next;
    }
    node* temp2 = temp->next;
    node* new = malloc(sizeof(node));
    new->val = elem;
    new->next = temp2;
    new->prev = temp;
    temp->next = new;
    temp2->prev = new;
    }
}
void display(node* head){
    if(head==NULL){
        printf("LinkedList is Empty\n");
        return;
    }
    node* temp = head;
    printf("%d<=>",temp->val);
    temp=temp->next;
    while(temp!=(head)){
        printf("%d<=>",temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}
void deleteFromaCircularLL(node** head){
    int index;
    printf("Enter the position you want to delete\n");
    scanf("%d",&index);
    int size = sizeofLinkedList(*head);
     if (size == 0 || index >= size) {
        printf("Invalid position\n");
        return;
    }
    node* temp = *head;
    while(index>0){
        index--;
        temp = temp->next;
    }
    node* temp_prev = temp->prev;
    temp_prev->next = temp->next;
    temp->next->prev = temp_prev;
    
    if (index == 0) {
        *head = temp->next;
    }
    free(temp);
}
int main(){
     node* head;
    head=NULL;
    printOptions();
    int choose;
    while(1){
        printf("Enter your choice\n");
        scanf("%d",&choose);
        if(choose==0){
            break;
        }
        switch (choose)
        {
        case 1:
            insertInACircularLL(&head);
            break;
        case 2:
            deleteFromaCircularLL(&head);
            break;
        case 3:
            display(head);
            break;
        default:
            break;
        }
    }
}