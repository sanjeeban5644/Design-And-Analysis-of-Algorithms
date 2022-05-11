#include<stdio.h>
#define INFY 9999
int arr[20];

int uni(int, int );
int find(int );


int main(){
	int vertex,edges,i,j,k,a,b,count=1,min,totcost=0,u,v,q,w,t;
	printf("\nEnter the no.of vertices : ");
	scanf("%d",&vertex);
	int mat[vertex+1][vertex+1];
	for(i=1;i<=vertex;i++){
		for(j=1;j<=vertex;j++){
			mat[i][j]=INFY;
		}
	}
	printf("\nEnter the no.of edges : ");
	scanf("%d",&edges);
	printf("\nTake input : ");
	for(i=1;i<=edges;i++){
		scanf("%d%d%d",&q,&w,&t);
		mat[q][w]=t;
		mat[w][q]=t;
	}
	for(i=1;i<=vertex;i++){
 		for(j=1;j<=vertex;j++){
 			printf(" %d",mat[i][j]);
		 }
		 printf("\n");
	 }
	 
	 while(count<vertex){
	 	for(i=1,min=INFY;i<=vertex;i++){
	 		for(j=1;j<=vertex;j++){
	 			if(mat[i][j]<min){
	 				min=mat[i][j];
	 				a=u=i;
	 				b=v=j;
				 }
			 }
		 }
		 u=find(u);
		 v=find(v);
		 if(uni(u,v)){
		 	printf("\nEdge %d : %d -> %d  =  %d",count++,a,b,min);
		 	totcost+=min;
		 }
		 mat[a][b]=mat[b][a]=INFY;
	 }
	 
	printf("\nTotal cost is : %d",totcost);
}

int find(int i){
	while(arr[i]){
		i=arr[i];
	}
	return i;
}

int uni(int i,int j){
	if(i!=j){
		arr[j]=i;
		return 1;
	}
	return 0;
}