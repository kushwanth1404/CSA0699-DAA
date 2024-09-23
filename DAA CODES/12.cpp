#include <stdio.h> 
// Function to perform binary search 
int binarySearch(int arr[], int size, int target) { 
int low = 0; 
int high = size - 1; 
int mid; 
while (low <= high) { 
mid = low + (high - low) / 2; 
// Check if target is present at mid 
if (arr[mid] == target) { 
return mid; // Target found 
} 
// If target is smaller, ignore the right half 
if (arr[mid] > target) { 
high = mid - 1; 
} 
// If target is larger, ignore the left half 
else { 
low = mid + 1; 
} 
} 
return -1; // Target not found 
} 
int main() { 
int n, target, result; 
// Input: Number of elements 
printf("Enter the number of elements in the array: "); 
scanf("%d", &n); 
// Declare an array of size n 
int arr[n]; 
// Input: Elements of the array 
printf("Enter the elements of the sorted array:\n"); 
for (int i = 0; i < n; i++) { 
scanf("%d", &arr[i]); 
} 
// Input: Target value to search 
printf("Enter the target value to search: "); 
scanf("%d", &target); 
// Perform binary search 
result = binarySearch(arr, n, target); 
// Output: Result of binary search 
if (result != -1) { 
printf("Element %d found at index %d.\n", target, result); 
} else { 
printf("Element %d not found in the array.\n", target); 
} 
return 0; 
} 