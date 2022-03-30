#include<stdio.h>
#include<stdlib.h>

void sortmaxprofit(int [],int [],int [],float [],int );
void sortratio(float [],int [],int [],int [],int );
float knapsack(int [],int [],int [],int ,int );
void sortminweight(int [],int [],int [],float [],int );

int main(){
    int n,i,limit;
    char ch;
    printf("\nEnter the total no.of items : ");
    scanf("%d",&n);
    printf("\nEnter the limit : ");
    scanf("%d",&limit);
    int profit[n],weight[n],id[n];
    float ratio[n];
    for(i=0;i<n;i++){
        printf("\n\nEntry - %d",i+1);
        printf("\nEnter the id : ");scanf("%d",&id[i]);
        printf("\nEnter the profit : ");scanf("%d",&profit[i]);
        printf("\nEnter the weight : ");scanf("%d",&weight[i]);
        ratio[i] = (float)profit[i]/weight[i];
    }
    system("cls");
    int choice=0;
    while(choice<4){
        system("cls");
        printf("\n1-> Calculate Profit using maximum profit method");
        printf("\n2-> Calculate Profit using minimum weight method");
        printf("\n3-> Calculate Profit using ratio method");
        printf("\n4-> Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1: {
                sortmaxprofit(profit,weight,id,ratio,n);
				float ans = knapsack(profit,weight,id,limit,n);
                printf("\nThe Total Profit is : %f",ans);
                printf("\n\nPress 'y' to continue : ");
                scanf(" %c",&ch);
                break;
            }
            case 2: {
            	sortminweight(weight,profit,id,ratio,n);
            	float ans = knapsack(profit,weight,id,limit,n);
            	printf("\nThe Total Profit is : %f",ans);
                printf("\n\nPress 'y' to continue : ");
                scanf(" %c",&ch);
                break;
            }
            case 3: {
            	sortratio(ratio,profit,weight,id,n);
            	float ans = knapsack(profit,weight,id,limit,n);
            	printf("\nThe Total Profit is : %f",ans);
            	printf("\n\nPress 'y' to continue : ");
            	scanf(" %c",&ch);
                break;
            }
            default : {
                printf("\nProgram ended!");printf("\nThankyou");
                break;
            }
        }
    }
    return 0;

}

void sortminweight(int a[],int b[],int c[],float d[],int n){
	int i,j,temp;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(a[j]>a[j+1]){
				
				temp = a[j];
                a[j]=a[j+1];
                a[j+1]=temp;

                temp = b[j];
                b[j]=b[j+1];
                b[j+1]=temp;

                temp = c[j];
                c[j]=c[j+1];
                c[j+1]=temp;

                temp = d[j];
                d[j]=d[j+1];
                d[j+1]=temp;
			}
		}
	}
}

void sortmaxprofit(int a[],int b[],int c[],float d[],int n){
    int i,j,temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(a[j]<a[j+1]){

                temp = a[j];
                a[j]=a[j+1];
                a[j+1]=temp;

                temp = b[j];
                b[j]=b[j+1];
                b[j+1]=temp;

                temp = c[j];
                c[j]=c[j+1];
                c[j+1]=temp;

                temp = d[j];
                d[j]=d[j+1];
                d[j+1]=temp;
            }
        }
    }

}

void sortratio(float a[],int b[],int c[],int d[],int n){
	int i,j,temp;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(a[j]<a[j+1]){

				a[j]=a[j]+a[j+1];
				a[j+1]=a[j]-a[j+1];
				a[j]=a[j]-a[j+1];

                temp = b[j];
                b[j]=b[j+1];
                b[j+1]=temp;

                temp = c[j];
                c[j]=c[j+1];
                c[j+1]=temp;
                
                temp = d[j];
                d[j]=d[j+1];
                d[j+1]=temp;
			}
		}
	}
}

float knapsack(int p[],int w[],int id[],int limit,int n){
	int remaining_weight = limit,i=0,temp[n];
	for(i=0;i<n;i++){
		temp[i]=-1;
	}
	i=0;
	float totprofit = 0.0;
	while(remaining_weight!=0 && i<n){
		if(remaining_weight-w[i]<0){
			totprofit =  totprofit + (float)(p[i]*((float)remaining_weight)/w[i]);
            remaining_weight=0;
		}else{
			remaining_weight = remaining_weight-w[i];
            totprofit = totprofit + p[i];
		}
		temp[i]=id[i];
        i++;
	}
	
	printf("Objects selected : ");
	for(i=0;temp[i]!=-1;i++){
		printf(" %d",temp[i]);
		if(i==n-1){
			break;
		}
	}

	if(remaining_weight>0){
		printf("\nLeft Over Space in Knapsack is : %d",remaining_weight);
	}
    return totprofit;	
}