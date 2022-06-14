#include<stdio.h>

#define INFY 9999;

int main(){
	int vertex,edge,i,j,a,b,u,v,c,min,totcost=0,count=1;
	printf("\nEnter the total vertices : ");
	scanf("%d",&vertex);
	int mat[vertex+1][vertex+1];
	for(i=1;i<=vertex;i++){
		for(j=1;j<=vertex;j++){
			mat[i][j]=INFY;
		}
	}
	printf("\nEnter the total edges : ");
	scanf("%d",&edge);
	printf("\nEnter the edges and cost in order : ");
	for(i=0;i<edge;i++){
		scanf("%d%d%d",&a,&b,&c);
		mat[a][b]=c;
	}
	int visited[vertex+1];
	for(i=1;i<=vertex;i++){
		visited[i]=0;
	}
	//selecting the 1st vertex as the starting vertex. 
	//You can change it as you wish.
	visited[1]=1;
	
	while(count<vertex){
		for(i=1;i<=vertex;i++){
			min=INFY;
			for(j=1;j<=vertex;j++){
				if(mat[i][j]<min){
					if(visited[i]!=0){
						min=mat[i][j];
						a=u=i;
						b=v=j;
					}
					if(visited[u]==0 || visited[v]==0){
						printf("\nEdge %d : %d->%d = %d",count++,a,b,min);
						totcost+=min;
						visited[b]=1;
					}
				}
			}
		}
		mat[a][b]=mat[b][a]=INFY;
	}
	
	printf("\nThe total cost is : %d",totcost);
	return 0;
}

