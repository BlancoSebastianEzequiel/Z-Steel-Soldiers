// "Copyright [2017] <Copyright SebastianBlanco>"
#ifndef  _HOME_SEBASTIAN_CLIONPROJECTS_TP2_LOCK_H_
#define  _HOME_SEBASTIAN_CLIONPROJECTS_TP2_LOCK_H_
//--------------------------------------------------------------------------
#include <mutex>
//--------------------------------------------------------------------------
class Lock {
 private :
    std::mutex& m;
 public :
    explicit Lock(std::mutex& m);
    //--------------------------------------------------------------------------
    ~Lock();
    //--------------------------------------------------------------------------
 private :
    Lock(const Lock&) = delete;
    //--------------------------------------------------------------------------
    Lock& operator=(const Lock&) = delete;
    //--------------------------------------------------------------------------
    Lock(Lock&&) = delete;
    //--------------------------------------------------------------------------
    Lock& operator=(Lock&&) = delete;
    //--------------------------------------------------------------------------
};

#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TP2_LOCK_H_
