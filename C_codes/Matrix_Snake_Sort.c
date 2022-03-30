// Question : Sort the entire matrix in a snake wise patter.

// Input ->    [4,1,5]
//             [7,2,9]
//             [8,3,6]

// Output ->   [1,2,3]
//             [6,5,4]
//             [7,8,9]
// ---------------------------------------------------------------------

#include<stdio.h>
#include<stdlib.h>

void sort(int [],int );
void swap(int *,int *);

int main(){
    int row,col;
    printf("\nEnter the row size of the matrix : ");
    scanf("%d",&row);
    printf("\nEnter the column size of the matrix : ");
    scanf("%d",&col);
    int i,j,k=0,arr[row][col],a[row*col];
    printf("\nEnter the matrix elements : \n");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("\nEnter the element [%d][%d] : ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
    printf("\nDisplaying the matrix \n");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf(" %d",arr[i][j]);
            a[k++]=arr[i][j];
        }
        printf("\n");
    }
    printf("\nDisplaying the sorted matrix \n");
    sort(a,k);
    int p=0;
    //continue from here
    
    for(i=0;i<row;i++){
        //int k=0;
        if(i%2==0){
            for(j=0;j<col;j++){
                arr[i][j]=a[p++];
            }
        }else{
            for(j=col-1;j>=0;j--){
                arr[i][j]=a[p++];
            }
        }
       
    }

    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf(" %d",arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void sort(int arr[],int k){
    int i,j;
    for(i=0;i<k-1;i++){
        for(j=0;j<k-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}