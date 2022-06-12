package com.company.Dynamic_Programming;

import java.util.Scanner;

public class Bellman_Ford {
    public static void main(String[] args) {
        int flag=1;
        Scanner in = new Scanner(System.in);
        System.out.println("Enter the total no.of vertices : ");
        int vertex = in.nextInt();
        System.out.println("Enter the total no.of edges : ");
        int edges = in.nextInt();
        int[] distance = new int[vertex+1];
        for (int i = 1; i <= vertex; i++) {
            distance[i]=9999;
        }

        int[] cost = new int[edges+1];
        int[] start = new int[edges+1];
        int[] end = new int[edges+1];
        System.out.println("Enter the edges and cost in order : ");
        for (int i = 1; i <= edges ; i++) {
            int s = in.nextInt();
            int f = in.nextInt();
            int c = in.nextInt();
            start[i]=s;
            end[i]=f;
            cost[i]=c;
        }
        int[] ans = new int[vertex+1];
        System.out.println();
        System.out.print("Enter the start vertex : ");
        int begin = in.nextInt();
        distance[begin]=0;
        for (int i = 1; i <= vertex-1; i++) {
            for (int j = 1; j <= edges ; j++) {
                if(distance[start[j]]+cost[j]<distance[end[j]]){
                    distance[end[j]]=distance[start[j]]+cost[j];
                }
            }
        }
        int[] duplicate = new int[vertex+1];
        for (int i = 0; i <= vertex; i++) {
            duplicate[i]=distance[i];
        }
        // Checking for negative cycle
        for (int j = 1; j <= edges ; j++) {
            if(distance[start[j]]+cost[j]<distance[end[j]]){
                distance[end[j]]=distance[start[j]]+cost[j];
            }
        }
        for (int i = 0; i <=vertex ; i++) {
            if(duplicate[i]!=distance[i]){
                flag=0;
            }
        }
        System.out.println();
        if(flag==0){
            System.out.println("Negative Edge Cycle Detected!");
        }

        if(flag==1){
            System.out.println();
            System.out.println("The Shortest Path is : ");
            for (int i = 1; i <= vertex ; i++) {
                System.out.println("Vertex "+i+" : "+distance[i]);
            }
        }
        in.close();
    }
}
