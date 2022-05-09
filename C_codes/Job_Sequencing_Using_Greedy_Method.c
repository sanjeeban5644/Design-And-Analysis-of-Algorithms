#include<stdio.h>

void sort(int [],int [],int [],int );
void swap(int *,int *);


int main(){
	int tj,i;
	printf("\nEnter the total no.of jobs : ");
	scanf("%d",&tj);
	int id[tj],profit[tj],deadline[tj],max_d=0;
	printf("\nEnter the profits and deadlines : ");
	for(i=0;i<tj;i++){
		printf("\nEnter the profit for job %d : ",i+1);
		scanf("%d",&profit[i]);
		printf("\nEnter the deadline for job %d : ",i+1);
		scanf("%d",&deadline[i]);
		id[i]=i+1;
		if(deadline[i]>max_d){
			max_d=deadline[i];
		}
	}
	sort(id,profit,deadline,tj);
	int arr[max_d];
	for(i=0;i<max_d;i++){
		arr[i]=0;
	}
	
	for(i=0;i<tj;i++){
		int curr_d = deadline[i];
		while(curr_d>0){
			if(arr[curr_d-1]==0){
				arr[curr_d-1]=id[i];
				break;
			}else{
				curr_d--;
			}
		}
	}
	printf("\nThe Job Selected in order is : ");
	for(i=0;i<max_d;i++){
		printf(" J%d",arr[i]);
	}
	
	return 0;
	
}

void sort(int id[],int profit[],int deadline[],int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n-1-i;j++){
			if(profit[j]<profit[j+1]){
				swap(&profit[j],&profit[j+1]);
				swap(&id[j],&id[j+1]);
				swap(&deadline[j],&deadline[j+1]);
			}
		}
	}
}

void swap(int *a,int *b){
	int temp;
	temp=*a;
	*a = *b;
	*b = temp;
}
