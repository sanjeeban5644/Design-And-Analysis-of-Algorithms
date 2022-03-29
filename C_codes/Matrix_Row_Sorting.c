// Question : Sort the Matrix according to the elements of the row

// Example : Input ->   [4,2,3]
//                      [7,9,4]
//                      [2,1,3]
//           Output ->  [2,3,4]
//                      [4,7,9]
//                      [1,2,3]
//-------------------------------------------------------
#include<stdio.h>
#include<stdlib.h>

int main(){
    int row,col;
    printf("\nEnter the row size of the matrix : ");
    scanf("%d",&row);
    printf("\nEnter the column size of the matrix : ");
    scanf("%d",&col);
    printf("\nEnter the array elements : ");
    int i,j,arr[row][col],k;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("\nEnter the element [%d][%d] : ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf(" %d",arr[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<row;i++){
        for(j=0;j<col-1;j++){
            for(k=0;k<col-j-1;k++){
                if(arr[i][k]>arr[i][k+1]){
                    int temp = arr[i][k];
                    arr[i][k]=arr[i][k+1];
                    arr[i][k+1]=temp;
                }
            }
        }
    }

    printf("\nThe Sorted Array is : \n");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf(" %d",arr[i][j]);
        }
        printf("\n");
    }
    return 0;

}