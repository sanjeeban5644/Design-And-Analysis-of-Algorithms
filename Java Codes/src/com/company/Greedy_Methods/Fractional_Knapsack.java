package com.company.Greedy_Methods;

import java.util.Arrays;
import java.util.Scanner;

public class Fractional_Knapsack {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter the total no.of Objects : ");
        int n = in.nextInt();
        int[] id = new int[n];
        int[] profit = new int[n];
        int[] weight = new int[n];
        float[] pw = new float[n];
        System.out.println("Enter the profits and weights in order : ");
        for (int i = 0; i < n; i++) {
            id[i]=i+1;
            profit[i] = in.nextInt();
            weight[i] = in.nextInt();
            pw[i] = profit[i]/(float)weight[i];
        }
        sort(id,profit,weight,pw,n);
        //Checking the sorted arrays
//        for(int i : id){
//            System.out.print(i+" ");
//        }
//        System.out.println();
//        for(int i : profit){
//            System.out.print(i+" ");
//        }
//        System.out.println();
//        for(int i : weight){
//            System.out.print(i+" ");
//        }
        float[] solution = new float[n];

        float rw = 15.0f,total_p=0.0f;
        int p=0;
        while(rw>0){
            if(rw-weight[p]>=0){
                solution[p]=1;
                rw-=weight[p];
                total_p+=profit[p];
            }else{
                float temp = profit[p]*((rw)/(float)weight[p]);
                rw=-1.0f;
                solution[p]=temp;
                total_p+=temp;
            }
            p++;
        }

        System.out.println("Solution set is : "+Arrays.toString(solution));
        System.out.println("Total Profit is : "+total_p);
        in.close();
    }

    private static void sort(int[] id,int[] profit,int[] weight,float[] pw,int n){
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n-1-i; j++) {
                if(pw[j]<pw[j+1]){
                    float temp = pw[j];
                    pw[j] = pw[j+1];
                    pw[j+1] = temp;

                    int t = id[j];
                    id[j] = id[j+1];
                    id[j+1] = t;

                    t = profit[j];
                    profit[j] = profit[j+1];
                    profit[j+1] = t;

                    t = weight[j];
                    weight[j]=weight[j+1];
                    weight[j+1]=t;
                }
            }
        }
    }

}
