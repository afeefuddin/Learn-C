#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    int height;
    struct node* left;
    struct node* right;
}node;

int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}

int height(node* root){
    if(root==NULL){
        return 0;
    }
    return root->height;
}

int getBalance(node* root){
    if(root==NULL)
        return 0;
    return height(root->left) - height(root->right);
}

node* leftRotate(node* root){
    node* ptr = root->left;
    root->left = ptr->right;
    ptr->right = root;
    root->height = max(height(root->left),height(root->right)) + 1;
    ptr->height = max(height(ptr->right),height(ptr->left)) + 1;
    return ptr;
}
node* rightRotate(node* root){
    node* ptr = root->right;
    root->right = ptr->left;
    ptr->left = root;
    root->height = max(height(root->left),height(root->right)) + 1;
    ptr->height = max(height(ptr->right),height(ptr->left)) + 1;
    return ptr;
}
node* insert(node* root, int data){
    if(root==NULL){
        node* new = malloc(sizeof(node));
        new->val = data;
        new->right = NULL;
        new->left = NULL;
        new->height = 0;
        return new;
    }
    if((root->val)>data){
        root->left = insert(root->left,data);
    }
    else {
        root->right = insert(root->right,data);
    }
    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);
    if(balance>1 && root->left->val > data){
        //left left
        root = leftRotate(root);
    }
    if(balance>1 && root->left->val < data){
        // left right 
        root->left = rightRotate(root->left);
        root = leftRotate(root);
        
    }
    if(balance < -1 && root->right->val > data){
        //right left 
        root->right = leftRotate(root->right);
        root = rightRotate(root);
    }
    if(balance < -1 && root->right->val <data){
        //right right
        root = rightRotate(root);
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
node* insertInATree(node* root){
    int options,value;
    printf("Enter 0 to exit and 1 to insert\n");
    scanf("%d",&options);
    while(options){
        printf("Enter the element to insert\n");
        scanf("%d",&value);
        root = insert(root,value);
        printf("Inserted\n");
        printf("Enter 0 to exit and 1 to insert\n");
        scanf("%d",&options);
    }
    return root;
}

int main(){
    node* root = NULL;
    root = insertInATree(root);
    printf("The inorder traversal of the tree is : ");
    inorderTraversal(root);
    return 0;
}