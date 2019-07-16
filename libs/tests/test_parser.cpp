#include "test_parser.h"

void Test_parser::test_parse_line_with_no_delim() {
    std::string line = "word";
    std::vector<std::string> parsed = aParser.parseLine(line, '-');
    std::vector<std::string> expected(1, "word");
    testing.test(__func__, parsed==expected);
}

void Test_parser::test_parse_line_with_delim() {
    std::string line = "word-word";
    std::vector<std::string> parsed = aParser.parseLine(line, '-');
    std::vector<std::string> expected(2, "word");
    testing.test(__func__, parsed==expected);
}

void Test_parser::run() {
    test_parse_line_with_no_delim();
    test_parse_line_with_delim();
}
