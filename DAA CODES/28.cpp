#include <stdio.h>
// Function to generate Pascal's Triangle
void printPascalsTriangle(int n) {
 int triangle[n][n]; // Declare a 2D array to store Pascal's Triangle
 // Initialize the Pascal's Triangle
 for (int i = 0; i < n; i++) {
 for (int j = 0; j <= i; j++) {
 if (j == 0 || j == i) {
 triangle[i][j] = 1; // First and last element of each row are 1
 } else {
 triangle[i][j] = triangle[i - 1][j - 1] + triangle[i -
1][j]; // Sum of two elements above
 }
 }
 }
 // Print Pascal's Triangle
 for (int i = 0; i < n; i++) {
 // Print leading spaces for alignment
 for (int j = 0; j < n - i - 1; j++) {
 printf(" ");
 }
 // Print elements of the current row
 for (int j = 0; j <= i; j++) {
 printf("%d ", triangle[i][j]);
 }
 printf("\n"); // Move to the next line
 }
}
int main() {
 int n;
 // Input: number of rows
 printf("Enter the number of rows for Pascal's Triangle: ");
 scanf("%d", &n);
 // Print Pascal's Triangle
 printPascalsTriangle(n);
 return 0;
}

