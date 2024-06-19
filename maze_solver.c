#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
  int x;
  int y;
} Point;
Point *create_point(int x, int y)
{
  Point *p = (Point *)malloc(sizeof(Point));
  if (p == NULL)
  {
    perror("Failed to allocate memory for Point");
    return NULL;
  }
  // Set the coordinates
  p->x = x;
  p->y = y;
  return p;
}

#define ROW_LEN 10
#define COL_LEN 10

typedef struct
{
  Point *data;
  size_t size;
  size_t capacity;
} DynamicArray;

DynamicArray *create_dynamic_array(size_t initial_capacity);
void push(DynamicArray *array, Point element);
Point pop(DynamicArray *array);
void free_dynamic_array(DynamicArray *array);
void resize_if_needed(DynamicArray *array);

DynamicArray *create_dynamic_array(size_t initial_capacity)
{
  DynamicArray *array = (DynamicArray *)malloc(sizeof(DynamicArray));
  array->data = (Point *)malloc(initial_capacity * sizeof(Point));

  array->size = 0;
  array->capacity = initial_capacity;
  return array;
}

void push(DynamicArray *array, Point element)
{
  if (array->size >= array->capacity)
  {
    array->capacity *= 2;
    array->data = (Point *)realloc(array->data, array->capacity * sizeof(Point));
    if (!array->data)
    {
      perror("Failed to reallocate memory for array data");
      exit(EXIT_FAILURE);
    }
  }
  array->data[array->size++] = element;
}
Point pop(DynamicArray *array)
{
  if (array->size == 0)
  {
    fprintf(stderr, "Cannot pop from an empty array\n");
    exit(EXIT_FAILURE);
  }
  return array->data[--array->size];
}

void resize_if_needed(DynamicArray *array)
{
  if (array->size >= array->capacity)
  {
    array->capacity *= 2;
    array->data = (Point *)realloc(array->data, array->capacity * sizeof(Point));
  }
}
void free_dynamic_array(DynamicArray *array)
{
  free(array->data);
  free(array);
}
#define dirLen 4
#define dirROW_LEN 2
const int dir[dirLen][dirROW_LEN] = {
    {-1, 0}, // Up
    {1, 0},  // Down
    {0, -1}, // Left
    {0, 1}   // Right
};
bool walk(char maze[COL_LEN][ROW_LEN], char wall, Point curr, Point end, bool seen[COL_LEN][ROW_LEN], DynamicArray *path)
{
  if (curr.x < 0 || curr.x >= COL_LEN || curr.y < 0 || curr.y >= ROW_LEN)
  {
    return false;
  }
  if (maze[curr.y][curr.x] == wall || seen[curr.y][curr.x])
  {
    return false;
  }
  if (curr.x == end.x && curr.y == end.y)
  {
    push(path, end);
    return true;
  }

  seen[curr.y][curr.x] = true;
  push(path, curr);

  for (int i = 0; i < 4; ++i)
  {
    Point next = {curr.x + dir[i][0], curr.y + dir[i][1]};
    if (walk(maze, wall, next, end, seen, path))
    {
      return true;
    }
  }

  pop(path);
  seen[curr.y][curr.x] = false;
  return false;
};

DynamicArray *solve(char maze[COL_LEN][ROW_LEN], char wall, Point start, Point end)
{
  bool seen[COL_LEN][ROW_LEN] = {{false}};
  DynamicArray *path = create_dynamic_array(5);

  if (!walk(maze, wall, start, end, seen, path))
  {
    free_dynamic_array(path);
    return NULL;
  }
  return path;
}
int main()
{
  char maze[COL_LEN][ROW_LEN] = {
      {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
      {'#', '0', '0', '0', '0', '0', '0', '0', '0', '#'},
      {'#', '0', '#', '#', '#', '#', '#', '#', '0', '#'},
      {'#', '0', '#', '0', '0', '0', '0', '#', '0', '#'},
      {'#', '0', '#', '0', '#', '#', '0', '#', '0', '#'},
      {'#', '0', '#', '0', '#', '0', '0', '#', '0', '#'},
      {'#', '0', '#', '0', '#', '0', '#', '#', '0', '#'},
      {'#', '0', '#', '0', '#', '0', '0', '0', '0', '#'},
      {'#', '0', '#', '0', '#', '#', '#', '#', '0', '#'},
      {'#', '0', '0', '0', '0', '0', '0', '0', 'E', '#'},
      {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}};

  Point start = {1, 1};
  Point end = {8, 8};
  char wall = '#';

  DynamicArray *path = solve(maze, wall, start, end);

  if (path != NULL)
  {
    printf("Path found:\n");
    for (size_t i = 0; i < path->size; i++)
    {
      printf("(%d, %d) ", path->data[i].x, path->data[i].y);
    }
    printf("\n");
    free_dynamic_array(path);
  }
  else
  {
    printf("No path found.\n");
  }

  return 0;
}