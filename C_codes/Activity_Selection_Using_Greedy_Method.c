#include<stdio.h>

void sort(int [],int [],int [],int );
void swap(int *,int *);

int main(){
	int n,i,j;
	printf("\nEnter the total no.of activities : ");
	scanf("%d",&n);
	int id[n],start[n],finish[n];
	printf("\nEnter the start and finish timings : ");
	for(i=0;i<n;i++){
		printf("\nEnter the start for activity %d : ",i+1);
		scanf("%d",&start[i]);
		printf("\nEnter the finish for activity %d : ",i+1);
		scanf("%d",&finish[i]);
		id[i]=i+1;
	}
	sort(id,start,finish,n);
	printf("\n");
	printf("\nThe Activities done is : ");
	printf(" A%d",id[0]);
	j=0;
	for(i=1;i<n;i++){
		if(finish[j]<start[i]){
			printf(" A%d",id[i]);
			j++;
		}
	}

	return 0;
}
void sort(int id[],int start[],int finish[],int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n-1-i;j++){
			if(finish[j]>finish[j+1]){
				swap(&finish[j],&finish[j+1]);
				swap(&start[j],&start[j+1]);
				swap(&id[j],&id[j+1]);
			}
		}
	}
}

void swap(int *a,int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}