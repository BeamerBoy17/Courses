#pragma once
#include<iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <queue>
#include <ctime>
#pragma warning(disable : 4996)
#define INF 9999999
using namespace std;

typedef struct Graph {
    int** matrix;
    int     size;
   
}Graph;

int** matrix(int size);
void generate_matrix(Graph* graph);

Graph* init_graph(int size);
void free_graph(Graph* graph);
void print_graph(Graph* graph, FILE* stream);
void prim_auto(Graph* graph, FILE* stream);

Graph* init_manually();

Graph* read_graph(const char* fname);
