// "Copyright [2017] <SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef  _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_COMMONPARSER_H_
#define  _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_COMMONPARSER_H_
//------------------------------------------------------------------------------
#include <vector>
#include <cstdio>
#include <cstdarg>
#include <string>
#include <stdio.h>
//------------------------------------------------------------------------------
#define BUF_LEN 256
//------------------------------------------------------------------------------
class Parser {
 private :
    std::vector<std::vector<std::string>> parsedLines;
 public :
    //--------------------------------------------------------------------------
    Parser();
    //--------------------------------------------------------------------------
    ~Parser();
    //--------------------------------------------------------------------------
    /*
     * pre: Recibe un puntero a char del nombre del archivo, un caracter que
     * representa el ultimo caracter de cada linea, el caracter delimitador
     * de los argumentos y la cantidad de argumentos que se espera. Si no se
     * sabe cuantos argumentos son se pone -1.
     * pos: Devuelve un vector de vectores de string donde cada vector
     * representa cada linea parseada.
     */
    std::vector<std::vector<std::string>> parseFile(
            char* fileName, char endOfLine, char delim, ssize_t args = -1);
    //--------------------------------------------------------------------------
    /*
     * pre: Recibe una linea, un caracter que representa el caracter delimitador
     * de los argumentos y la cantidad de argumentos que se espera. Si no se
     * sabe cuantos argumentos son se pone -1.
     * pos: Devuelve un vector de string donde que representa la linea parseada.
     */
    std::vector<std::string> parseLine(
            std::string line, char delim, ssize_t args = -1);
    //--------------------------------------------------------------------------
    size_t stringToSize_t(std::string aString);
    //--------------------------------------------------------------------------
    ssize_t stringToSsize_t(std::string aString);
    //--------------------------------------------------------------------------
    uint32_t stringToUint32_t(std::string aString);
    //--------------------------------------------------------------------------
    float stringToFloat(std::string aString);
    //--------------------------------------------------------------------------
    std::string size_tToString(size_t number);
    //--------------------------------------------------------------------------
    std::string armString(const char* fmt, ...);
    //--------------------------------------------------------------------------
    std::string bufferToString(const char* buffer, size_t size);
    //--------------------------------------------------------------------------
 private :
    //--------------------------------------------------------------------------
    /*
     * pre: un caracter.
     * pos: Devuelve el char convertido a string.
     */
    std::string charToString(char aChar);
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  //  _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_COMMONPARSER_H_
