
#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array.h"
#include <stdbool.h>
#include <math.h>
#include "queue_list.h"

#define V 5

// Function to add an edge to an undirected graph
void addEdge(int graph[V][V], int src, int dest)
{
  graph[src][dest] = 1;
  graph[dest][src] = 1; // Comment this line for a directed graph
}

// Function to print the adjacency matrix
void printGraph(int graph[V][V])
{
  for (int i = 0; i < V; i++)
  {
    for (int j = 0; j < V; j++)
    {
      printf("%d ", graph[i][j]);
    }
    printf("\n");
  }
}

ArrayList *bfs(
    int graph[V][V],
    int source,
    int needle)
{
  bool seen[V];
  int prev[V];
  for (int i = 0; i < V; i++)
  {
    seen[i] = false;
    prev[i] = -1;
  }

  seen[source] = true;
  Queue *queue = createQueue();
  enqueue(queue, source);

  while (queue->length != 0)
  {
    int curr = dequeue(queue);

    for (int i = 0; i < V; i++)
    {
      if (graph[curr][i] == 0 || seen[i])
      {
        continue; // No edge or already visited
      }

      seen[i] = true;
      prev[i] = curr;
      enqueue(queue, i);

      if (i == needle)
      {
        // Found the needle, construct the path
        ArrayList *path = create_array_list(10); // Adjust initial capacity as needed
        int step = i;
        while (step != source)
        {
          add_element(path, step);
          step = prev[step];
        }
        add_element(path, source); // Add the source vertex
        reverse_array_list(path);
        return path;
      }
    }
  }

  if (prev[needle] == -1)
  {
    return NULL;
  }

  // build it backwards
  int curr = needle;
  ArrayList *out = create_array_list(3);
  while (prev[curr] != -1)
  {
    add_element(out, curr);
    curr = prev[curr];
  }
  if (out->size != 0)
  {
    reverse_array_list(out);
    add_element(out, source);
    return out;
  }
  return NULL;
}

int main()
{
  int graph[V][V] = {0}; // Initialize the matrix with 0s

  addEdge(graph, 0, 1);
  addEdge(graph, 0, 4);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 3);
  addEdge(graph, 1, 4);
  addEdge(graph, 2, 3);
  addEdge(graph, 3, 4);

  printf("Adjacency Matrix of the graph:\n");
  printGraph(graph);

  int source = 0;
  int needle = 3;

  ArrayList *path = bfs(graph, source, needle);

  if (path)
  {
    printf("Path from %d to %d: ", source, needle);
    for (size_t i = 0; i < path->size; i++)
    {
      printf("%d ", get_element(path, i));
    }
    printf("\n");
    free_array_list(path);
  }
  else
  {
    printf("No path found from %d to %d\n", source, needle);
  }

  return 0;
}