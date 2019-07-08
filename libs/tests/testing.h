#ifndef TESTING_H
#define TESTING_H

#include <stdbool.h>
class Testing {
public:
    void test(const char *message, bool ok);
    int failure_count();
};

#endif // TESTING_H
