// Prim's Algorithm in C

#include<stdio.h>
#include<stdbool.h> 
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

#pragma warning(disable : 4996)
#define INF 9999999

// number of vertices in graph
#define V 5

void generate_matrix()
{
    for (int i = 0; i <V; i++) {
        for (int j = 0; j < V; j++) {
            if (j > i) {
                matrix[i][j] = rand() % 2;
                matrix[j][i] = matrix[i][j];
            }
            else if (i == j) matrix[i][j] = 0;
        }
    }
}

int main() {
    int no_edge;  

 
    int selected[V];

  
    memset(selected, false, sizeof(selected));


    no_edge = 0;

    

   
    selected[0] = true;

    int x;  //  row number
    int y;  //  col number

   
    printf("Edge : Weight\n");

    while (no_edge < V - 1) {
      

        int min = INF;
        x = 0;
        y = 0;

        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && G[i][j]) { 
                        if (min > matrix[i][j]) {
                            min = matrix[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        printf("%d - %d : %d\n", x, y, matrix[x][y]);
        selected[y] = true;
        no_edge++;
    }

    return 0;
