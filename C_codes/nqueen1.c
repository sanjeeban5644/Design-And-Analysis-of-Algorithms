#include<stdio.h>

void queen(int ,int ,int []);
int place(int ,int ,int []);
void print(int ,int[]);

int count=1;

int main(){
	int n;
	printf("\nEnter the total no.of queens : ");
	scanf("%d",&n);
	int board[n];
	if(n<=3){
		printf("\nYou Fool!");
		return 0;
	}
	queen(1,n,board);
	return 0;
}

void queen(int row,int n,int board[]){
	int col;
	for(col=1;col<=n;col++){
		if(place(row,col,board)){
			board[row]=col;
			if(row==n){
				print(n,board);
			}else{
				queen(row+1,n,board);
			}
		}
	}
}

int place(int row,int col,int board[]){
	int i;
	for(i=1;i<=row-1;i++){
		if(board[i]==col){
			return 0;
		}
		if(abs(board[i]-col)==abs(i-row)){
			return 0;
		}
	}
	return 1;
}

void print(int n,int board[]){
	int i,j;
	printf("\nSolution %d : ",count++);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(board[i]==j){
				printf(" %d",j);
			}
		}
	}
}