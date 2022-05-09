#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
}*front=NULL,*rear=NULL,*temp;

void enqueue(int data){
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=NULL;
	if(front==NULL){
		front=newnode;
		rear=newnode;
	}
	else{
		rear->next=newnode;
		rear=newnode;
	}
}

int dequeue(){
	temp=front;
	front=front->next;
	temp->next=NULL;
	return temp->data;
}


int main(){
	int vertex,edges,i,j,a,b;
	printf("\nEnter the no.of vertices : ");
	scanf("%d",&vertex);
	printf("\nEnter the no.of edges : ");
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
	int start;
	printf("\nEnter the starting vertex : ");
	scanf("%d",&start);
	int visited[vertex+1];
	for(i=1;i<=vertex;i++){
		visited[i]=0;
	}
	visited[start]=1;
	printf(" %d",start);
	enqueue(start);
	while(1){
		if(front==NULL){
			break;
		}
		int top = dequeue();
		for(i=1;i<=vertex;i++){
			if(arr[top][i]==1 && visited[i]==0){
				printf(" %d",i);
				enqueue(i);
				visited[i]=1;
				arr[top][i]=0;
				arr[i][top]=0;
			}
		}
	}
	
	return 0;
}