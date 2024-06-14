#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 1. char* to const char*
const char* char_to_const_char(const char *str) {
    return (const char*) str;
}

// 2. char* to char[]
void char_to_char_array(const char *src, char *dest, size_t len) {
    strncpy(dest, src, len - 1);
    dest[len - 1] = '\0';
}

// 3. const char* to char*
char* const_char_to_char(const char *str) {
    // Allocate memory for the new string and copy the content
    char *result = (char *)malloc(strlen(str) + 1);
    strcpy(result, str);
    return result;
}

// 4. const char* to char[]
void const_char_to_char_array(const char *src, char *dest, size_t len) {
    strncpy(dest, src, len - 1);
    dest[len - 1] = '\0';
}

// 5. char[] to const char*
const char* char_array_to_const_char(const char *array) {
    return (const char*) array;
}

// 6. char[] to char*
char* char_array_to_char(const char *array) {
    // Allocate memory for the new string and copy the content
    char *result = (char *)malloc(strlen(array) + 1);
    strcpy(result, array);
    return result;
}

int main() {
    // Example usage:

    char str1[] = "Hello, World!";
    const char *cstr1;
    char arr1[50];
    
    // 1. char* to const char*
    cstr1 = char_to_const_char(str1);
    printf("char* to const char*: %s\n", cstr1);
    
    // 2. char* to char[]
    char_to_char_array(str1, arr1, sizeof(arr1));
    printf("char* to char[]: %s\n", arr1);
    
    // 3. const char* to char*
    const char *str2 = "Hello, Universe!";
    char *cstr2;
    cstr2 = const_char_to_char(str2);
    printf("const char* to char*: %s\n", cstr2);
    free(cstr2);
    
    // 4. const char* to char[]
    char arr2[50];
    const_char_to_char_array(str2, arr2, sizeof(arr2));
    printf("const char* to char[]: %s\n", arr2);
    
    // 5. char[] to const char*
    cstr1 = char_array_to_const_char(arr1);
    printf("char[] to const char*: %s\n", cstr1);
    
    // 6. char[] to char*
    cstr2 = char_array_to_char(arr1);
    printf("char[] to char*: %s\n", cstr2);
    free(cstr2);

    return 0;
}
