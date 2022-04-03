#include<stdio.h>
int fibonacci(int [],int );
//int arr[100];

int main(){
    int n,i; 
    printf("\nEnter the term you want to print : ");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<=n;i++){
        arr[i]=-1;
    }
    int ans = fibonacci(arr,n);
    printf("\nThe %dth term is : %d",n,ans);
    printf("\nThe final array is : ");
    for(i=0;i<n;i++){
        printf(" %d",arr[i]);
    }
    return 0;
}

int fibonacci( int arr[], int n){
    
    if(arr[n]!=-1){
        return arr[n];
    }
    if(n<=1){
        arr[n]=n;
        return n;
    }
    int sum = fibonacci(arr,n-1)+fibonacci(arr,n-2);
    arr[n]=sum; 
    return sum;
}