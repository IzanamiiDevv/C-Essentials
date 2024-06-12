#include <stdio.h>

const int MAX = 99999;

int main() {
    FILE *fptr;

    // Open a file in read mode
    fptr = fopen("README.md", "r");

    // Store the content of the file
    char myString[10];

    // Read the first content and store it inside myString
    fgets(myString, MAX, fptr);

    // Print the file content
    printf("%s", myString);

    // Read the content of each line and print it
    while(fgets(myString, MAX, fptr)) {
        printf("%s", myString);
    }

    // Close the file
    fclose(fptr);

    return 0;

}