#include "essential.h"
#include <stdlib.h>

int main() {

    const char* text = "Hello";
    char arr[6];
    const_char_to_char_array(text, arr, sizeof(arr));


    printf("%s",arr);
    return 0;
}