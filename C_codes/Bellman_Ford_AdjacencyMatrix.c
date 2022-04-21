#include<stdio.h>

#define INFY 1000

int main(){
    int v,e,i,j,srcvertex;
    printf("\nEnter the no.of vertex : ");
    scanf("%d",&v);
    printf("\nEnter the no.of edges : ");
    scanf("%d",&e);
    int distance[v];//,src[e],dest[e],cost[e];
    int src[] = {0,1,1,1,2,3,4,4,3,5,6};
    int dest[] = {0,2,3,4,5,2,3,6,5,7,7};
    int cost[] = {0,6,5,5,-1,-2,-2,-1,1,3,3};
    printf("\nEnter the total source, destination and cost of the arrays : \n");
    // for(i=1;i<=e;i++){
    //     scanf("%d%d%d",&src[i],&dest[i],&cost[i]);
    // }
    for(i=0;i<=v;i++){
        distance[i]=INFY;
    }
    printf("\nEnter the source vertex : ");
    scanf("%d",&srcvertex);
    distance[srcvertex]=0;

    for(i=1;i<=(v-1);i++){
        for(j=1;j<=e;j++){
            int k = dest[j];
            if(distance[j]+cost[j]<distance[k]){
                distance[k]=distance[j]+cost[j];
            }
        }
    }
    printf("\n\n");
    for(i=1;i<=v;i++){
        printf(" %d",distance[i]);
    }
    return 0;
}