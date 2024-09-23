#include <stdio.h> 
// Function to perform bubble sort 
void bubbleSort(int arr[], int n) { 
int i, j, temp; 
for (i = 0; i < n-1; i++) { 
// Last i elements are already in place 
for (j = 0; j < n-i-1; j++) { 
// Compare and swap if elements are in the wrong order 
if (arr[j] > arr[j+1]) { 
temp = arr[j]; 
arr[j] = arr[j+1]; 
arr[j+1] = temp; 
} 
} 
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
// Perform bubble sort 
bubbleSort(arr, n); 
// Output: Sorted array 
printf("Sorted array: \n"); 
printArray(arr, n); 
return 0; 
} 