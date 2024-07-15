#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CREDIT "IzanamiiDev"

typedef struct {
    void* list;
    unsigned int len;
} Array;

Array Array_Init() {
    Array buff;
    buff.len = 0;
    buff.list = NULL;
    return buff;
}


void Array_Free(Array* arr) {
    free(arr->list);
    arr->len = 0;
}

#define Array_PushBack(arr, type, value) { \
    void* new_list; \
    (arr).len += 1; \
    new_list = realloc((arr).list, sizeof(type) * (arr).len); \
    if (new_list == NULL) return 1; \
    (arr).list = new_list; \
    ((type*)(arr).list)[(arr).len - 1] = value; \
};

#define Array_Print(format, type, arr) { \
    printf("["); \
    for(int i = 0; i < (arr).len; i++) { \
        printf(format, ((type*)(arr).list)[i]); \
        if(i == (arr).len - 1) break; \
        printf(", "); \
    } \
    printf("] \n"); \
}

#define Array_Take(type, arr, index) ((( type* )(arr).list)[(index)])

#define Array_ForEach(type, arr, callback) { \
    void(*arrforeach)(type) = callback; \
    for(int i = 0; i < (arr).len; i++) { \
        arrforeach((( type* )(arr).list)[i]); \
    } \
}

#define Array_Map(type, arr, callback) { \
    type (*arrmap)(type) = callback; \
    for(int i = 0; i < (arr).len; i++) { \
        (( type* )(arr).list)[i] = arrmap((( type* )(arr).list)[i]); \
    } \
}

void fn(char* item) {
    printf("%s \n", item);
}

char* fn2(char* item) {
    return "Test";
}

int main() {
    Array myarr = Array_Init();
    Array_PushBack(myarr, char* , "Hello");
    Array_PushBack(myarr, char* , "World");

    Array_ForEach(char*, myarr, fn);
    Array_Map(char*, myarr, fn2);
    Array_Print("%s", char*, myarr);

    Array_Free(&myarr);
    return 0;
}