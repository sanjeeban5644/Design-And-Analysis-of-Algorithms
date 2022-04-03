#include<stdio.h>

int fibonacci(int [],int );

int main(){
    int n,i;
    printf("\nEnter the term to print : ");
    scanf("%d",&n);
    int fibo[n];
    int ans =  fibonacci(fibo,n);
    printf("\nThe %dth term is : %d",n,ans);
    printf("\nThe final array is : ");
    for(i=0;i<n;i++){
        printf(" %d",fibo[i]);
    }
    return 0;
}

int fibonacci(int fibo[],int n){
    if(n<=1){
        return n;
    }
    fibo[0]=0;
    fibo[1]=1;
    int i;
    for(i=2;i<=n;i++){
        fibo[i]=fibo[i-1]+fibo[i-2];
    }
    return fibo[n];
}