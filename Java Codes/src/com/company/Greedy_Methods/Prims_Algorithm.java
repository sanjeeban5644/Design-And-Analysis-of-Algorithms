package com.company.Greedy_Methods;

import java.util.Scanner;

public class Prims_Algorithm {
    public static void main(String[] args) {
        int count=1,u=0,v=0;
        Scanner in = new Scanner(System.in);
        System.out.println("Enter the no.of vertices : ");
        int vertex = in.nextInt();
        System.out.println("Enter the no.of edges : ");
        int edges = in.nextInt();
        int[][] mat = new int[vertex+1][vertex+1];
        for (int i = 1; i <= vertex ; i++) {
            for (int j = 1; j <= vertex ; j++) {
                mat[i][j]=9999;
            }
        }
        System.out.println("Enter the edges in order : ");
        for (int i = 1; i <= edges ; i++) {
            int a = in.nextInt();
            int b = in.nextInt();
            int c = in.nextInt();
            mat[a][b]=c;
            mat[b][a]=c;
        }
        //Optional
//        System.out.println("Printing the Adjacency Matrix : ");
//        for (int i = 1; i <=vertex ; i++) {
//            for (int j = 1; j <=vertex ; j++) {
//                System.out.print(" "+mat[i][j]);
//            }
//            System.out.println();
//        }
        int[] visited = new int[vertex+1];
        for(int i: visited){
            visited[i]=0;
        }
        System.out.println("Enter the Source Vertex : ");
        int source = in.nextInt();
        visited[source]=1;
        int totcost=0;
        //Main Logic
        while(count<vertex){
            int a = 0,b=0;
            for (int i = 1,min=9999; i <=vertex ; i++) {
                for (int j = 1; j <=vertex ; j++) {
                    if(mat[i][j]<min){
                        if(visited[i]!=0){
                            min = mat[i][j];
                            a=u=i;
                            b=v=j;
                        }
                        if(visited[u]==0 || visited[v]==0){
                            System.out.println("Edge "+count+" : "+a+"->"+b+" = "+min);
                            count++;
                            totcost+=min;
                            visited[b]=1;
                        }
                    }
                }
                mat[a][b]=mat[b][a]=9999;
            }
        }
        System.out.println("The Total Cost is : "+totcost);

    }
}
