//Building Stack With LinkedList
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node* next;
    struct node* prev;
} node;

typedef struct stack{
    node* top;
    node* bottom;
}stack;

void push(stack* st){
    int elem;
    printf("Enter the element you want to insert \n");
    scanf("%d",&elem);
    if(st->top==NULL){
        node* new = malloc(sizeof(node));
        new->val = elem;
        new->next = NULL;
        new->prev = NULL;
        st->top = new;
        st->bottom = new;
    }else{
    node* new = malloc(sizeof(node));
    new->val = elem;
    new->next = NULL;
    st->top->next = new;
    new->prev = st->top;
    st->top = new;
    }   
}

int pop(stack* st){
    int ans;
    if(st->top==NULL){
        printf("Stack is already empty\n");
        return -1;
    }
    
    if(st->top==st->bottom){
        node* temp = st->top;
        st->top = NULL;
        st->bottom = NULL;
        free(temp);
    }
    else{
        node* temp = st->top;
        st->top = st->top->prev;
        st->top->next = NULL;
        free(temp);
    }
}
void display(stack* st){
    if(st->top==NULL){
        printf("Stack is Empty\n");
        return;
    }
    node* temp = st->top;
    while(temp!=NULL){
        printf("| %d |\n",temp->val);
        temp = temp->prev;
    }
}
void printOptions(){
    printf("1-->Push\n2-->Pop\n3-->Display\n0-->Exit\n");
}
int main(){
    int choose;
    stack st;
    st.top = NULL;
    st.bottom = NULL;
    while(1){
        printf("Enter the Option\n");
        printOptions();
        scanf("%d",&choose);
        if(choose==0){
            break;
        }
        switch(choose){
            case 1:
                push(&st);
                break;
            case 2:
                pop(&st);
                break;
            case 3:
                display(&st);
                break;
            default:
                break;
        }
    }
}