#include<stdio.h>

void sort(int [],int [],int [],float [],int );
int swap(int *,int *);

int main(){
	int n,i,value;
	float totprofit=0.0;
	printf("\nEnter the total no.of objects : ");
	scanf("%d",&n);
	int id[n],profit[n],weight[n];
	float pw[n],ss[n];
	for(i=0;i<n;i++){
		ss[i]=0.0;
	}
	printf("\nEnter the id, profit and weight in order : ");
	for(i=0;i<n;i++){
		scanf("%d",&id[i]);
		scanf("%d",&profit[i]);
		scanf("%d",&weight[i]);
		pw[i]=profit[i]/(float)weight[i];
	}
	sort(id,profit,weight,pw,n);
	printf("\nEnter the knapsack value : ");
	scanf("%d",&value);
	// Main Logic
	int temp = value,t=0;
	while(temp>0){
		if(temp-weight[t]>=0){
			temp=temp-weight[t];
			totprofit+=profit[t];
			ss[t]=1.0;
			t++;
		}else{
			float p = profit[t]*(temp/(float)weight[t]);
			totprofit+=p;
			ss[t]=temp/(float)weight[t];
			temp=0;
		}
	}
	printf("\nThe Solution Set is : {");
	for(i=0;i<n;i++){
		if(i==n-1){
			printf(" %f",ss[i]);
		}else{
			printf(" %f,",ss[i]);
		}
	}
	printf(" }");
	printf("\nThe total profit is : %f",totprofit);
	
	return 0;
}

void sort(int id[],int profit[],int weight[],float pw[],int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n-1-i;j++){
			if(pw[j]<pw[j+1]){
				float temp = pw[j];
				pw[j]=pw[j+1];
				pw[j+1]=temp;
				swap(&id[j],&id[j+1]);
				swap(&profit[j],&profit[j+1]);
				swap(&weight[j],&weight[j+1]);
			}
		}
	}
}

int swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

