#include<stdio.h>
#include<stdlib.h>
void printarray(int [],int );
void quicksort(int [],int ,int );
int partition(int [],int ,int );
void swap(int *,int *);
int main(){
    int n;
    printf("\nEnter the total elements of the array : ");
    scanf("%d",&n);
    printf("\nEnter the elements of the array : ");
    int i,arr[n];
    for(i=0;i<n;i++){
        printf("\nEnter the element [%d] : ",i);
        scanf("%d",&arr[i]);
    }

    printf("\nThe Entered Array is : ");
    printarray(arr,n);

    printf("\nThe Sorted Array is : ");
    quicksort(arr,0,n-1);
    printarray(arr,n);

    return 0;
}

void quicksort(int arr[],int lb,int ub){
    int t;
    if(lb<ub){
        t = partition(arr,lb,ub);
        quicksort(arr,lb,t-1);
        quicksort(arr,t+1,ub);
    }
}

int partition(int arr[],int lb,int ub){
    int pivot = arr[ub];
    int i=(lb-1),j;
    for(j=lb;j<ub;j++){
        if(arr[j]<=pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[ub]);
    return (i+1);
}

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printarray(int arr[],int n){
    int i;
    for(i=0;i<n;i++){
        printf(" %d",arr[i]);
    }
}