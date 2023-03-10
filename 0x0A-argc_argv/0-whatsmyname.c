#include <stdio.h>
#include <string.h>
#include <main.h>

int main(int argc, char *argv[]) {
    char *program_name = strdup(argv[0]);  // Make a copy of the program name
    printf("%s\n", program_name);          // Print the program name
    free(program_name);                    // Free the memory allocated by strdup
    return 0;
}
