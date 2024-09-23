#include <stdio.h> 
// Function to calculate GCD using the Euclidean algorithm 
int gcd(int a, int b) { 
if (b == 0) 
return a; 
else 
return gcd(b, a % b); 
} 
int main() { 
int num1, num2, result; 
// Input: Two numbers 
printf("Enter two integers: "); 
scanf("%d %d", &num1, &num2); 
// Calculate GCD 
result = gcd(num1, num2); 
// Output: GCD of the two numbers 
printf("GCD of %d and %d is %d.\n", num1, num2, result); 
return 0; 
}