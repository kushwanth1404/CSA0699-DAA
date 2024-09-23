#include <stdio.h> 
// Function to perform selection sort 
void selectionSort(int arr[], int n) { 
int i, j, min_idx, temp; 
    // Iterate over the array 
    for (i = 0; i < n-1; i++) { 
        // Assume the minimum element is the first element of the unsorted part
        min_idx = i; 
         
        // Find the actual minimum element in the unsorted part 
        for (j = i+1; j < n; j++) { 
            if (arr[j] < arr[min_idx]) { 
                min_idx = j; 
            } 
        } 
         
        // Swap the found minimum element with the first element of the unsorted part 
        temp = arr[min_idx]; 
        arr[min_idx] = arr[i]; 
        arr[i] = temp; 
    } 
} 
 
// Function to print an array 
void printArray(int arr[], int size) { 
    int i; 
    for (i = 0; i < size; i++) { 
        printf("%d ", arr[i]); 
    } 
    printf("\n"); 
} 
 
int main() { 
    int n, i; 
 
    // Input: Number of elements in the array 
    printf("Enter the number of elements in the array: "); 
    scanf("%d", &n); 
 
    // Declare an array of size n 
    int arr[n]; 
 
    // Input: Elements of the array 
    printf("Enter the elements of the array:\n"); 
    for (i = 0; i < n; i++) { 
        scanf("%d", &arr[i]); 
    } 
 
    // Perform selection sort 
    selectionSort(arr, n); 
 
    // Output: Sorted array 
    printf("Sorted array: \n"); 
    printArray(arr, n); 
 
    return 0; 
} 