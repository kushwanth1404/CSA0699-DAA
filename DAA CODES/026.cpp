#include <stdio.h> 
 
// Function to print the pattern 
void printPattern(int n) { 
    for (int i = 1; i <= n; i++) { 
        // Print leading spaces 
        for (int j = 0; j < n - i; j++) { 
            printf(" "); 
        } 
        // Print numbers in the current row 
        for (int k = 1; k <= i; k++) { 
            printf("%d ", k); 
        } 
        printf("\n"); // Move to the next line 
    } 
} 
 
int main() { 
    int n; 
 
    // Input: number of rows 
    printf("Enter the number of rows (n): "); 
    scanf("%d", &n); 
 
    // Print the pattern 
    printPattern(n); 
 
    return 0; 
}