#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

#define Array_PushBack(type ,arr, value) { \
    void* new_list; \
    (arr).len += 1; \
    new_list = realloc((arr).list, sizeof(type) * (arr).len); \
    if (new_list == NULL) printf("Error: Memorry Allocation Failed."); \
    (arr).list = new_list; \
    ((type*)(arr).list)[(arr).len - 1] = value; \
};

#define Array_PopBack(type, arr) { \
    void* new_list; \
    (arr).len -= 1; \
    new_list = realloc((arr).list, sizeof(type) * (arr).len); \
    if(new_list == NULL) printf("Error: Memorry Allocation Failed."); \
    (arr).list = new_list; \
}

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

#define Array_Modify(type, arr, index, value) (( type* )(arr).list)[index] = value;

#define Array_Shuffle(type, arr) { \
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
    Array myarr = Array_Init();
    Array_PushBack(char*, myarr, "Kamusta");
    Array_PushBack(char*, myarr, "Hello World");
    Array_PushBack(char*, myarr, "Hii");
    Array_Modify(char*, myarr, 0, "Test");
    Array_Shuffle(char*, myarr);
    Array_PopBack(char*, myarr);

    Array_Print("%s", char*, myarr);

    Array_Free(&myarr);
    return 0;
}

//(rand() % (MAX - MIN + 1)) + MIN