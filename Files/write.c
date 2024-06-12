#include <stdio.h>

int main() {
    FILE *fptr;

    // Open a file in writing mode
    fptr = fopen("README.md", "w");

    // Write some text to the file
    fprintf(fptr, "Some text");

    // Close the file
    fclose(fptr);

    return 0;
}