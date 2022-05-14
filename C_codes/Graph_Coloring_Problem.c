#include<stdio.h>

int g[20][20],arr[20],vertex,m,count;

void gcolor(int );
void next(int );

int main(){
	int edge,i,j,a,b;
	printf("\nEnter the no.of vertices : ");
	scanf("%d",&vertex);
	printf("\nEnter the no.of edges : ");
	scanf("%d",&edge);
	printf("\nEnter the edges : ");
	for(i=1;i<=vertex;i++){
		for(j=1;j<=vertex;j++){
			g[i][j]=0;
		}
	}
	for(i=1;i<=edge;i++){
		scanf("%d%d",&a,&b);
		g[a][b]=1;
		g[b][a]=1;
	}
	
	printf("\nEnter the no.of colors : ");
	scanf("%d",&m);
	gcolor(1);
	printf("\nTotal Solutions are : %d",count);
	return 0;
}

void gcolor(int k){
	int i;
	while(1){
		next(k);
		if(arr[k]==0){
			return ;
		}
		if(k==vertex){
			for(i=1;i<=vertex;i++){
				printf(" %d",arr[i]);
			}
			count++;
			printf("\n");
		}else{
			gcolor(k+1);
		}
	}
}

void next(int k){
	int j;
	while(1){
		arr[k]=(arr[k]+1)%(m+1);
		if(arr[k]==0){
			return;
		}
		for(j=1;j<=vertex;j++){
			if(g[k][j]==1 && arr[j]==arr[k]){
				break;
			}
		}
		if(j==(vertex+1)){
			return ;
		}
	}
}
