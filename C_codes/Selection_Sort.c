#include<stdio.h>
#include<limits.h>

void swap(int *,int *);

int main(){
	int n,index;
	printf("\nEnter the total elements : ");
	scanf("%d",&n);
	int arr[n];
	printf("\nEnter the elements of the array : ");
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("\nThe Entered Array is : ");
	for(i=0;i<n;i++){
		printf(" %d",arr[i]);
	}
	int count = 0;
	while(count<n-1){
		int min = arr[count];
		for(i=count+1;i<n;i++){
			if(arr[i]<min){
				min=arr[i];
				index = i;
			}
		}
		swap(&arr[count],&arr[index]);
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