#include "Matrix_graph.h"

Graph* init_manually() {
    int V;

    printf("\n Enter the matrix size: ");
    scanf("%d", &V);
    Graph* graph = init_graph(V);
    graph->size = V;

    return graph;
}

void prim_auto(Graph* graph, FILE* stream) {
    
    int no_edge;
    int* selected = (int*)calloc(graph->size, sizeof(int));

    no_edge = 0;


    selected[0] = true;

    int x;  //  Номер Строки
    int y;  //  Номер Столбца
    printf("   \n\n");

    print_graph(graph,stdout);
    if (stream){ print_graph(graph, stream); }

    printf("\n  Edge : Weight\n");
    if (stream){ fprintf(stream,"\n  Edge : Weight\n"); }
    while (no_edge < graph->size- 1) {
        int min = INF;
        x = 0;
        y = 0;
        for (int i = 0; i < graph->size; i++) {
            if (selected[i]) {
                for (int j = 0; j < graph->size; j++) {
                    if (!selected[j] && graph->matrix[i][j]) {
                        if (min > graph->matrix[i][j]) {
                            min = graph->matrix[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        printf("\n  %d - %d : %d\n", x, y, graph->matrix[x][y]);
        if (stream) { fprintf(stream, "\n  %d - %d : %d\n", x, y, graph->matrix[x][y]); }
       
    
        selected[y] = true;
        no_edge++;
    }
}
void generate_matrix(Graph* graph)
{
    for (int i = 0; i < graph->size; i++) {
        for (int j = 0; j < graph->size; j++) {

            if (j != i) {
                graph->matrix[i][j] = rand() % 100;
                graph->matrix[j][i] = graph->matrix[i][j];
            }
            else if (i == j) graph->matrix[i][j] = 0;


        }
    }
}
int izo_matrix(Graph* graph) {
    bool k = false;
    int* matri = (int*)malloc(graph->size * sizeof(int));
    for (int i = 0; i < graph->size; i++) {
        matri[i] = 0;

    }
    for (int i = 0; i < graph->size; i++) {
        for (int j = 0; j < graph->size; j++) {
            matri[i] = matri[i] + graph->matrix[i][j];
        }
    }
    for (int i = 0; i < graph->size; i++) {
        if (matri[i] == 0) {
            k = true;
        }
    }
    return k;
}

int** matrix(int V )
{   
    int** matrix = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++)
    {
        matrix[i] = (int*)malloc(V * sizeof(int));
    }
    return matrix;
}

Graph* init_graph(int V)
{
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->matrix = matrix(V);
    graph->size = V;
    srand(time(NULL));
    generate_matrix(graph);
    return graph;
};

void free_graph(Graph* graph)
{
    for (int i = 0; i < graph->size; i++)
    {
        free(graph->matrix[i]);
    }
    free(graph->matrix);
    free(graph);
}

void print_graph(Graph* graph,FILE* stream)
{
    for (int i = 0; i < graph->size; i++) {
       fprintf(stream,"%3d|", i);

        for (int j = 0; j < graph->size; j++) {
            fprintf(stream,"%3d ",graph->matrix[i][j]);
        }

        fprintf(stream,"\n");
    }

}
Graph* read_graph(const char* fname) {
    errno_t err;
    FILE* input;
    err = fopen_s(&input, fname, "r");

    if (err == 0) {
        int size = 0;

        char next_char = ' ';

        int position = ftell(input);
        do {
            if (next_char != ' ') {
                size++;
            }
            next_char = fgetc(input);
        } while (next_char != '\n');
        fseek(input, position, SEEK_SET);

        Graph* graph = init_graph(size);

            for (int i = 0; i < graph->size; i++) {
                for (int j = 0; j < graph->size; j++) {
          
                fscanf(input, "%d", &graph->matrix[i][j]);
            }
        }

        return graph;
    }
    else {
        printf("The file '%s' was not opened\n", fname);
        return NULL;
    }


}





