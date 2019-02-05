#ifndef MUTEXLOCK_H
#define MUTEXLOCK_H
#include <mutex>
class mutexLock{
private:
    std::mutex& mtx;
public:
    mutexLock( std::mutex& mtx, char mode = 0):mtx(mtx){
        if(mode == 0) Lock();
        if(mode == 1) WaitForLock();
    }
    ~mutexLock(){mtx.unlock();}
    void Unlock(){mtx.unlock();}
    void Lock(){mtx.lock();}
    void TryLock(){mtx.try_lock();}
    void WaitForLock(){while(!mtx.try_lock());}

};

#endif // MUTEXLOCK_H
