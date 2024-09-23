#include <stdio.h>
#include <stdbool.h>
#define MAX_VERTICES 100
// Function to check if the current color assignment is safe for vertex `v`
bool isSafe(int graph[MAX_VERTICES][MAX_VERTICES], int color[], int v, int
c, int V) {
 for (int i = 0; i < V; i++) {
 if (graph[v][i] && color[i] == c) {
 return false;
 }
 }
 return true;
}
// Recursive function to solve the graph coloring problem
bool graphColoringUtil(int graph[MAX_VERTICES][MAX_VERTICES], int color[],
int v, int m, int V) {
 // Base case: If all vertices are assigned a color then return true
 if (v == V) {
 return true;
 }
 // Try different colors for vertex `v`
 for (int c = 1; c <= m; c++) {
 if (isSafe(graph, color, v, c, V)) {
 color[v] = c; // Assign color `c` to vertex `v`
 // Recur to assign colors to the rest of the vertices
 if (graphColoringUtil(graph, color, v + 1, m, V)) {
 return true;
 }
 // If assigning color `c` doesn't lead to a solution then remove it
 color[v] = 0;
 }
 }
 return false;
}
// Function to solve the graph coloring problem
bool graphColoring(int graph[MAX_VERTICES][MAX_VERTICES], int V, int m) {
 int color[V];
 for (int i = 0; i < V; i++) {
 color[i] = 0; // Initialize all vertices with no color
 }
 // Call the recursive function to solve the problem
 return graphColoringUtil(graph, color, 0, m, V);
}
// Function to print the color assignment
void printSolution(int color[], int V) {
 printf("Solution:\n");
 for (int i = 0; i < V; i++) {
 printf("Vertex %d ---> Color %d\n", i, color[i]);
 }
}
int main() {
 int V, E, m;
 int graph[MAX_VERTICES][MAX_VERTICES] = {0};
 // Input: number of vertices
 printf("Enter the number of vertices: ");
 scanf("%d", &V);
 // Input: number of edges
 printf("Enter the number of edges: ");
 scanf("%d", &E);
 // Input: edges of the graph
 printf("Enter the edges (format: u v):\n");
 for (int i = 0; i < E; i++) {
 int u, v;
 scanf("%d %d", &u, &v);
 graph[u][v] = 1;
 graph[v][u] = 1;
 }
 // Input: number of colors
 printf("Enter the number of colors: ");
 scanf("%d", &m);
 // Solve the graph coloring problem
 if (graphColoring(graph, V, m)) {
 printf("Solution exists with %d colors:\n", m);
 void printSolution (int color[], int V);
 } else {
 printf("Solution does not exist with %d colors.\n", m);
 }
 return 0;
}

