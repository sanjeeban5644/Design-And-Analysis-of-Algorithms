#include<stdio.h>

void heapsort(int [],int );
void heapify(int[] ,int ,int );
void swap(int *,int *);

int main(){
	int n,i;
	printf("\nEnter the total no.of elements of the array : ");
	scanf("%d",&n);
	int arr[n];
	printf("\nEnter the elements : ");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("\nThe Entered array is : ");
	for(i=0;i<n;i++){
		printf(" %d",arr[i]);
	}
	printf("\nThe Sorted array is : ");
	heapsort(arr,n);
	for(i=0;i<n;i++){
		printf(" %d",arr[i]);
	}
	return 0;
}

void heapsort(int arr[],int n){
	int i;
	for(i=(n/2)-1;i>=0;i--){
		heapify(arr,n,i);
	}
	for(i=n-1;i>=0;i--){
		swap(&arr[0],&arr[i]);
		heapify(arr,i,0);
	}
}

void heapify(int arr[],int n,int i){
	int lar = i;
	int left = (2*i)+1;
	int right = (2*i)+2;
	if(left<n && arr[left]>arr[lar]){
		lar = left;
	}
	if(right<n && arr[right]>arr[lar]){
		lar = right;
	}
	if(lar!=i){
		swap(&arr[lar],&arr[i]);
		heapify(arr,n,lar);
	}
}


void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}