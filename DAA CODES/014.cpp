#include <stdio.h> 
#include <string.h> 
int main() { 
char str[100]; 
// Input: String from the user 
printf("Enter a string: "); 
fgets(str, sizeof(str), stdin); 
// Remove the newline character if present 
str[strcspn(str, "\n")] = '\0'; 
// Calculate the length of the string using strlen 
int length = strlen(str); 
// Output: Length of the string 
printf("Length of the string: %d\n", length); 
return 0; 
}