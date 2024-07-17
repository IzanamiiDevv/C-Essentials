#ifndef ESSENTIAL
#define ESSENTIAL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define CREDIT "IzanamiiDev"


/*=========================|USER INPUTS|================================*/

// Function to get a valid integer input
int get_int(const char* text) {
    char temp[100];
    int valid = 0;
    int num;
    while (!valid) {
        printf("%s", text);
        if (scanf("%99s", temp) != 1) {
            while (getchar() != '\n');
            continue;
        }      
        valid = 1;
        for (int i = 0; i < strlen(temp); i++) {
            if (!isdigit(temp[i])) {
                valid = 0;
                printf("Invalid input. Please enter a valid number.\n");
                break;
            }
        }
    }  
    num = atoi(temp);
    return num;
}

// Function to get a valid long input
long get_long(const char* text) {
    char temp[100];
    int valid = 0;
    long num;

    while (!valid) {
        printf("%s", text);
        if (scanf("%99s", temp) != 1) {
            while (getchar() != '\n');
            continue;
        }
        valid = 1;
        for (int i = 0; i < strlen(temp); i++) {
            if (!isdigit(temp[i]) && !(i == 0 && (temp[i] == '-' || temp[i] == '+'))) {
                valid = 0;
                printf("Invalid input. Please enter a valid long number.\n");
                break;
            }
        }
    }
    num = atol(temp);
    return num;
}

// Function to get a valid float input
float get_float(const char* text) {
    char temp[100];
    int valid = 0;
    float num;

    while (!valid) {
        printf("%s", text);
        if (scanf("%99s", temp) != 1) {
            while (getchar() != '\n');
            continue;
        }
        valid = 1;
        int dot_count = 0;
        for (int i = 0; i < strlen(temp); i++) {
            if (!isdigit(temp[i]) && !(i == 0 && (temp[i] == '-' || temp[i] == '+')) && temp[i] != '.') {
                valid = 0;
                printf("Invalid input. Please enter a valid float number.\n");
                break;
            }
            if (temp[i] == '.') dot_count++;
            if (dot_count > 1) {
                valid = 0;
                printf("Invalid input. Please enter a valid float number.\n");
                break;
            }
        }
    }
    num = atof(temp);
    return num;
}

// Function to get a valid double input
double get_double(const char* text) {
    char temp[100];
    int valid = 0;
    double num;

    while (!valid) {
        printf("%s", text);
        if (scanf("%99s", temp) != 1) {
            while (getchar() != '\n');
            continue;
        }
        valid = 1;
        int dot_count = 0;
        for (int i = 0; i < strlen(temp); i++) {
            if (!isdigit(temp[i]) && !(i == 0 && (temp[i] == '-' || temp[i] == '+')) && temp[i] != '.') {
                valid = 0;
                printf("Invalid input. Please enter a valid double number.\n");
                break;
            }
            if (temp[i] == '.') dot_count++;
            if (dot_count > 1) {
                valid = 0;
                printf("Invalid input. Please enter a valid double number.\n");
                break;
            }
        }
    }
    num = atof(temp);
    return num;
}

// Function to get a valid string input
const char* get_string(const char* text) {
    static char temp[100];
    printf("%s", text);
    if (scanf("%99s", temp) != 1) {
        while (getchar() != '\n');
    }
    return temp;
}

// Function to get a valid char input
char get_char(const char* text) {
    char temp[100];
    char ch;

    while (1) {
        printf("%s", text);
        if (scanf("%99s", temp) != 1) {
            while (getchar() != '\n');
            continue;
        }
        if (strlen(temp) == 1) {
            ch = temp[0];
            break;
        } else {
            printf("Invalid input. Please enter a single character.\n");
        }
    }
    return ch;
}

/*======================|STRING CONVERTER|==============================*/

// Convert char* to const char*
const char* char_to_const_char(const char *str) {
    return (const char*) str;
}

// Convert char* to char[]
void char_to_char_array(const char *src, char *dest, size_t len) {
    strncpy(dest, src, len - 1);
    dest[len - 1] = '\0';
}

// Convert const char* to char*
char* const_char_to_char(const char *str) {
    // Allocate memory for the new string and copy the content
    char *result = (char *)malloc(strlen(str) + 1);
    strcpy(result, str);
    return result;
}

// Convert const char* to char[]
void const_char_to_char_array(const char *src, char *dest, size_t len) {
    strncpy(dest, src, len - 1);
    dest[len - 1] = '\0';
}

// Convert char[] to const char*
const char* char_array_to_const_char(const char *array) {
    return (const char*) array;
}

// Convert char[] to char*
char* char_array_to_char(const char *array) {
    // Allocate memory for the new string and copy the content
    char *result = (char *)malloc(strlen(array) + 1);
    strcpy(result, array);
    return result;
}

/*========================|DYNAMIC ARRAY|===============================*/
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

#endif //ESSENTIAL