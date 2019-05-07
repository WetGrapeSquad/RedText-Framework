#pragma once
#include <thread>

struct Args{
    int i;
    void** vect;
    void (*_func)(...);
};


namespace rt {

    class Rthread
    {
    public:
        Rthread(){}
        template<typename r,typename args>
        Rthread(r(*_func)(args...), args s){
            th(_func, s);
        }
        void join(){
            th.join();
        }
        void detach(){
            th.detach();
        }
    private:
        std::thread th;
    };

}
