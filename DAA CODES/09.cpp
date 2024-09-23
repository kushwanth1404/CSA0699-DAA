#include <stdio.h> 
// Function to multiply two matrices 
void multiplyMatrices(int firstMatrix[][10], int secondMatrix[][10], int 
resultMatrix[][10], int r1, int c1, int r2, int c2) { 
    int i, j, k; 
 
    // Initialize the result matrix to 0 
    for (i = 0; i < r1; i++) { 
        for (j = 0; j < c2; j++) { 
            resultMatrix[i][j] = 0; 
        } 
    } 
 
    // Multiply the matrices 
    for (i = 0; i < r1; i++) { 
        for (j = 0; j < c2; j++) { 
            for (k = 0; k < c1; k++) { 
                resultMatrix[i][j] += firstMatrix[i][k] * 
secondMatrix[k][j]; 
            } 
        } 
    } 
} 
 
// Function to print a matrix 
void printMatrix(int matrix[][10], int row, int col) { 
    int i, j; 
    for (i = 0; i < row; i++) { 
        for (j = 0; j < col; j++) { 
            printf("%d ", matrix[i][j]); 
        } 
        printf("\n"); 
    } 
} 
 
int main() { 
    int r1, c1, r2, c2, i, j; 
     
    // Input: Dimensions of the first matrix 
    printf("Enter the number of rows and columns of the first matrix: "); 
    scanf("%d %d", &r1, &c1); 
 
    // Input: Dimensions of the second matrix 
    printf("Enter the number of rows and columns of the second matrix: "); 
    scanf("%d %d", &r2, &c2); 
 
    // Ensure the matrices can be multiplied 
    if (c1 != r2) { 
        printf("Error! Column of the first matrix must be equal to row of the second matrix.\n"); 
        return -1; 
    } 
 
    // Declare the matrices 
    int firstMatrix[10][10], secondMatrix[10][10], resultMatrix[10][10]; 
 
    // Input: Elements of the first matrix 
    printf("Enter the elements of the first matrix:\n"); 
    for (i = 0; i < r1; i++) { 
        for (j = 0; j < c1; j++) { 
            scanf("%d", &firstMatrix[i][j]); 
        } 
    } 
 
    // Input: Elements of the second matrix 
printf("Enter the elements of the second matrix:\n"); 
for (i = 0; i < r2; i++) { 
for (j = 0; j < c2; j++) { 
scanf("%d", &secondMatrix[i][j]); 
} 
} 
// Multiply the matrices 
multiplyMatrices(firstMatrix, secondMatrix, resultMatrix, r1, c1, r2, 
c2); 
// Output: Result matrix 
printf("Resultant Matrix:\n"); 
printMatrix(resultMatrix, r1, c2); 
return 0; 
} 