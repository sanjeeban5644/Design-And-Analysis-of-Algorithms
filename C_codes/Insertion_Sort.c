#include<stdio.h>

void swap(int *,int *);

int main(){
	int n,i;
	printf("\nEnter the total no.of elements of the array : ");
	scanf("%d",&n);
	int arr[n];
	printf("\nEnter the elements of the array : ");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("\nThe Entered Array is : ");
	for(i=0;i<n;i++){
		printf(" %d",arr[i]);
	}
	int count = 0;
	while(count<n){
		for(i=count+1;i>0;i--){
			if(arr[i]<arr[i-1]){
				swap(&arr[i],&arr[i-1]);
			}
		}
		count++;
	}
	
	printf("\nThe Sorted Array is : ");
	for(i=0;i<n;i++){
		printf(" %d",arr[i]);
	}
	return 0;
}

void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}