#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float avg(int[],int );

int main(){
    int row,col;
    printf("\nEnter the no.of rows : ");
    scanf("%d",&row);
    printf("\nEnter the no.of columns : ");
    scanf("%d",&col);
    //generating random matrix
    int i,j,matrix[row][col];
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            matrix[i][j]=rand()%100;
        }
    }
    //printing the random matrix
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf(" %d",matrix[i][j]);
        }
        printf("\n");
    }
    //converting 2d to 1d
    int l = row*col;
    int arr[l],count=0;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            arr[count++]=matrix[i][j];
        }
    }
    // printing the 1-d array(optional)
    // printf("\n");
    // for(i=0;i<count;i++){
    //     printf(" %d",arr[i]);
    // }

    //generating two random integers
    int a = rand()%100;
    int b = rand()%100;
    int set_a[row*col];
    int set_b[row*col];
    count=0;
    int iter=1;

    while(1){

        int m=0,n=0;
        printf("\n\t----Iteration - %d----",iter++);

        printf("\nRandom value of 'a' : %d",a);
        printf("\nRandom value of 'b' : %d",b);

        for(i=0;i<l;i++){
            int diff1 = abs(arr[i]-a);
            int diff2 = abs(arr[i]-b);
            if(diff1<diff2){
                set_a[m++]=arr[i];
            }else{
                set_b[n++]=arr[i];
            }
        }
        //printing set-a
        printf("\nSet-A : ");
        for(i=0;i<m;i++){
            printf(" %d",set_a[i]);
        }
        //printing set-b
        printf("\nSet-B : ");
        for(i=0;i<n;i++){
            printf(" %d",set_b[i]);
        }
        float avg_set_a = avg(set_a,m);
        printf("\nAverage of Set-A is : %f",avg_set_a);
        float avg_set_b = avg(set_b,n);
        printf("\nAverage of Set-B is : %f",avg_set_b);

        if(abs(avg_set_a-a)<0.5 && abs(avg_set_b-b)<0.5){
            break;
        }
        else{
            a=avg_set_a;
            b=avg_set_b;
        }
            
    }
    return 0;

}

float avg(int arr[],int len){
    int i,sum=0;
    float sum2=0.0;
    for(i=0;i<len;i++){
        sum+=arr[i];
    }
    sum2=sum/(float)len;
    return sum2;
}