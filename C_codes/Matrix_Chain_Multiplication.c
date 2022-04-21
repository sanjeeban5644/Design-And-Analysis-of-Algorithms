#include<stdio.h>

#define INF 9999;
int costmat[10][10],kmat[10][10];

void Cost_Table_Generation(int [],int );
void print_Cost_Table(int );
void print_optimal(int ,int );
int matrix_chain_multiplication(int [],int ,int );

int main(){
    int n,i,j;
    
    printf("\nEnter the total no.of matrices : ");
    scanf("%d",&n);
    int dimarray[n];
    for(i=1;i<=n;i++){
        for(j=i+1;j<=n;j++){
            costmat[i][i]=0;
            costmat[i][j]=INF;
            kmat[i][j]=0;
        }
    }
    printf("\nEnter the dimensions of the matrices : ");
    for(i=0;i<n;i++){
        printf("D%d - ",i);
        scanf("%d",&dimarray[i]);
    }
    Cost_Table_Generation(dimarray,n);
    print_Cost_Table(n);
    i=1,j=n;
    printf("\nMultiplication Sequence : ");
    print_optimal(i,j);
    printf("\n\nThe minimum no.of multiplications is : %d",matrix_chain_multiplication(dimarray,1,n));

    return 0;
}

 int matrix_chain_multiplication(int arr[],int i,int j){
     if(i==j){
         return 0;
     }
     int min = INF;
     int result,k;
     for(k=i;k<j;k++){
         result = matrix_chain_multiplication(arr,i,k)+matrix_chain_multiplication(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
         if(result<min){
             min = result;
         }
     }
     return min;
 }


void print_optimal(int i,int j){
    if(i==j){
        printf("M%d",i);
    }
    else{
        printf("(");
        print_optimal(i,kmat[i][j]);
        print_optimal(kmat[i][j]+1,j);
        printf(")");
    }
}

void print_Cost_Table(int n){
    int i,j;
    for(i=1;i<=n;i++){
        for(j=i;j<=n;j++){
            printf(" %d",costmat[i][j]);
        }
        printf("\n");
    }
}

void Cost_Table_Generation(int arr[],int n){
    long int t;
    int k,i,j;
    for(i=n;i>0;i--){
        for(j=i;j<=n;j++){
            if(i==j){
                costmat[i][j]=0;
            }
            else{
                for(k=i;k<j;k++){
                    t = costmat[i][k]+costmat[k+1][j]+(arr[i-1]*arr[k]*arr[j]);
                    if(t<costmat[i][j]){
                        costmat[i][j]=t;
                        kmat[i][j]=k;
                    }
                }
            }
        }
    }
}
