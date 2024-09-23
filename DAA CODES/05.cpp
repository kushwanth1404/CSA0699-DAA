#include <stdio.h> 
// Function to calculate the factorial of a number using iteration 
unsigned long long factorial(int n) { 
unsigned long long fact = 1; 
for (int i = 1; i <= n; ++i) { 
fact *= i; 
} 
return fact; 
} 
int main() { 
int num; 
// Input: Number to find the factorial of 
printf("Enter a number: "); 
scanf("%d", &num); 
// Check if the input number is non-negative 
if (num < 0) { 
printf("Factorial is not defined for negative numbers.\n"); 
} else { 
// Output: Factorial of the number 
printf("Factorial of %d is %llu.\n", num, factorial(num)); 
} 
return 0; 
} 