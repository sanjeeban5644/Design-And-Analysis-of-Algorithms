//INCORRECT CODE
//CODE NOT WORKING
//CODE ON REVIEW...UPDATED CODE COMING SOON


#include<stdio.h>

void printarray(int [],int );
void heapsort(int [],int );
void maxheapify(int [],int ,int );
void swap(int *,int *);
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
    heapsort(arr,n);
    printarray(arr,n);

    return 0;
}

void heapsort(int arr[],int n){
    int i;
    for(i=n/2;i>=1;i--){
        maxheapify(arr,n,i);
    }
    for(i=n;i>=1;i--){
        swap(&arr[1],&arr[i]);
        maxheapify(arr,n,1);
    }
}

void maxheapify(int arr[],int n,int i){
    int largest = i;
    int l=(2*i);
    int r=(2*i)+1;

    while(l<=n && arr[l]>arr[largest]){
        largest=l;
    }
    while(l<=n && arr[r]>arr[largest]){
        largest=r;
    }
    if(largest!=i){
        swap(&arr[largest],&arr[i]);
        maxheapify(arr,n,largest);
    }
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