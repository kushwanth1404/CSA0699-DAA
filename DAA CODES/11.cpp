#include <stdio.h> 
#include <string.h> 
int main() { 
char source[100], destination[100]; 
// Input: Source string 
printf("Enter the source string: "); 
fgets(source, sizeof(source), stdin); 
// Remove the newline character if present 
source[strcspn(source, "\n")] = '\0'; 
// Copy the string using strcpy 
strcpy(destination, source); 
// Output: Destination string 
printf("Destination string: %s\n", destination); 
return 0; 
} 