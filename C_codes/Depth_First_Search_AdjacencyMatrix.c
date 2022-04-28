#include<stdio.h>
#include<stdlib.h>

int isempty_stack();
void push(int );
int pop();
void display();

struct node{
    int data;
    struct node *next;
}*top=NULL,*temp;

int main(){
    int edges,vertices,i,j,row,col,ele;
    printf("\nEnter the number of vertices : ");
    scanf("%d",&vertices);
    printf("\nEnter the number of edges : ");
    scanf("%d",&edges);
    int arr[vertices+1][vertices+1];
    int a[vertices+1];
    for(i=1;i<=vertices;i++){
        for(j=1;j<=vertices;j++){
            arr[i][j]=0;
        }
    }
    printf("\nEnter the edges with connections : ");
    for(i=1;i<=edges;i++){
        scanf("%d%d",&row,&col); 
        arr[row][col]=1;
        arr[col][row]=1;
    }
    for(i=1;i<=vertices;i++){
        for(j=1;j<=vertices;j++){
            printf(" %d",arr[i][j]);
        }
        printf("\n");
    }
    for(i=1;i<=vertices;i++){
        a[i]=0;
    }
    printf("\nEnter the starting node : ");
    scanf("%d",&ele);
    
    push(ele);
    //display();
        while(isempty_stack())
        {    
                ele = pop();
                if(a[ele]==0)
                {
                        printf("%d ",ele);
                        a[ele]=1;
                }
                for(i=1; i<=vertices; i++)
                {
                        if(arr[ele][i]==1 && a[i]==0)
                                push(i);
                }
        }
    


    //printf("\nh");

    return 0;
}

int isempty_stack(){
    if(top==NULL){
        return 0;
    }else{
        return 1;
    }
}

void push(int ele){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if(top==NULL){
        newnode->data=ele;
        newnode->next=NULL;
        top=newnode;
    }else{
        newnode->data=ele;
        newnode->next=top;
        top=newnode;
    }
}

int pop(){
    int ele;
    if(top!=NULL){
        temp=top;
        ele=top->data;
        top=top->next;
        temp->next=NULL;
        free(temp);
    }
    return ele;
}

void display(){
    if(top==NULL){
        printf("\ntt");
    }
    else{
        temp=top;
        while(temp!=NULL){
            printf(" %d",temp->data);
            temp=temp->next;
        }
    }
}