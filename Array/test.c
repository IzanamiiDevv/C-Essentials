#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void* list;
    size_t len;
    size_t elem_type;

} Array;

typedef void(*Array_Interger_Foreach_Callback)(int);

Array Array_Init() {
    Array buffer;
    buffer.list = NULL;
    buffer.len = 0;
    buffer.elem_type = 0;

    return buffer;
};

void Array_PushBack(Array* arr, void* data, char type) {
    void* new_list;
    switch (type) {
        case 'i':
            arr->elem_type = sizeof(int);
            arr->len += 1;
            new_list = realloc(arr->list, arr->elem_type * arr->len);
            if (new_list == NULL) return;
            arr->list = new_list;
            ((int*)arr->list)[arr->len - 1] = *( int * )data;
            break;

        case 'f':
            arr->elem_type = sizeof(float);
            arr->len += 1;
            new_list = realloc(arr->list, arr->elem_type * arr->len);
            if (new_list == NULL) return;
            arr->list = new_list;
            ((float*)arr->list)[arr->len - 1] = *( float * )data;
            break;
        case 'c':
            arr->elem_type = sizeof(char);
            arr->len += 1;
            new_list = realloc(arr->list, arr->elem_type * arr->len);
            if (new_list == NULL) return;
            arr->list = new_list;
            ((char*)arr->list)[arr->len - 1] = *( char * )data;
            break;
        case 's':

            arr->elem_type = sizeof( char* );
            arr->len += 1;
            new_list = realloc(arr->list, arr->elem_type * arr->len);
            if (new_list == NULL) return;

            arr->list = new_list;
            ((char**)arr->list)[arr->len - 1] = (char*) data;


            break;
        default:
            printf("Error: Unknown type\n");
    }
}

void Array_ForEach() {

}

void Array_Free(Array* buffer) {
    free(buffer->list);
    buffer->len = 0;
    buffer->elem_type = 0;
}

int main() {
    Array mynum = Array_Init();
    Array names = Array_Init();
    char* x;
    int n;

    n = 10;
    Array_PushBack(&mynum, &n, 'i');

    x = "Hello World";
    Array_PushBack(&names, x, 's');

    n = 20;
    Array_PushBack(&mynum, &n, 'i');

    n = 50;
    Array_PushBack(&mynum, &n, 'i');

    for(size_t i = 0; i < names.len; i++) {
        printf("%s\n", (( char** )names.list)[i]);
    }

    for(size_t i = 0; i < mynum.len; i++) {
        printf("%i\n", (( int* )mynum.list)[i]);
    }

    Array_Free(&mynum);
    return 0;
}

/*

ListArray myarr = ListArray_Initialized("STRING");

Array_Push(&myarr, 29);
Array_Pop(&myarr);

ListArray myarr = ListArray_Initialized(int);

 */