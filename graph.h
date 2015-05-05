#ifndef GRAPH_H_
#define GRAPH_H_

#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

typedef void* GRAPH_TYPE;
typedef struct Graph Graph;
typedef struct Edge Edge;
typedef struct Vertex Vertex;

struct Edge {
	int id;
	int weight;
	Vertex* v1;
	Vertex* v2;
};

struct Vertex {
	int id;
	GRAPH_TYPE value;
	Vector* edges;
};

struct Graph{
	int size;
	Vector* vertex_list;
	Vector* edge_list;
};

Edge* add_edge(Vertex* v1, Vertex* v2, int weight, Graph* graph);
Vertex* add_vertex(GRAPH_TYPE value, Graph* graph);
/*
// static constructors
Edge* edge_constructor(Vertex* v1, Vertex* v2, int weight);
Vertex* vertex_constructor(GRAPH_TYPE value);
*/
Graph* graph_constructor();
void print_graph(Graph *graph);
void print_edge(Edge *edge);
void print_vertex(Vertex *vertex);

Edge* get_edge(int edge_id);

Vertex* get_vertex(int vertex_id);

Vector* adjacent_vertices(Vertex *vertex);

#endif