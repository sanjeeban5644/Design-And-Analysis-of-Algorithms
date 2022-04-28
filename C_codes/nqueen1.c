#include<stdio.h>
#include<math.h>

int board[20][20];

int queen(int ,int ); 

int main()
{
 int n,i,j;
 //void queen(int row,int n);
 
 printf(" - N Queens Problem Using Backtracking -");
 printf("\n\nEnter number of Queens:");
 scanf("%d",&n);
 int board[n][n];
 int ans = queen(1,n);
 return 0;
}

 
int place(int row,int column)
{
 int i;
 for(i=1;i<=row-1;++i)
 {
  //checking column and digonal conflicts
  if(board[i]==column)
   return 0;
  else
   if(abs(board[i]-column)==abs(i-row))
    return 0;
 }
 return 1; 
}
 

int queen(int row,int n)
{
  int col;
 if(row==n){
   return 1;
 }
 for(col=0;col<n;col++){
   if(place(row,col)){
     board[row][col]=1;
     if(queen(row,row+1)){
       return 1;
     }
     board[row][col]=0;
   }
 }
 return 0;
}

