#include <stdio.h>
#include <limits.h>
#define N 4 // Number of tasks and workers
// Function prototypes
void assignmentProblem(int costMatrix[N][N]);
int branchAndBound(int costMatrix[N][N], int assignment[], int row, int n,
int bound, int currCost, int minCost, int visited[]);
// Helper function to calculate the lower bound for a given node
int calculateLowerBound(int costMatrix[N][N], int assignment[], int n, int
row, int visited[]);
// Helper function to find the minimum cost assignment
int findMinCost(int costMatrix[N][N], int assignment[], int n, int
currCost, int minCost, int visited[]);
int main() {
 int costMatrix[N][N] = {
 {10, 2, 8, 12},
 {9, 4, 7, 6},
 {5, 11, 13, 10},
 {7, 9, 16, 5}
 };
 assignmentProblem(costMatrix);
 return 0;
}
void assignmentProblem(int costMatrix[N][N]) {
 int assignment[N] = {-1}; // Store the assignment of tasks to workers
 int visited[N] = {0}; // Track visited nodes
 int minCost = INT_MAX; // Initialize minimum cost to a large value
 minCost = branchAndBound(costMatrix, assignment, 0, N, 0, 0, minCost,
visited);
 printf("Minimum cost is %d\n", minCost);
}
int branchAndBound(int costMatrix[N][N], int assignment[], int row, int n,
int bound, int currCost, int minCost, int visited[]) {
 if (row == n) {
 // All tasks are assigned
 if (currCost < minCost) {
 minCost = currCost;
 }
 return minCost;
 }
 for (int col = 0; col < n; col++) {
 if (!visited[col]) {
 // Mark this worker as visited
 visited[col] = 1;
 assignment[row] = col;
 // Calculate the lower bound for this node
 int newBound = bound + costMatrix[row][col];
 int lowerBound = calculateLowerBound(costMatrix, assignment, n,
row + 1, visited);
 // If the lower bound is less than the minimum cost found so far, explore further
 if (newBound + lowerBound < minCost) {
 minCost = branchAndBound(costMatrix, assignment, row + 1,
n, newBound, currCost + costMatrix[row][col], minCost, visited);
 }
 // Backtrack
 visited[col] = 0;
 assignment[row] = -1;
 }
 }
 return minCost;
}
int calculateLowerBound(int costMatrix[N][N], int assignment[], int n, int
row, int visited[]) {
 int bound = 0;
 // Calculate the lower bound using row reduction
 for (int i = row; i < n; i++) {
 int min1 = INT_MAX, min2 = INT_MAX;
 for (int j = 0; j < n; j++) {
 if (!visited[j] && costMatrix[i][j] < min1) {
 min2 = min1;
 min1 = costMatrix[i][j];
 } else if (!visited[j] && costMatrix[i][j] < min2) {
 min2 = costMatrix[i][j];
 }
 }
 bound += (min1 == INT_MAX) ? 0 : min1;
 bound += (min2 == INT_MAX) ? 0 : min2;
 }
 // Calculate the lower bound using column reduction
 for (int j = 0; j < n; j++) {
 int min1 = INT_MAX, min2 = INT_MAX;
 for (int i = row; i < n; i++) {
 if (!visited[j] && costMatrix[i][j] < min1) {
 min2 = min1;
 min1 = costMatrix[i][j];
 } else if (!visited[j] && costMatrix[i][j] < min2) {
 min2 = costMatrix[i][j];
 }
 }
 bound += (min1 == INT_MAX) ? 0 : min1;
 bound += (min2 == INT_MAX) ? 0 : min2;
 }
 return bound / 2;
}

