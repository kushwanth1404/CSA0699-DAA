#include <stdio.h>
// Function to calculate the sum of digits of a number
int sumOfDigits(int num) {
 int sum = 0;
 while (num != 0) {
 sum += num % 10; // Add the last digit to sum
 num /= 10; // Remove the last digit from the number
 }
 return sum;
}
int main() {
 int number;
 // Input: the number to find the sum of digits
 printf("Enter a number: ");
 scanf("%d", &number);
 // Handle negative numbers
 if (number < 0) {
 number = -number; // Convert to positive if the number is negative
 }
 // Compute and print the sum of digits
 int result = sumOfDigits(number);
 printf("The sum of digits is: %d\n", result);
 return 0;
}

