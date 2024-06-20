#ifndef ADJACENCY_LIST_H
#define ADJACENCY_LIST_H

// Structure to represent a node in the adjacency list
typedef struct AdjListNode
{
  int dest;
  int weight;
  struct AdjListNode *next; // use `struct` keyword here
} AdjListNode;

// Structure to represent an adjacency list
typedef struct AdjList
{
  struct AdjListNode *head; // pointer to head node of list
} AdjList;

// Structure to represent a graph
typedef struct Graph
{
  int V;          // Number of vertices
  AdjList *array; // An array of adjacency lists
} Graph;

typedef struct Edge
{
  int dest;
  int weight;
} Edge;

struct AdjListNode *newAdjListNode(int dest, int weight);
struct Graph *createGraph(int V);
void addEdge(Graph *graph, int src, int dest, int weight);
ArrayList *getEdgesForVertex(Graph *graph, int vertex);
void printGraph(Graph *graph);

#endif /* ADJACENCY_LIST_H */
