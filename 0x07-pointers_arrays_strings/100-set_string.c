#include <main.h>

int main() {
    char *s = NULL;
    char *to = "hello, world!";
    set_string(&s, to);
    printf("%s\n", s);
    return 0;
}
