#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node* next;
}node;

void printOptions(){
    printf("1-->Insetion\n2-->Deletion\n3-->Display\n4-->Reverse\n5-->Sort\n0-->Exit\n");
}
void insetInaLinkedList(node** head){
    int elem;
    printf("Enter the element you want to insert\n");
    scanf("%d",&elem);
    node *temp = (*head);
    if(temp!=NULL){

    while(temp->next){
        temp = temp->next;
    }
    //Now my temp is pointing to the last element
    node* new;
    new =(node*) malloc(sizeof(node));
    new->val = elem;
    new->next=NULL;
    temp->next = new;
    }
    else{
        printf("HERE");
        node *new = (node*)malloc(sizeof(node));
        new->val=elem;
        new->next=NULL;
        *head = new;
        // printf("%d",temp->val);
    }
}
int sizeofLinkedList(node* head){
    int ans=0;
    while(head){
        head=head->next;
        ans++;
    }
    return ans;
}
void deleteFromaLinkedList(node** head){
    node* temp = *head;
    if(temp==NULL){
        printf("Can't delete from an empty LinkeddList");
        return;
    }
    int choose;
    printf("Enter the option\n");
    printf("1-->Delete from front \n 2-->Delete from the end");
    scanf("%d",&choose);
    if(choose==1){
        //delete from front
        node* temp = (*head);
        *head = temp->next;
        free(temp);
    }
    else if(choose==2){
        if(sizeofLinkedList(*head)==1){
            node* temp = (*head);
            *head = temp->next;
            free(temp);
        }else
        {
        while((temp->next)->next!=NULL){
            temp = temp->next;
        }
            node* temp2 = temp->next;
            temp->next=NULL;
            free(temp2);
        }
    }
    else{
        printf("Invalid Input");
        return;
    }
}
void display(node* head){
    while(head){
        printf("%d->",head->val);
        head=head->next;
    }
    printf("NULL\n");
}

void reverseALinkedList(node** head){
    if(sizeofLinkedList(*head)<=1){
        return;
    }
    node* prev;
    node* nex;
    node* cur;

    prev=NULL;
    cur = (*head);
    nex = cur->next;
    while(cur!=NULL){
        cur->next = prev;
        prev = cur;
        cur = nex;
        if(nex!=NULL)
        nex = nex->next;
    }
    *head = prev;
}
void sortALinkedList(node** head){
      int n = sizeofLinkedList(*head);
    if (n <= 0) {
        printf("Can't sort an empty LinkedList");
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        node* temp2 = *head;
        for (int j = 0; j < n - i - 1; j++) {
            if ((temp2->val) > (temp2->next->val)) {
                int temp = temp2->val;
                temp2->val = temp2->next->val;
                temp2->next->val = temp;
            }
            temp2 = temp2->next;
        }
    }
}
int main(){
    int options;
    node* head;
    head=NULL;
    printOptions();
    scanf("%d",&options);
    while(1){
        if(options==0){
            break;
        }
        switch (options)
        {
        case 1:
            insetInaLinkedList(&head);
            break;
        case 2:
            deleteFromaLinkedList(&head);
            break;
        case 3:
            display(head);
            break;
        case 4:
            reverseALinkedList(&head);
            break;
        case 5: 
            sortALinkedList(&head);
            break;
        default:
            break;
        }
        printOptions();
        scanf("%d",&options);
    }

}