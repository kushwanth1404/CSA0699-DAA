#include <stdio.h> 
#include <stdbool.h> 
// Function to generate prime numbers using Sieve of Eratosthenes 
void sieveOfEratosthenes(int n) { 
// Create a boolean array and initialize all entries as true 
bool prime[n + 1]; 
for (int i = 0; i <= n; i++) { 
prime[i] = true; 
} 
// 0 and 1 are not prime numbers 
prime[0] = prime[1] = false; 
for (int p = 2; p * p <= n; p++) { 
// If prime[p] is not changed, then it is a prime 
if (prime[p] == true) { 
// Update all multiples of p 
for (int i = p * p; i <= n; i += p) { 
prime[i] = false; 
} 
} 
} 
// Print all prime numbers 
printf("Prime numbers up to %d:\n", n); 
for (int p = 2; p <= n; p++) { 
if (prime[p]) { 
printf("%d ", p); 
} 
} 
printf("\n"); 
} 
int main() { 
int n; 
// Input: Upper limit to generate prime numbers 
printf("Enter the upper limit to generate prime numbers: "); 
scanf("%d", &n); 
// Generate and print prime numbers up to n 
sieveOfEratosthenes(n); 
return 0; 
}