#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node* left;
    struct node* right;
} node;

node* insert(node* root,int data){
    if(root==NULL){
        node* new = malloc(sizeof(node));
        new->val = data;
        new->left = NULL;
        new->right = NULL;
        return new;
    }
    if((root->val)>data){
        root->left=insert(root->left,data);
    }
    else{
        root->right = insert(root->right,data);
    }
    return root;
}
node* insretInaTree(node* root){
    int n;
    printf("Enter the number of elements you wanna enter\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int cur;
        printf("Enter the element you want to insert\n");
        scanf("%d",&cur);
        root = insert(root,cur);
    }
    return root;
    
}
void inorderTraversal(node* root){
    if(root==NULL){
        return;
    }
    if(root->left!=NULL){
        inorderTraversal(root->left);
    }
    printf("%d ",root->val);
    if(root->right!=NULL){
        inorderTraversal(root->right);
    }
}
void preorderTraversal(node* root){
    if(root==NULL){
        return;
    }
    printf("%d ",root->val);
    if(root->left!=NULL){
        preorderTraversal(root->left);
    }
    if(root->right!=NULL){
        preorderTraversal(root->right);
    }
}
void postorderTraversal(node* root){
    if(root==NULL){
        return;
    }
    if(root->left!=NULL){
        postorderTraversal(root->left);
    }
    if(root->right!=NULL){
        postorderTraversal(root->right);
    }
    printf("%d ",root->val);
}
int main(){
    node* root = NULL;
    root = insretInaTree(root);
    printf("The inorder traversal : ");
    inorderTraversal(root);
    printf("\nThe preorder traversal : ");
    preorderTraversal(root);
    printf("\nThe postorder traversal : ");
    postorderTraversal(root);
}