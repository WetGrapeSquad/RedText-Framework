#pragma once
#include <pthread.h>

namespace rt {
    class Rmutex
    {
    public:
        Rmutex();
        void lock();
        bool try_lock();
        void unlock();
        ~Rmutex();
    private:
        pthread_mutex_t p_mutex;
    };

}
