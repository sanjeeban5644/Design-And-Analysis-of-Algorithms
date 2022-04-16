#include<stdio.h>
#include<stdlib.h>

struct queue{
    int data;
    struct queue *next;
}*front=NULL,*rear=NULL;

void enqueue(int );
int dequeue();

int main(){
    int n;    
    printf("\nEnter the number of vertices : ");
    scanf("%d",&n);
    int arr[n][n];
    char vertex_name[n];
    printf("\nEnter the names of the vertices");
    int i,j;
    for(i=0;i<n;i++){ 
        printf("\nEnter the name of vertex %d : ",i+1);
        scanf(" %c",&vertex_name[i]);
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j){
                arr[i][j]=0;
            }
            else{
                arr[i][j]=-1;
            }
        }
    }
    int t;
    char answer;
    for(t=0;t<n;t++){
        printf("\n--Considering Vertex %c--",vertex_name[t]);
        char ch = vertex_name[t];
        for(i=0;i<n;i++){
            if(ch!=vertex_name[i] && arr[t][i]==-1){
                printf("\nIs '%c' and '%c' connected?",ch,vertex_name[i]);
                scanf(" %c",&answer);
                if(answer=='y'){
                    arr[t][i]=1;
                    arr[i][t]=1;
            }
                else{
                    arr[t][i]=0;
                    arr[i][t]=0;
                }
            }
        }
    }
    printf("\nThe Adjacency Matrix for the Graph is : \n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf(" %d",arr[i][j]);
        }
        printf("\n");
    }
    char ch;
    printf("\nEnter the starting vertex : ");
    scanf(" %c",&ch);
    int visited[n];
    for(t=0;t<n;t++){
        if(vertex_name[t]==ch){
            break;
        }
    }
    for(i=0;i<n;i++){
        visited[i]=0;
    }
    printf("\n\nThe BFS Traversal of the Graph is : ");
    printf(" %c",vertex_name[t]);
    enqueue(t);
    visited[t]=1;
    while(1){
        if(front==NULL){
            printf("\nProgram Ended");
            break;
        }
        int first = dequeue();
        for(j=0;j<n;j++){
            if(arr[first][j]==1 && visited[j]==0){
                printf(" %c",vertex_name[j]);
                visited[j]=1;
                enqueue(j);
            }
        }
    }
return 0;
}
void enqueue(int value){
    struct queue *new = (struct queue*)malloc(sizeof(struct queue));
    new->data=value;
    new->next=NULL;
    if(front==NULL || rear==NULL){
        front = new;
        rear = new;
    }
    else{
        rear->next=new;
        rear=new;
    }
}
int dequeue(){
    struct queue* temp;
    if(front!=NULL){
        temp = front;
        front = front->next;

    }
    return temp->data;
}