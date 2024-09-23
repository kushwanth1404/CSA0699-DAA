#include <stdio.h> 
#include <string.h> 
// Function to print the reverse of a string 
void printReverse(char str[]) { 
int length = strlen(str); 
for (int i = length - 1; i >= 0; i--) { 
printf("%c", str[i]); 
} 
printf("\n"); 
} 
int main() { 
char str[100]; 
// Input: String to be reversed 
printf("Enter a string: "); 
fgets(str, sizeof(str), stdin); 
// Remove the newline character if present 
str[strcspn(str, "\n")] = '\0'; 
// Print the reverse of the string 
printf("Reversed string: "); 
printReverse(str); 
return 0; 
} 