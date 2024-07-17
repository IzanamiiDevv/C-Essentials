#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CREDIT "IzanamiiDev"

typedef struct {
    void* list;
    unsigned int len;
} Array;

Array array_init() {
    Array buff;
    buff.len = 0;
    buff.list = NULL;
    return buff;
}


void array_flush(Array* arr) {
    free(arr->list);
    arr->len = 0;
}

#define array_pushBack(type ,arr, value) { \
    void* new_list; \
    (arr).len += 1; \
    new_list = realloc((arr).list, sizeof(type) * (arr).len); \
    if (new_list == NULL) printf("Error: Memorry Allocation Failed."); \
    (arr).list = new_list; \
    ((type*)(arr).list)[(arr).len - 1] = value; \
};

#define array_popBack(type, arr) { \
    void* new_list; \
    (arr).len -= 1; \
    new_list = realloc((arr).list, sizeof(type) * (arr).len); \
    if(new_list == NULL) printf("Error: Memorry Allocation Failed."); \
    (arr).list = new_list; \
}

#define array_print(format, type, arr) { \
    printf("["); \
    for(int i = 0; i < (arr).len; i++) { \
        printf(format, ((type*)(arr).list)[i]); \
        if(i == (arr).len - 1) break; \
        printf(", "); \
    } \
    printf("] \n"); \
}

#define array_take(type, arr, index) ((( type* )(arr).list)[(index)])


#define array_forEach(type, arr, callback) { \
    void(*arrforeach)(type) = callback; \
    for(int i = 0; i < (arr).len; i++) { \
        arrforeach((( type* )(arr).list)[i]); \
    } \
}

#define array_map(type, arr, callback) { \
    type (*arrmap)(type) = callback; \
    for(int i = 0; i < (arr).len; i++) { \
        (( type* )(arr).list)[i] = arrmap((( type* )(arr).list)[i]); \
    } \
}

#define array_mod(type, arr, index, value) (( type* )(arr).list)[index] = value;

#define array_shuffle(type, arr) { \
    srand(time(0)); \
    const unsigned int MAX = (arr).len - 1; \
    const unsigned short MIN = 0; \
    for(int i = 0; i < (arr).len; i++) {\
        type temp = (( type* )(arr).list)[i]; \
        int randn = (rand() % (MAX - MIN + 1)) + MIN; \
        (( type* )(arr).list)[i] = (( type* )(arr).list)[randn];\
        (( type* )(arr).list)[randn] = temp; \
    } \
}

int main() {
    Array nn = array_init();
    Array nnn = array_init();
    array_pushBack(int, nnn, 20);
    array_pushBack(Array, nn, nnn);

    Array getVal = array_take(Array, nn, 0);
    int num = array_take(int, getVal, 0);

    printf("%i\n", num);

    array_flush(&nnn);
    array_flush(&nn);
    return 0;
}