#include<stdio.h>

#define INFY 1000

int min(int ,int );

int main(){
    int v,e,i,sv,dv,cost,j;
    printf("\nEnter the no.of vertex : ");
    scanf("%d",&v);
    printf("\nEnter the no.of edges : ");
    scanf("%d",&e);
    int mat[v][v];
    for(i=1;i<=v;i++){
        for(j=1;j<=v;j++){
            if(i==j){
                mat[i][j]=0;
            }else{
                mat[i][j]=INFY;
            }
        }
    }

    // printf("\nPrinting the adjacency matrix : \n");
    // for(i=0;i<v;i++){
    //     for(j=0;j<v;j++){
    //         printf(" %d",mat[i][j]);
    //     }
    //     printf("\n");
    // }

    printf("\nEnter the individual src vertex, dest vertex and cost : ");
    for(i=0;i<e;i++){
        scanf("%d%d%d",&sv,&dv,&cost);

        mat[sv][dv]=cost;
        // printf("\n%d",mat[sv][dv]);
        // printf("%d\n",cost);
    }
    printf("\nPrinting the adjacency matrix : \n");
    for(i=1;i<=v;i++){
        for(j=1;j<=v;j++){
            printf(" %d",mat[i][j]);
        }
        printf("\n");
    }

    int k=1;
    for(k=1;k<=v;k++){
        for(i=1;i<=v;i++){
            for(j=1;j<=v;j++){
                mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
            }
        }
    }
    printf("\n\n");
    printf("\nPrinting the adjacency matrix : \n");
    for(i=1;i<=v;i++){
        for(j=1;j<=v;j++){
            printf(" %d",mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}


int min(int a,int b){
    if(a<b){
        return a;
    }else{
        return b;
    }
}