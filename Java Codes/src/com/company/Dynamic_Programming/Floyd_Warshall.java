package com.company.Dynamic_Programming;

import java.util.Scanner;

public class Floyd_Warshall {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter the number of vertices : ");
        int vertex = in.nextInt();
        System.out.println("Enter the number of edges : ");
        int edges = in.nextInt();

        int[][] mat = new int[vertex+1][vertex+1];
        for (int i = 1; i <= vertex; i++) {
            for (int j = 1; j <= vertex ; j++) {
                if(i==j){
                    mat[i][j]=0;
                }else{
                    mat[i][j]=9999;
                }
            }
        }
        System.out.println("Enter the edges in order : ");
        for (int i = 0; i < edges; i++) {
            int a = in.nextInt();
            int b = in.nextInt();
            int c = in.nextInt();
            mat[a][b]=c;
        }
        System.out.println("Printing the Adjacency Matrix");
        for (int i = 1; i <= vertex ; i++) {
            for (int j = 1; j <= vertex ; j++) {
                System.out.print(" "+mat[i][j]);
            }
            System.out.println();
        }

        for(int k=1;k<=vertex;k++){
            for(int i=1;i<=vertex;i++){
                for(int j=1;j<=vertex;j++){
                    mat[i][j] = mini(mat[i][j],mat[i][k]+mat[k][j]);
                }
            }
        }
        System.out.println("Printing the Shortest Path Matrix");
        for (int i = 1; i <= vertex ; i++) {
            for (int j = 1; j <= vertex ; j++) {
                System.out.print(" "+mat[i][j]);
            }
            System.out.println();
        }
        in.close();
    }

    private static int mini(int a,int b){
        return Math.min(a, b);
    }



}
