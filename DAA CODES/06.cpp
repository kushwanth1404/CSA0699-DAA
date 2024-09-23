#include <stdio.h> 
#include <stdbool.h> 
#include <math.h> 
// Function to check if a number is prime 
bool isPrime(int num) { 
if (num <= 1) { 
return false; 
} 
for (int i = 2; i <= sqrt(num); i++) { 
if (num % i == 0) { 
return false; 
} 
} 
return true; 
} 
int main() { 
int num; 
// Input: Number to be checked 
printf("Enter a number: "); 
scanf("%d", &num); 
// Output: Check if the number is a prime number 
if (isPrime(num)) { 
printf("%d is a prime number.\n", num); 
} else { 
printf("%d is not a prime number.\n", num); 
} 
return 0; 
} 