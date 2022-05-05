#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define v 5

bool isSafe(int,int [v][v],int [],int );


bool graphcolor(int arr[v][v],int tot_color,int color[],int index){
        if(index>v){
            return true;
        }
        int i;
        for(i=1;i<=tot_color+1;i++){
            if(isSafe(index,arr,color,i)){
                color[index]=i;

            if(graphcolor(arr,tot_color,color,index+1)==true){
                return true;    
            }
             color[index]=0;
           
            }
           
        }
        return false;
}






bool isSafe(int index,int arr[v][v],int color[],int i){
    int j;
    for(j=1;j<=v;j++){
        if(arr[index][j] && i == color[j]){
            return false;
        }
    }
    return true;
}

int main(){
    int total_vertex,total_edges,i,a,b,j,tot_color;
    
    printf("\nEnter the total number of vertices : ");
    scanf("%d",&total_vertex);
    printf("\nEnter the total number of edges : ");
    scanf("%d",&total_edges);
    int arr[total_vertex+1][total_vertex+1];
    for(i=1;i<=total_vertex;i++){
        for(j=1;j<=total_vertex;j++){
            arr[i][j]=0;

        }
    }
    printf("\nEnter the vertices and edges in order : \n");
    for(i=0;i<total_edges;i++){
        scanf("%d%d",&a,&b);
        arr[a][b]=1;
        arr[b][a]=1; 
    }
    printf("\nPrinting the Adjacency Matrix\n");
    for(i=1;i<=total_vertex;i++){
        for(j=1;j<=total_vertex;j++){
            printf(" %d",arr[i][j]);
        }
        printf("\n");
    }
    printf("\nEnter the number of colors : ");
    scanf("%d",&tot_color);
    int color[total_vertex+1];
    for(i=1;i<=total_vertex;i++){
        color[i]=0;
        }
    if(graphcolor(arr,tot_color,color,1)==false){
            printf("\nNo Solution Exists");
            return false;
        }
    
    printf("\n\n\n");
    for(i=1;i<=total_vertex;i++){
        printf(" %d",color[i]);
    }

    return 0;
}


