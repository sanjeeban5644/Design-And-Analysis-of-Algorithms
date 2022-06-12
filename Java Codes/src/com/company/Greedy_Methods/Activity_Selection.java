package com.company.Greedy_Methods;

import java.util.Scanner;

public class Activity_Selection {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the total Activities : ");
        int ta = in.nextInt();
        int[] id = new int[ta];
        int[] start = new int[ta];
        int[] finish = new int[ta];
        System.out.println("Enter the id,start and finish time : ");
        for (int i = 0; i < ta; i++) {
            id[i]=in.nextInt();
            start[i]=in.nextInt();
            finish[i]=in.nextInt();
        }
        sort(id,start,finish,ta);

        // Checking the arrays after sorting
//        for(int i : id){
//            System.out.print(i+" ");
//        }
//        System.out.println();
//        for(int i : start){
//            System.out.print(i+" ");
//        }
//        System.out.println();
//        for(int i : finish){
//            System.out.print(i+" ");
//        }

        System.out.println();
        System.out.print("The Activities selected are : ");
        System.out.print("A"+id[0]+" ");
        int temp = finish[0];
        for (int i = 1; i < ta; i++) {
            if(start[i]>temp){
                System.out.print("A"+id[i]+" ");
                temp=finish[i];
            }
        }
        in.close();

    }

    private static void sort(int[] id,int[] start,int[] finish,int n){
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n-1-i; j++) {
                if(finish[j]>finish[j+1]){
                    int temp = finish[j];
                    finish[j]=finish[j+1];
                    finish[j+1]=temp;

                    temp = id[j];
                    id[j]=id[j+1];
                    id[j+1]=temp;

                    temp = start[j];
                    start[j]=start[j+1];
                    start[j+1]=temp;
                }
            }
        }
    }

}
