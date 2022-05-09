#include<stdio.h>
#include<stdlib.h>

#define INFY 1000

void printbracket(int,int );
int costarr[10][10],kmat[10][10];

int main(){
	int n,i,j,t;
	printf("\nEnter the total number of matrices : ");
	scanf("%d",&n);
	int arr[n];
	printf("\nEnter the dimensions of the array : ");
	for(i=0;i<=n;i++){
		scanf("%d",&arr[i]); 
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i==j){
				costarr[i][j]=0;
			}else{
				costarr[i][j]=INFY;
			}
		}
	}
	int ans = matrix_multiplication(arr,n);
	printf("\n%d\n",ans);
	printf("\n Optimal Brackets are : ");
	printbracket(1,n);
	return 0;
}

int matrix_multiplication(int arr[],int n){
	int i,j,k;
	for(i=n;i>0;i--){
		for(j=i+1;j<=n;j++){
			for(k=i;k<j;k++){
				int cost = (costarr[i][k]+costarr[k+1][j]+(arr[i-1]*arr[k]*arr[j]));
				if(cost<costarr[i][j]){
					costarr[i][j]=cost;
					kmat[i][j]=k;
				}
			}
		}
	}
	printf("\nPrinting the Cost Matrix\n");
	printf("\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf(" %d",costarr[i][j]);
		}
		printf("\n");
	}
	printf("\nPrinting the Matrix\n");
	printf("\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf(" %d",kmat[i][j]);
		}
		printf("\n");
	}
	return costarr[1][n];
}


void printbracket(int i,int j){
	if(i==j){
		printf("M%d",i);
	}else{
		printf("(");
		printbracket(i,kmat[i][j]);
		printbracket(kmat[i][j]+1,j);
		printf(")");
	}
}


