#include <stdio.h> 
#include <limits.h> 
 
// Function to find the cost of the optimal binary search tree 
void optimalBST(float p[], int n) { 
    // Tables for storing minimum cost, root and weight 
    float e[n][n], w[n][n]; 
    int root[n][n]; 
 
    // Initialize tables 
    for (int i = 0; i < n; i++) { 
        e[i][i] = p[i]; 
        w[i][i] = p[i]; 
        root[i][i] = i; 
    } 
 
    // Fill tables for chains of increasing length 
    for (int len = 2; len <= n; len++) { 
        for (int i = 0; i <= n - len; i++) { 
            int j = i + len - 1; 
            e[i][j] = INT_MAX; 
            w[i][j] = w[i][j - 1] + p[j]; 
 
            // Try different roots and find the minimum cost 
            for (int k = i; k <= j; k++) { 
                float t = (k > i ? e[i][k - 1] : 0) + (k < j ? e[k + 1][j] 
: 0) + w[i][j]; 
                if (t < e[i][j]) { 
                    e[i][j] = t; 
                    root[i][j] = k; 
                } 
            } 
        } 
    } 
 
    // Print the minimum cost 
    printf("Minimum cost of the optimal BST: %.2f\n", e[0][n - 1]); 
 
    // Print the root table 
    printf("Root table:\n"); 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) { 
            printf("%2d ", root[i][j]); 
        } 
        printf("\n"); 
    } 
} 
 
int main() { 
    int n; 
 
    // Input: Number of keys 
    printf("Enter the number of keys: "); 
    scanf("%d", &n); 
 
    float p[n]; 
 
    // Input: Probabilities of the keys 
    printf("Enter the probabilities of the keys:\n"); 
    for (int i = 0; i < n; i++) { 
        printf("Probability of key %d: ", i + 1); 
        scanf("%f", &p[i]); 
    } 
 
    // Compute the optimal BST 
    optimalBST(p, n); 
 
    return 0; 
} 