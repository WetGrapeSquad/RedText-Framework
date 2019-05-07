#include "Rmutex.h"

using namespace rt;


Rmutex::Rmutex(){
    pthread_mutex_init(&p_mutex, NULL);
}
void Rmutex::lock(){
    pthread_mutex_lock(&p_mutex);
}
bool Rmutex::try_lock(){
    return pthread_mutex_trylock(&p_mutex);
}
void Rmutex::unlock(){
    pthread_mutex_unlock(&p_mutex);
}
Rmutex::~Rmutex(){
    pthread_mutex_destroy(&p_mutex);
}
