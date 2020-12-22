#include "Matrix_graph.h"

int main() {
    int d;

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

    if (d == '1') {
        prim_auto(graph, output);
    }
    if (d == '2') {
        prim_auto(graph, NULL);
    }

    return 0;
}


