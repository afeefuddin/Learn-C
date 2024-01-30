#include <stdio.h>

void linearSearch(int arr[],int n){
    int val;
    int ans = -1;
    printf("Enter The Element You want to search\n");
    scanf("%d",&val);
    for(int i=0;i<n;i++){
        if(arr[i]==val){
            ans=i;
            break;
        }
    }
    if(ans==-1){
        printf("Unable to find %d in the array\n",val);
    }
    else{
        printf("%d found in the array at the position %d\n",val,ans);
    }
}
void binarySearch(int arr[], int n){
    int val; 
    int ans =-1;
    printf("Enter the element you want to search\n");
    scanf("%d",&val);
    int st =0 ;
    int end = n-1;
    while(st<=end){
        int mid = st + (end-st)/2;
        if(arr[mid]==val){
            ans = mid;
            break;
        }
        else if(arr[mid]>val){
            end = mid-1;
        }
        else{
            st = mid+1;
        }
    }
    if(ans==-1){
        printf("Unable to find %d in the array\n",val);
    }
    else{
        printf("%d found in the array at the position %d\n",val,ans);
    }
}

int main(){
    int n;
    printf("Enter the length of the array");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the Operation to be performed \n 0-->Linear Search \n 1-->Binary Search \n");
    int option;
    scanf("%d",&option);
    if(option==0){
        linearSearch(arr,n);
    }
    else if(option==1){
        binarySearch(arr,n);
    }
    else{
        printf("Invalid Input");
    }
    return 0;
}