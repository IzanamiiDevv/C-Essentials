#include <stdio.h>

int main() {
    FILE *fptr;

    // Open a file in append mode
    fptr = fopen("README.md", "a");

    // Append some text to the file
    fprintf(fptr, "\n Hello World");

    // Close the file
    fclose(fptr);

    return 0;
}