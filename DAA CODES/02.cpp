#include <stdio.h> 
#include <math.h> 
// Function to count the number of digits in a number 
int countDigits(int num) { 
int count = 0; 
while (num != 0) { 
num /= 10; 
count++; 
} 
return count; 
} 
// Function to check if a number is an Armstrong number 
int isArmstrong(int num) { 
int sum = 0, temp, remainder, n = 0; 
// Calculate the number of digits 
n = countDigits(num); 
temp = num; 
while (temp != 0) { 
remainder = temp % 10; 
sum += pow(remainder, n); 
temp /= 10; 
} 
// Check if sum of digits each raised to the power of number of digits 
if (sum == num) 
return 1; 
else 
return 0; 
} 
int main() {
	int num; 
// Input: Number to be checked 
printf("Enter a number: "); 
scanf("%d", &num); 
// Output: Check if the number is an Armstrong number 
if (isArmstrong(num)) 
printf("%d is an Armstrong number.\n", num); 
else 
printf("%d is not an Armstrong number.\n", num); 
return 0; 
} 