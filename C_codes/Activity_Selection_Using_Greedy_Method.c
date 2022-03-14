#include<stdio.h>
void sort(int [],int [],int [],int );
int main(){
	int i,n;
	printf("\nEnter the total no.of activities : ");
	scanf("%d",&n);
	int id[n],start[n],finish[n];
	for(i=0;i<n;i++){
		printf("\nActivity - %d",i+1);
		printf("\nEnter the id : ");
		scanf("%d",&id[i]);
		printf("\nEnter the start time : ");
		scanf("%d",&start[i]);
		printf("\nEnter the finish time : ");
		scanf("%d",&finish[i]);
	}
	sort(id,start,finish,n);
	int totalactivities[n],t=0;
	i=0;
	totalactivities[i] = id[t];
	i++;
	int lastactivity = finish[t];
	t++;
	while(1){
		if(start[t]>=lastactivity){
			totalactivities[i]=id[t];
			lastactivity=finish[t];
			i++;
			}
			t++;
			if(t==n){
				break;
		}
	}
	totalactivities[i]='\0';
	printf("\nTotal activities selected in order is : ");
	for(i=0;totalactivities[i]!='\0';i++){
		printf(" %d ",totalactivities[i]);
	}
	return 0;
}

void sort(int id[],int start[],int finish[],int n){
	int i,j,temp;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(finish[j]>finish[j+1]){
				temp=finish[j];
				finish[j]=finish[j+1];
				finish[j+1]=temp;
				
				temp=id[j];
				id[j]=id[j+1];
				id[j+1]=temp;
				
				temp=start[j];
				start[j]=start[j+1];
				start[j]=temp;
			}
		}
	}
}