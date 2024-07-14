#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* array;
    size_t used;
    size_t length;
} Array_Interger;

typedef void(*Array_Interger_Foreach_Callback)(int);
typedef int(*Array_Interger_Map_Callback)(int);

Array_Interger New_Array_Interger(int array[], size_t initialLength) {
    Array_Interger temp;
    temp.array = malloc(sizeof(int) * initialLength);
    temp.used = initialLength;
    temp.length = initialLength;

    for (size_t i = 0; i < initialLength; i++)
        temp.array[i] = array[i];
    return temp;
}

void Array_Integer_Push_Back(Array_Interger *a, int element) {
    if (a->used == a->length) {
        a->length *= 2;
        a->array = ( int * )realloc(a->array, a->length * sizeof(int));
    }
    a->array[a->used++] = element;
}

void Array_Integer_Pop_Back(Array_Interger *a) {
    if(a->used == 0) return;
    if(a->used == a->length) {
        a->length = (a->length / 2);
        a->array = ( int * )realloc(a->array, a->length / sizeof(int));
    }

    a->used--;
}

void Array_Interger_Free(Array_Interger *a) {
    free(a->array);
    a->array = NULL;
    a->used = 0;
    a->length = 0;
}

void Array_Integer_ForEach(Array_Interger a, Array_Interger_Foreach_Callback callback) {
    for(size_t i = 0; i < a.used; i++)
        callback(a.array[i]);
}

void Array_Integer_Map(Array_Interger *a, Array_Interger_Map_Callback callback) {
    for(size_t i = 0; i < a->used; i++)
        a->array[i] = callback(a->array[i]);
}

/*=============================================================================*/

void printAll(int num) {
    printf("%i\n", num);
}

int increament(int num) {
    return num + 10;
}

int main() {
    int num[] = {10, 39, 20, 60};
    size_t length = sizeof(num) / sizeof(num[0]);
    Array_Interger numbers = New_Array_Interger(num, length);

    Array_Integer_Push_Back(&numbers, 10);
    Array_Integer_Pop_Back(&numbers);

    Array_Integer_Map(&numbers, increament);
    Array_Integer_ForEach(numbers, printAll);

    Array_Interger_Free(&numbers);
    return 0;
}