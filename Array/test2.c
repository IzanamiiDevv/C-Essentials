#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void* list;
    unsigned int len;
    size_t size;
} Array;

Array _MacroDefined(size_t size);
#define Array_Init(type) (_MacroDefined(sizeof(type)));

Array _MacroDefined(size_t size) {
    Array buff;
    buff.len = 0;
    buff.list = malloc(size);
    buff.size = size;
    return buff;
}


void Array_Free(Array* arr) {
    free(arr->list);
    arr->len = 0;
    arr->size = 0;
}

#define Array_PushBack(arr, value ,type) { \
    void* new_list; \
    arr.len += 1; \
    new_list = realloc(arr.list, arr.size * arr.len); \
    if (new_list == NULL) return 1; \
    arr.list = new_list; \
    ((type*)arr.list)[arr.len - 1] = value; \
};


int main() {
    Array myarr = Array_Init(char*);
    Array_PushBack(myarr, "Hello", char* );
    Array_PushBack(myarr, "World", char* );
    for(int i = 0; i < myarr.len; i++) {
        printf("%s", ((char**)myarr.list)[i]);
    }
    Array_Free(&myarr);
    return 0;
}