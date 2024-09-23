#include <stdio.h>
// Function to find the maximum value in the knapsack
int knapsack(int W, int weights[], int values[], int n) {
 int dp[n + 1][W + 1];
 // Initialize the dp array
 for (int i = 0; i <= n; i++) {
 for (int w = 0; w <= W; w++) {
 if (i == 0 || w == 0) {
 dp[i][w] = 0;
 } else if (weights[i - 1] <= w) {
 dp[i][w] = (values[i - 1] + dp[i - 1][w - weights[i - 1]] >
dp[i - 1][w]) ?
 (values[i - 1] + dp[i - 1][w - weights[i - 1]])
:
 dp[i - 1][w];
 } else {
 dp[i][w] = dp[i - 1][w];
 }
 }
 }
 // The maximum value that can be carried is in dp[n][W]
 return dp[n][W];
}
int main() {
 int n, W;
 // Input: number of items
 printf("Enter the number of items: ");
 scanf("%d", &n);
 int weights[n], values[n];
 // Input: weights and values of items
 printf("Enter the weights of the items:\n");
 for (int i = 0; i < n; i++) {
 scanf("%d", &weights[i]);
 }
 printf("Enter the values of the items:\n");
 for (int i = 0; i < n; i++) {
 scanf("%d", &values[i]);
 }
 // Input: maximum weight capacity
 printf("Enter the maximum weight capacity of the knapsack: ");
 scanf("%d", &W);
 // Compute and print the maximum value
 int result = knapsack(W, weights, values, n);
 printf("The maximum value that can be carried is: %d\n", result);
 return 0;
}

