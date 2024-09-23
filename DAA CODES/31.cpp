#include <stdio.h>
// Function to find the minimum and maximum values in the list
void findMinMax(int arr[], int size, int *min, int *max) {
 *min = arr[0];
 *max = arr[0];

 for (int i = 1; i < size; i++) {
 if (arr[i] < *min) {
 *min = arr[i];
 }
 if (arr[i] > *max) {
 *max = arr[i];
 }
 }
}
int main() {
 int n;
 // Input: number of elements in the list
 printf("Enter the number of elements: ");
 scanf("%d", &n);
 int arr[n];

 // Input: elements of the list
 printf("Enter the elements:\n");
 for (int i = 0; i < n; i++) {
 scanf("%d", &arr[i]);
 }
 int min, max;
 // Find the minimum and maximum values
 findMinMax(arr, n, &min, &max);
 // Print the results
 printf("Minimum value: %d\n", min);
 printf("Maximum value: %d\n", max);
 return 0;
}

