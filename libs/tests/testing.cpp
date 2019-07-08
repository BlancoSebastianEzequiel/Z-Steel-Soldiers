#include "testing.h"
#include <stdio.h>
#include <iostream>


static int _failure_count;

void Testing::test(const char *message, bool ok) {
    if (ok) {
        printf("%s... OK\n", message);
    } else {
        printf("%s... ERROR\n", message);
    }
    fflush(stdout);
    _failure_count += !ok;
}

int Testing::failure_count() {
    return _failure_count;
}
