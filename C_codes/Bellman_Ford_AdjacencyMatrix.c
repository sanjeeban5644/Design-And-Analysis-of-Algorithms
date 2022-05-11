#include<stdio.h>


int main(){
	int vertices,edges,i,j;
	printf("\nEnter the total no.of vertices : ");
	scanf("%d",&vertices);
	printf("\nEnter the total no.of edges : ");
	scanf("%d",&edges);
	int mat[vertices+1][vertices+1];
	int source[edges+1],dest[edges+1],cost[edges+1],dist[vertices+1];
	for(i=1;i<=vertices;i++){
		dist[i]=9999;
	}
	printf("\nEnter the edges and cost in order : ");
	for(i=1;i<=edges;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		source[i]=a;
		dest[i]=b;
		cost[i]=c;
	}
//	printf("\nSource array : ");
//	for(i=1;i<=edges;i++){
//		printf(" %d",source[i]);
//	}
//	printf("\ndestination array : ");
//	for(i=1;i<=edges;i++){
//		printf(" %d",dest[i]);
//	}
//	printf("\ncost array : ");
//	for(i=1;i<=edges;i++){
//		printf(" %d",cost[i]);
//	}
//	printf("\ndistance array : ");
//	for(i=1;i<=vertices;i++){
//		printf(" %d",dist[i]);
//	}
	int src;
	printf("\nEnter the source vertex : ");
	scanf("%d",&src);
	dist[src]=0;
	int c = 1;
	for(i=1;i<vertices;i++){
		for(j=1;j<=edges;j++){
			if(dist[source[j]]+cost[j]<dist[dest[j]]){
				dist[dest[j]]=dist[source[j]]+cost[j];
			}
		}
		int k;
		for(k=1;k<=vertices;k++){
			mat[c][k]=dist[k];
			
		}
		c++;
	}
	
	printf("\n");
	for(i=1;i<=vertices;i++){
		for(j=1;j<=vertices;j++){
			printf(" %d",mat[i][j]);
		}
		printf("\n");
	}
	

	
	for(i=1;i<=vertices;i++){
		printf(" \n%d -> %d ",i,dist[i]);
	}
	return 0;
}