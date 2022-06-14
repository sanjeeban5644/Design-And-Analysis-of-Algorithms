#include<stdio.h>
#include<limits.h>

int max=INT_MIN,min=INT_MAX;
void maxmin(int[],int ,int );

int main(){
	int n,i;
	printf("\nEnter the total no.of elements : ");
	scanf("%d",&n);
	int arr[n];
	printf("\nEnter the elements : ");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	maxmin(arr,0,n-1);
	printf("\nLargest no.is : %d",max);
	printf("\nSmallest no. is : %d",min);
	return 0;
}

void maxmin(int arr[],int low,int high){
	if(low==high){
		if(arr[low]>max){
			max=arr[low];
		}
		if(arr[high]<min){
			min=arr[high];
		}
		return ;
	}
	int mid = (low+high)/2;
	maxmin(arr,low,mid);
	maxmin(arr,mid+1,high);
}