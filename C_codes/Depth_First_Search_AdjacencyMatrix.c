#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
}*top=NULL,*temp;

void push(int data){
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=NULL;
	if(top==NULL){
		top=newnode;
	}
	else{
		newnode->next=top;
		top=newnode;
	}
}

int pop(){
	temp=top;
	top=top->next;
	temp->next=NULL;
	return temp->data;
}

int main(){
	int vertex,edges,i,j,a,b,start;
	printf("\nEnter the total no.of vertices : ");
	scanf("%d",&vertex);
	printf("\nEnter the total no.of edges : ");
	scanf("%d",&edges);
	int arr[vertex+1][vertex+1];
	for(i=1;i<=vertex;i++){
		for(j=1;j<=vertex;j++){
			arr[i][j]=0;
		}
	}
	printf("\nEnter the vertices and edges in order : \n");
	for(i=1;i<=edges;i++){
		scanf("%d%d",&a,&b);
		arr[a][b]=1;
		arr[b][a]=1;
	}
	printf("\nPrinting the Adjacency Matrix : \n");
	for(i=1;i<=vertex;i++){
		for(j=1;j<=vertex;j++){
			printf(" %d",arr[i][j]);
		}
		printf("\n");
	}
	printf("\nEnter the starting vertex : ");
	scanf("%d",&start);
	printf("\nThe DFS Traversal is : ");
	push(start);
	int visited[vertex+1];
	for(i=1;i<=vertex;i++){
		visited[i]=0;
	}
	visited[start]=1;
	while(1){
		if(top==NULL){
			break;
		}
		int start = pop();
		if(visited[start]==1){
			printf(" %d",start);
		}
		for(i=1;i<=vertex;i++){
			if(arr[start][i]==1 && visited[i]==0){
				
				push(i);
				visited[i]=1;
				arr[start][i]=0;
				arr[i][start]=0;
			}
		}
	}
	return 0;

}

