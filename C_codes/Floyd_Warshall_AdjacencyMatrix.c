#include<stdio.h>
#include<stdlib.h>

#define INFY 1000;

int main(){
	int vertex,edges,i,j,a,b,c,k;
	printf("\nEnter the total no.of vertices : ");
	scanf("%d",&vertex);
	printf("\nEnter the total no.of edges : ");
	scanf("%d",&edges);
	int mat[vertex+1][vertex+1];
	for(i=1;i<=vertex;i++){
		for(j=1;j<=vertex;j++){
			if(i==j){
				mat[i][j]=0;
			}else{
				mat[i][j]=INFY;
			}
			
		}
	}
	printf("\nEnter the vertices, edges and cost in order : ");
	for(i=1;i<=edges;i++){
		scanf("%d%d%d",&a,&b,&c);
		mat[a][b]=c;
	}
	for(k=1;k<=vertex;k++){
		for(i=1;i<=vertex;i++){
			for(j=1;j<=vertex;j++){
				mat[i][j] = min(mat[i][j],mat[i][k]+mat[k][j]);
			}
		}
		printf("\nPrinting Matrix : %d\n",k);
		for(i=1;i<=vertex;i++){
			for(j=1;j<=vertex;j++){
			printf(" %d",mat[i][j]);
		}
		printf("\n");
	}
		printf("\n");
	}
	
}

int min(int a,int b){
	if(a>b){
		return b;
	}
	return a;
	
}