#ifndef ESSENTIAL
#define ESSENTIAL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//User Input

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

#endif //ESSENTIAL