#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concatenate_strings(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char* result = (char*) malloc(len1 + len2 + 1);  // +1 for null terminator
    if (result == NULL) {
        printf("Error: unable to allocate memory.\n");
        exit(1);
    }
    strcpy(result, str1);
    strcat(result, str2);
    return result;
}

int main() {
    char* str1 = "Hello, ";
    char* str2 = "world!";
    char* result = concatenate_strings(str1, str2);
    printf("%s\n", result);
    free(result);  // free dynamically allocated memory
    return 0;
}
