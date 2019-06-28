// "Copyright [2017] <SebastianBlanco>"
//------------------------------------------------------------------------------
#include <vector>
#include <cstring>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include "Parser.h"
#include "Exception.h"
//------------------------------------------------------------------------------
// PARSE CONSTRUCTOR
//------------------------------------------------------------------------------
Parser::Parser() {}
//------------------------------------------------------------------------------
// PARSE DESTRUCTOR
//------------------------------------------------------------------------------
Parser::~Parser() {}
//------------------------------------------------------------------------------
// PARSE FILE
//------------------------------------------------------------------------------
std::vector<std::vector<std::string>> Parser::parseFile(
        char* fileName, char endOfLine, char delim, ssize_t args) {
    std::ifstream file;
    file.open(fileName, std::ifstream::in);
    if (!file.is_open()) {
        file.close();
        throw Exception("El archivo %s no pude ser abierto", fileName);
    }
    file.seekg(0, file.end);
    std::string line;
    file.seekg(0, file.beg);
    getline(file, line, endOfLine);
    std::vector<std::vector<std::string>> parsedLines;
    while (!file.eof()) {
        if (file.fail()) {
            throw Exception("Hubo un error al leer el archivo %s y "
                                  "salto bit de fail", fileName);
        }
        parsedLines.push_back(parseLine(line, delim, args));
        getline(file, line, endOfLine);
    }
    return parsedLines;
}
//------------------------------------------------------------------------------
// PARSE USER
//------------------------------------------------------------------------------
std::vector<std::string> Parser::parseLine(
        std::string line, char delim, ssize_t args) {
    std::string aux = line;
    std::vector<std::string> aVector;
    size_t found = line.find(delim);
    size_t delimQuant = 0;
    std::string cmp = charToString(delim);

    while (found != std::string::npos) {
        delimQuant++;
        std::string parse = line.substr(0, found);
        if (strcmp(parse.c_str(), cmp.c_str()) != 0) {
            aVector.push_back(parse);
        }
        line = line.substr(found+1, line.size());
        found = line.find(delim);
    }
    if (args != -1 && delimQuant != (size_t)(args-1)) {
        throw Exception("La cantidad de argumentos en la linea %s, no es la "
                              "esperada\n", aux);
    }
    if (strcmp(line.c_str(), cmp.c_str()) != 0) {
        aVector.push_back(line);
    }
    return aVector;
}
//------------------------------------------------------------------------------
// STRING TO FLOAT
//------------------------------------------------------------------------------
float Parser::stringToFloat(std::string aString) {
    std::stringstream ss;
    ss << aString;
    float number;
    ss >> number;
    return number;
}
//------------------------------------------------------------------------------
// STRING TO UINT32_T
//------------------------------------------------------------------------------
uint32_t Parser::stringToUint32_t(std::string aString) {
    std::stringstream ss;
    ss << aString;
    uint32_t number;
    ss >> number;
    return number;
}
//------------------------------------------------------------------------------
// STRING TO SSIZE_T
//------------------------------------------------------------------------------
ssize_t Parser::stringToSsize_t(std::string aString) {
    std::stringstream ss;
    ss << aString;
    ssize_t number;
    ss >> number;
    return number;
}
//------------------------------------------------------------------------------
// STRING TO SIZE_T
//------------------------------------------------------------------------------
size_t Parser::stringToSize_t(std::string aString) {
    std::stringstream ss;
    ss << aString;
    size_t number;
    ss >> number;
    return number;
}
//------------------------------------------------------------------------------
// SIZE_T TO STRING
//------------------------------------------------------------------------------
std::string Parser::size_tToString(size_t number) {
    std::stringstream ss;
    ss << number;
    std::string s;
    ss >> s;
    return s;
}
//------------------------------------------------------------------------------
// ARM STRING
//------------------------------------------------------------------------------
std::string Parser::armString(const char* fmt, ...) {
    char msg[BUF_LEN];
    va_list args;
    va_start(args, fmt);
    vsnprintf(msg, BUF_LEN, fmt, args);
    va_end(args);
    msg[BUF_LEN-1] = 0;
    std::string finalString = msg;
    return finalString;
}
//------------------------------------------------------------------------------
// BUFFER TO STRING
//------------------------------------------------------------------------------
std::string Parser::bufferToString(const char* buffer, size_t size) {
    std::stringstream ss;
    std::string s;
    for (size_t i = 0; i < size; i++) {
        s += charToString(buffer[i]);
    }
    return s;
}
//------------------------------------------------------------------------------
// CHAR TO STRING
//------------------------------------------------------------------------------
std::string Parser::charToString(char aChar) {
    std::stringstream ss;
    std::string s;
    ss << aChar;
    ss >> s;
    return s;
}
//------------------------------------------------------------------------------
