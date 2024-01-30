#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int val;
    struct node* next;
    struct node* prev; 
} node;

void printOptions(){
    printf("1-->Insetion\n2-->Deletion\n3-->Display\n4-->Reverse\n0-->Exit\n");
}

void insert_front(node** head,int value){
    if(*head==NULL){
        node* new = malloc(sizeof(node));
        new->val = value;
        new->next = NULL;
        new->prev = NULL;
        (*head) = new;
    }
    else{
        node* new = malloc(sizeof(node));
        new->val = value;
        new->prev = NULL;
        new->next = *head;
        (*head)->prev = new;
        *head = new;
    }
}
void insert_back(node** head, int value){
    if(*head==NULL){
        insert_front(head,value);
    }
    else{
        node* temp = *head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        node* new = malloc(sizeof(node));
        new->val = value;
        new->next = NULL;
        new->prev = temp;
        temp->next = new;
    }
}

void insertInADLL(node** head){
    int elem;
    int choose;
    printf("Enter the positin in which you want to insert the new node \n");
    printf("1-->Insert From Front\n2-->Inset From Back\n");
    scanf("%d",&choose);
    printf("Enter the Element You want to insert");
    scanf("%d",&elem);
    if(choose==1){
        insert_front(head,elem);
    }
    else if(choose==2){
        insert_back(head,elem);
    }
    else{
        printf("Invalid Input\n");
        return;
    }
}

void display(node* head){
    while(head){
        printf("%d<=>",head->val);
        head = head->next;
    }
    printf("NULL\n");
}
void delete_front(node** head){
    if((*head)==NULL){
        printf("Can't delete from an empty LinkedList\n");
    }
    node* temp = *head;
    node* temp2 = *head;
    temp2 = temp2->next;
    if(temp2!=NULL){
        temp2->prev = NULL;
    }
    *head = temp2;
    free(temp);
}
void delete_back(node** head){
    if((*head)==NULL){
        printf("Can't delete from an empty LinkedList\n");
    }
    if((*head)->next==NULL){
        delete_front(head);
    }
    node* temp = *head;
    while((temp->next)->next!=NULL){
        temp = temp->next;
    }
    node* temp2 = temp->next;
    temp->next = NULL;
    free(temp2);
}
void deleteFromADLL(node** head){
    int choose;
    printf("1-->Delete from Front\n2-->Delete from Back\n");
    printf("Enter your choice\n");
    scanf("%d",&choose);
    if(choose==1){
        delete_front(head);
    }
    else if(choose==2){
        delete_back(head);
    }
    else{
        printf("Invalid Input");
    }
}
void reverseADLL(node** head){
    if(*head == NULL || (*head)->next == NULL){
        return;
    }
    node* pre;
    node* cur;
    node* nex;
    cur = *head;
    nex = (*head)->next;
    pre = NULL;
    while(cur!=NULL){
        cur->next = pre;
        cur->prev = nex;
        pre = cur;
        cur = nex;
        if(nex!=NULL){
            nex = nex->next;
        }
    }
    (*head) = pre;
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
        insertInADLL(&head);
            break;
        case 2:
            deleteFromADLL(&head);
            break;
        case 3:
            display(head);
            break;
        case 4:
            reverseADLL(&head);
        default:
            break;
        }
    }
}