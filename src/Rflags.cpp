#include "Rflags.h"
#include <Rstring.h>

using namespace rt;

Rflags::Rflags(){
    this->fg = '%';
    this->str = new char[1];
    this->Clear = true;
    this->fc = 0;
}
Rflags::Rflags(const char* str){
    this->fg = '%';
    int s = 0, size = strlen(str);
    this->str = new char[size + 1];
    for(int i = 0; i < size; i++) {
        this->str[i] = str[i];
    }
    this->str[size] = '\0';
    this->Clear = false;
    this->fc = 0;
    while(s < size){
        if(this->str[s] == this->fg){
            this->fc++;
        }
        s++;
    }
}
Rflags::Rflags(const char* str,const char fg){
    this->fg = fg;
    int s = 0, size = strlen(str);
    this->str = new char[size + 1];
    for(int i = 0; i < size; i++) {
        this->str[i] = str[i];
    }
    this->str[size] = '\0';
    this->Clear = false;
    this->fc = 0;
    while(s < size){
        if(this->str[s] == this->fg){
            this->fc++;
        }
        s++;
    }
}
void Rflags::operator()(char* str){
    delete [] this->str;
    int s = 0, size = strlen(str);
    this->str = new char[size + 1];
    for(int i = 0; i < size; i++) {
        this->str[i] = str[i];
    }
    this->str[size] = '\0';
    this->Clear = false;
    this->fc = 0;
    while(s < size){
        if(this->str[s] == this->fg){
            this->fc++;
        }
        s++;
    }
}
char *Rflags::GetFlag(int i){
    if(this->Clear) return "";
    if(this->fc < i || i < 0) return "";
    int f = 0, s = 0, size = strlen(this->str);
    while(s < size){
        if(this->str[s] == ' ' || this->str[s] == ',');
        else if(this->str[s] == this->fg){
            if(f == i){
                Rstring ret;
                s++;
                while(!(this->str[s] == this->fg || this->str[s] == '\0')) {
                    if(this->str[s] == ' ' || this->str[s] == ',');
                    else ret << this->str[s];
                    s++;
                }
                return ret;
            }
            f++;
        }
        s++;
    }
    return "";
}
void Rflags::SetClear(){
    delete [] this->str;
    this->str = new char[1];
    this->Clear = true;
}
int Rflags::GetCountFlag(){
    return this->fc;
}
bool Rflags::ifflag(char* ch){
    Rstring str = ch;
    for(int i = 0; i <= this->fc; i++)
        if(str == GetFlag(i)) return true;
    return false;
}
