#include "Matrix_graph.h"
int first_false(bool* arr, int size) {
    for (size_t i = 0; i < size; i++) {
        if (!arr[i]) { return i; };
    }
    return -1;
}


void DFS(Graph* g, int v, bool* visited) {
    printf("%d,", v + 1);
    visited[v] = 1;
    for (size_t i = 0; i < g->size; i++) {
        if (g->matrix[v][i] == 1 && visited[i] == 0) {

            DFS(g, i, visited);
        }
    }


}

void component(Graph* g) {
    bool* visited = (bool*)calloc(g->size, 1);

    int next_vertex = 0;

    while (next_vertex != -1) {
        DFS(g, next_vertex, visited);
        printf("\n");
        next_vertex = first_false(visited, g->size);
    }

    free(visited);
}
int main() {
    int d;
    bool k=false;
   
   
    
    printf("\n ---> 1.Generate matrix");
    printf("\n ---> 2.Generate a matrix from file");
    printf("\n ---> 0.Exit");
    d = _getch();
    if (!d) { return 0; }

    Graph* graph;
    FILE* output = fopen("output.txt", "w");

    if(d == '1') {
      
        graph = init_manually();
    }
    else{
        graph = read_graph("input.txt");
    }
    printf("\n ---> 1.Save result");

    printf("\n ---> 2.Without saving");

    d = _getch();

    if (d == '0') {
        exit(0);
    }
    
    k = izo_matrix(graph);
    if (d == '1') {
        if (k) {
            printf("\n\n----> | There is no minimum spanning tree | <---- \n");
            
        }
        else
            prim_auto(graph, output);
    }
    if (d == '2') {
        printf("\n");
        if (k) {
            printf("\n\n----> | There is no minimum spanning tree | <---- \n");
           
            
        }
        else
            prim_auto(graph, NULL);
    }
    

    return 0;
}


