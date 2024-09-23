#include <stdio.h> 
// Function to reverse the digits of a number 
int reverseNumber(int num) { 
int reversed = 0; 
while (num != 0) { 
int digit = num % 10;        // Extract the last digit 
reversed = reversed * 10 + digit;  // Append the digit to the reversed number 
num /= 10;                  // Remove the last digit from the original number 
} 
return reversed; 
} 
int main() { 
int number; 
// Input: the number to reverse 
printf("Enter a number: "); 
scanf("%d", &number); 
// Reverse the number and print the result 
int reversedNumber = reverseNumber(number); 
printf("Reversed number: %d\n", reversedNumber); 
return 0; 
} 