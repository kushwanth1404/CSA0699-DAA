#include <stdio.h>
#include <stdbool.h>
#define V 5 // Number of vertices in the graph
// Function to check if the vertex can be added to the Hamiltonian path
bool isSafe(int graph[V][V], int path[], int pos) {
 // Check if this vertex is an adjacent vertex of the previously added vertex.
 if (graph[path[pos-1]][path[pos]] == 0) {
 return false;
 }
 // Check if the vertex has already been included.
 for (int i = 0; i < pos; i++) {
 if (path[i] == path[pos]) {
 return false;
 }
 }

 return true;
}
// Function to solve the Hamiltonian Circuit problem
bool hamCycleUtil(int graph[V][V], int path[], int pos) {
 // Base case: If all vertices are included in the path
 if (pos == V) {
 // And if there is an edge from the last included vertex to the first vertex
 return graph[path[pos-1]][path[0]] == 1;
 }
 // Try different vertices as the next candidate in the path
 for (int v = 1; v < V; v++) {
 if (isSafe(graph, path, pos)) {
 path[pos] = v;
 // Recur to build the rest of the path
 if (hamCycleUtil(graph, path, pos + 1)) {
 return true;
 }
 // If adding vertex v doesn't lead to a solution, remove it
 path[pos] = -1;
 }
 }
 return false;
}
// Function to find and print the Hamiltonian Circuit
void findHamiltonianCircuit(int graph[V][V]) {
 int path[V];
 for (int i = 0; i < V; i++) {
 path[i] = -1;
 }
 // Let the first vertex in the path be 0
 path[0] = 0;
 if (hamCycleUtil(graph, path, 1) == false) {
 printf("No Hamiltonian Circuit found\n");
 } else {
 printf("Hamiltonian Circuit found:\n");
 for (int i = 0; i < V; i++) {
 printf("%d ", path[i]);
 }
 printf("%d\n", path[0]);
 }
}
int main() {
 // Graph representation using adjacency matrix
 int graph[V][V] = {
 {0, 1, 1, 1, 0},
 {1, 0, 1, 1, 1},
 {1, 1, 0, 1, 1},
 {1, 1, 1, 0, 1},
 {0, 1, 1, 1, 0}
 };
 findHamiltonianCircuit(graph);
 return 0;
}

