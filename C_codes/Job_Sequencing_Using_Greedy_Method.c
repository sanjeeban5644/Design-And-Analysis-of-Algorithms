#include<stdio.h>

void sort(int [],int [],int [],int);

int main(){
	int i,n,maxdeadline = 0;
	printf("\nEnter the total no.of jobs : ");
	scanf("%d",&n);
	int id[n],profit[n],deadline[n];
	for(i=0;i<n;i++){
		printf("\nJob -> %d\n",i+1);
		printf("\nEnter the id : ");
		scanf("%d",&id[i]);
		printf("\nEnter the profit : ");
		scanf("%d",&profit[i]);
		printf("\nEnter the deadline : ");
		scanf("%d",&deadline[i]);
		if(deadline[i]>maxdeadline){
			maxdeadline=deadline[i];
		}
	}
	
	sort(id,profit,deadline,n);
	
	int totalslots[maxdeadline];
	for(i=0;i<maxdeadline;i++){
		totalslots[i]=-1;
	}
	int totprofit=0,totjob=0;
	for(i=0;i<n;i++){
		int p = deadline[i];
		while(p>0){
			if(totalslots[p-1]==-1){
				totalslots[p-1]=id[i];
				totprofit+=profit[i];
				totjob+=1;
				break;
			}
			else{
				p--;
			}
		}
		
	}
	printf("\n\nTotal Profit = %d",totprofit);
	printf("\nTotal jobs done = %d",totjob);
	printf("\nOrder of jobs : ");
	for(i=0;i<maxdeadline;i++){
		if(i==maxdeadline-1){
			printf(" Job-%d.",totalslots[i]);
		}else{
			printf(" Job-%d -> ",totalslots[i]);
		}
	}
	return 0;
}

void sort(int id[],int profit[],int deadline[],int n){
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(profit[j]<profit[j+1]){
				int temp;
				temp = profit[j];
				profit[j]=profit[j+1];
				profit[j+1]=temp;
				
				temp = id[j];
				id[j]=id[j+1];
				id[j+1]=temp;
				
				temp = deadline[j];
				deadline[j]=deadline[j+1];
				deadline[j+1]=temp;
				
			}
		}
	}
}