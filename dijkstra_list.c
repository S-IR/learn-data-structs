#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h> // Include this header for `memmove`
#include <stdint.h> // Include this header for `intptr_t`
#include "dynamic_array.h"
#include "queue_list.h"
#include "adjacency_list.h"

#define V 5

// Dijkstra's algorithm implementation
bool hasUnvisited(bool seen[], int dists[])
{
  for (int i = 0; i < V; i++)
  {
    if (!seen[i] && dists[i] != __INT_MAX__)
    {
      return true;
    }
  }
  return false;
}

int getLowestUnvisited(bool seen[V], int dists[V])
{
  int index = -1;
  int lowestDistance = __INT_MAX__;

  for (int i = 0; i < V; ++i)
  {
    if (seen[i])
    {
      continue;
    }

    if (lowestDistance > dists[i])
    {
      lowestDistance = dists[i];
      index = i;
    }
  }
  return index;
}

ArrayList *dijkstra_list(int source, int sink, Graph *graph) // Corrected function name
{
  bool seen[V];
  int prev[V];
  int dists[V];

  for (int i = 0; i < V; i++)
  {
    seen[i] = false;
    prev[i] = -1;
    dists[i] = __INT_MAX__;
  }
  dists[source] = 0;

  while (hasUnvisited(seen, dists))
  {
    int curr = getLowestUnvisited(seen, dists);
    seen[curr] = true;
    ArrayList *edges = getEdgesForVertex(graph, curr);

    for (int i = 0; i < edges->size; i++)
    {
      Edge *edge = (Edge *)get_element(edges, i);
      if (seen[edge->dest])
      {
        continue;
      }
      int dist = dists[curr] + edge->weight;
      if (dist < dists[edge->dest])
      {
        dists[edge->dest] = dist;
        prev[edge->dest] = curr;
      }
    }
  }

  ArrayList *out = create_array_list(5);
  int curr = sink;

  while (prev[curr] != -1)
  {
    add_element(out, (void *)(intptr_t)curr); // Cast int to void*
    curr = prev[curr];
  }

  add_element(out, (void *)(intptr_t)source); // Cast int to void*
  reverse_array_list(out);
  return out;
}

// Main program
int main()
{
  Graph *graph = createGraph(V);

  addEdge(graph, 0, 1, 2);
  addEdge(graph, 0, 4, 6);
  addEdge(graph, 1, 2, 3);
  addEdge(graph, 1, 3, 8);
  addEdge(graph, 1, 4, 5);
  addEdge(graph, 2, 3, 7);
  addEdge(graph, 3, 4, 9);

  printf("Adjacency List of the graph:\n");
  printGraph(graph);

  int source = 0;
  int sink = 3;
  ArrayList *path = dijkstra_list(source, sink, graph);

  printf("Shortest path from %d to %d:\n", source, sink);
  for (size_t i = 0; i < path->size; i++)
  {
    int vertex = (int)(intptr_t)get_element(path, i); // Cast void* to int
    printf("%d ", vertex);
  }
  printf("\n");

  free_array_list(path);
  free(graph->array);
  free(graph);

  return 0;
}
