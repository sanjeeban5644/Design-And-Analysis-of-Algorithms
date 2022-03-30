#include<stdio.h>

void mergesort(int [],int ,int );
void merge(int [],int ,int ,int );
void printarray(int [],int );

int main(){
    int n;
    printf("\nEnter the total elements of the array : ");
    scanf("%d",&n);
    int arr[n],i;
    printf("\nEnter the elements of the array : ");
    for(i=0;i<n;i++){
        printf("\nEnter the element [%d] : ",i);
        scanf("%d",&arr[i]);
    }
    printf("\nThe Entered array is : ");
    printarray(arr,n);

    printf("\nThe Sorted array is : ");
    mergesort(arr,0,n-1);
    printarray(arr,n);

    return 0;
}

void mergesort(int arr[],int lb,int ub){
    if(lb<ub){
        int mid = (lb+ub)/2;
        mergesort(arr,lb,mid);
        mergesort(arr,mid+1,ub);
        merge(arr,lb,mid,ub);
    }
}

void merge(int arr[],int lb,int mid,int ub){
    int i=lb,k=lb;
    int j=mid+1,temparr[ub];
    while(i<=mid && j<=ub){
        if(arr[i]<=arr[j]){
            temparr[k]=arr[i];
            i++;
        }
        else{
            temparr[k]=arr[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        while(j<=ub){
            temparr[k]=arr[j];
            k++;
            j++;
        }
    }else{
        while(i<=mid){
            temparr[k]=arr[i];
            k++;
            i++;
        }
    }

    for(k=lb;k<=ub;k++){
        arr[k]=temparr[k];
    }

}

void printarray(int arr[],int n){
    int i;
    for(i=0;i<n;i++){
        printf(" %d",arr[i]);
    }
}