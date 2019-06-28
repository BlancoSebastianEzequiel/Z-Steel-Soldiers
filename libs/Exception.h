// "Copyright [2017] <SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef  _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_COMMONEXCEPTION_H_
#define  _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_COMMONEXCEPTION_H_
//------------------------------------------------------------------------------
#include <typeinfo>
//------------------------------------------------------------------------------
#define BUF_LEN 256
//------------------------------------------------------------------------------
class Exception : public std::exception {
 private :
    char msg_error[BUF_LEN];
 public :
    //--------------------------------------------------------------------------
    explicit Exception(const char* fmt, ...) noexcept;
    //--------------------------------------------------------------------------
    virtual const char* what() const noexcept;
    //--------------------------------------------------------------------------
    virtual ~Exception() noexcept {}
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_COMMONEXCEPTION_H_
