// Question : Sort the Matrix according to the elements of the column

// Example : Input ->  [4,2,3]
//                     [7,9,4]
//                     [2,1,5]
//           Output -> [2,1,3]
//                     [4,3,4]
//                     [7,9,5]
// ---------------------------------------------------------------------

#include<stdio.h>
#include<stdlib.h>

int main(){
    int row,col;
    printf("\nEnter the row size of the matrix : ");
    scanf("%d",&row);
    printf("\nEnter the column size of the matrix : ");
    scanf("%d",&col);
    int i,j,k,arr[row][col];
    printf("\nEnter the elements of the array : ");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("\nEnter the element [%d][%d] : ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
    printf("\nDisplaying the array : \n");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf(" %d",arr[i][j]);
        }
        printf("\n");
    }

    printf("\nDisplaying the sorted matrix : \n");

    for(i=0;i<col;i++){
        for(j=0;j<col-1;j++){
            for(k=0;k<col-1-j;k++){
                if(arr[k][i]>arr[k+1][i]){
                    int temp = arr[k][i];
                    arr[k][i] = arr[k+1][i];
                    arr[k+1][i] = temp;
                }
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