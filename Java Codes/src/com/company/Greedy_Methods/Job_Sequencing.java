package com.company.Greedy_Methods;

import java.util.Scanner;

public class Job_Sequencing {
    public static void main(String[] args) {
        int tp=0;
        Scanner in = new Scanner(System.in);
        System.out.println("Enter the total no.of jobs : ");
        int tj = in.nextInt();
        int[] id = new int[tj];
        int[] profit = new int[tj];
        int[] dl = new int[tj];
        int max_d=0;
        System.out.println("Enter the profit and deadlines : ");
        for (int i = 0; i < tj; i++) {
            System.out.print("Enter the profit for job "+i+" : ");
            int p = in.nextInt();
            profit[i]=p;
            System.out.print("Enter the deadline for job "+i+" : ");
            int d = in.nextInt();
            dl[i]=d;
            id[i]=i+1;
            if(d>max_d){
                max_d=d;
            }
        }
        int[] arr = new int[max_d];
        for(int i : arr){
            arr[i]=0;
        }
        //Checking the input by the user by printing the input data
//        for(int i : profit){
//            System.out.print(i+" ");
//        }
//        System.out.println();
//        for(int i : dl){
//            System.out.print(i+" ");
//        }
//        System.out.println();
//        for(int i : id){
//            System.out.print(i+" ");
//        }
        sort(id,profit,dl,tj);

        //Checking after sorting
//        for(int i : profit){
//            System.out.print(i+" ");
//        }
//        System.out.println();
//        for(int i : dl){
//            System.out.print(i+" ");
//        }
//        System.out.println();
//        for(int i : id){
//            System.out.print(i+" ");
//        }

        for (int i = 0; i < tj; i++) {
            int temp = dl[i];
            while(temp>0){
                if(arr[temp-1]==0){
                    arr[temp-1]=id[i];
                    tp+=profit[i];
                    break;
                }else{
                    temp--;
                }
            }
        }
        System.out.println();
//        for(int i : arr){
//            System.out.print(arr[i]);
//        }
        System.out.print("The Jobs Selected in order is : ");
        for (int i = 0; i < max_d; i++) {
            System.out.print("Job "+arr[i]+" ");
        }
        System.out.println();
        System.out.println("The total profit is : "+tp);
        in.close();
    }

    private static void sort(int[] id,int[] profit,int[] dl,int n){
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n-1-i; j++) {
                if(profit[j]<profit[j+1]){
                    int temp = profit[j];
                    profit[j]=profit[j+1];
                    profit[j+1]=temp;

                    temp = id[j];
                    id[j]=id[j+1];
                    id[j+1]=temp;

                    temp = dl[j];
                    dl[j]=dl[j+1];
                    dl[j+1]=temp;
                }
            }
        }
    }
}
