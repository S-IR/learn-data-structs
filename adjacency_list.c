#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array.h"
#include <stdbool.h>
#include <math.h>
#include "queue_list.h"
#include "adjacency_list.h"

// Function to create a new adjacency list node
struct AdjListNode *newAdjListNode(int dest, int weight)
{
  struct AdjListNode *newNode = (struct AdjListNode *)malloc(sizeof(struct AdjListNode));
  newNode->dest = dest;
  newNode->weight = weight;
  newNode->next = NULL;
  return newNode;
}

// Function to create a graph with V vertices
struct Graph *createGraph(int V)
{
  struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
  graph->V = V;

  // Create an array of adjacency lists, size of V
  graph->array = (struct AdjList *)malloc(V * sizeof(struct AdjList));

  // Initialize each adjacency list as empty by making head as NULL
  for (int i = 0; i < V; ++i)
  {
    graph->array[i].head = NULL;
  }

  return graph;
}

// Function to add an edge to an undirected graph
void addEdge(Graph *graph, int src, int dest, int weight)
{
  // Add an edge from src to dest
  struct AdjListNode *newNode = newAdjListNode(dest, weight);
  newNode->next = graph->array[src].head;
  graph->array[src].head = newNode;

  // Since the graph is undirected, add an edge from dest to src also
  newNode = newAdjListNode(src, weight);
  newNode->next = graph->array[dest].head;
  graph->array[dest].head = newNode;
}

// Function to print the adjacency list representation of graph
void printGraph(Graph *graph)
{
  for (int v = 0; v < graph->V; ++v)
  {
    struct AdjListNode *crawler = graph->array[v].head;
    printf("Adjacency list of vertex %d\n head ", v);
    while (crawler)
    {
      printf("-> %d(%d) ", crawler->dest, crawler->weight);
      crawler = crawler->next;
    }
    printf("\n");
  }
}

ArrayList *getEdgesForVertex(Graph *graph, int vertex)
{
  ArrayList *edges = create_array_list(10); // Initial capacity of 10, can be adjusted
  struct AdjListNode *crawler = graph->array[vertex].head;

  while (crawler)
  {
    Edge *edge = (Edge *)malloc(sizeof(Edge));
    edge->dest = crawler->dest;
    edge->weight = crawler->weight;
    add_element(edges, edge);
    crawler = crawler->next;
  }

  return edges;
}

// Function to print edges
void printEdges(ArrayList *edges)
{
  for (size_t i = 0; i < edges->size; i++)
  {
    Edge edge = *(Edge *)get_element(edges, i);
    printf("-> %d(%d) ", edge.dest, edge.weight);
  }
  printf("\n");
}
