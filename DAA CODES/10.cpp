#include <stdio.h> 
#include <string.h> 
#include <stdbool.h> 
// Function to check if a string is a palindrome 
bool isPalindrome(char str[]) { 
int left = 0; 
int right = strlen(str) - 1; 
while (left < right) { 
if (str[left] != str[right]) { 
return false; 
} 
left++; 
right--; 
} 
return true; 
} 
int main() { 
char str[100]; 
// Input: String to be checked 
printf("Enter a string: "); 
scanf("%s", str); 
// Output: Check if the string is a palindrome 
if (isPalindrome(str)) { 
printf("\"%s\" is a palindrome.\n", str); 
} else { 
printf("\"%s\" is not a palindrome.\n", str); 
} 
return 0; 
}