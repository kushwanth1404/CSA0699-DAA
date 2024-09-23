#include <stdio.h> 
// Function to check if a number is a perfect number 
int isPerfectNumber(int num) { 
if (num <= 1) return 0;  // 0 and negative numbers are not perfect numbers 
int sum = 0; 
// Find divisors and sum them up 
for (int i = 1; i <= num / 2; i++) { 
if (num % i == 0) { 
sum += i; 
} 
} 
return sum == num;  // Check if sum of divisors equals the original number 
} 
int main() { 
int number; 
// Input: the number to check 
printf("Enter a number: "); 
scanf("%d", &number); 
// Check if the number is a perfect number and print the result 
if (isPerfectNumber(number)) { 
printf("%d is a perfect number.\n", number); 
} else { 
printf("%d is not a perfect number.\n", number); 
} 
return 0; 
} 