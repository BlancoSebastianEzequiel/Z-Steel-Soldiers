#ifndef TEST_PARSER_H
#define TEST_PARSER_H

#include "../Parser.h"
#include "testing.h"

class Test_parser {
private:
    Parser aParser;
    Testing testing;
    void test_line_with_no_delim();
    void test_line_with_delim();
public:
    void run();
};

#endif // TEST_PARSER_H
