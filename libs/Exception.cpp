// "Copyright [2017] <SebastianBlanco>"
//------------------------------------------------------------------------------
#include <cstdio>
#include <cstdarg>
#include "Exception.h"
//------------------------------------------------------------------------------
// OSERROR CONSTRUCTOR
//------------------------------------------------------------------------------
Exception::Exception(const char* fmt, ...) noexcept {
    va_list args;
    va_start(args, fmt);
    vsnprintf(msg_error, BUF_LEN, fmt, args);
    va_end(args);
    msg_error[BUF_LEN-1] = 0;
}
//------------------------------------------------------------------------------
// WHAT
//------------------------------------------------------------------------------
const char* Exception::what() const noexcept {
    return msg_error;
}
//------------------------------------------------------------------------------
