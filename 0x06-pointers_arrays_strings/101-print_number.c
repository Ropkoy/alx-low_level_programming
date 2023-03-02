#include "main.h"

void print_number(int n) {
    if (n < 0) {
        _putchar('-');
        n = -n;
    }

    if (n/10) {
        print_number(n/10);
    }

    _putchar(n%10 + '0');
}

int main() {
    int myNum = 42;
    print_number(myNum);
    return 0;
}
