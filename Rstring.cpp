#include "Rstring.h"
#include <conv.h>
#include <stdio.h>

int strlen(const char *str) {
	int i = 0;
	while (str[i] != '\0') i++;
	return i;
}

using namespace rt;

Rstring::Rstring(){
    this->str.setSize(1);
    this->str[0] = '\0';
}
Rstring::~Rstring(){}
Rstring::Rstring(char* str) {
    int h = strlen(str);
    this->str.setSize(h + 1);
    for(int i = 0; i < h; i++){
        this->str[i] = str[i];
    }
    this->str[h] = '\0';
	return;
}
Rstring::Rstring(const char* str){
    int h = strlen(str);
    this->str.setSize(h + 1);
    for(int i = 0; i < h; i++){
        this->str[i] = str[i];
    }
    this->str[h] = '\0';
    return;
}
Rstring::Rstring(Rvector<char> str){
    this->str = str;
}
Rstring::Rstring(char ch) {
    this->str.setSize(2);
    this->str[0] = ch;
    this->str[1] = '\0';
    return;
}
void Rstring::operator=(char* str) {
    int h = strlen(str);
    this->str.setSize(h + 1);
    for(int i = 0; i < h; i++){
        this->str[i] = str[i];
    }
    this->str[h] = '\0';
	return;
}
void Rstring::operator=(Rvector<char> str){
    this->str = str;
    return;
}
void Rstring::operator+=(char* str) {
    Rvector<char> v = this->str;
    int i1 = this->str.size() - 1, i2 = strlen(str), i3 = i1 + i2;
    this->str.setSize(i3 + 1);
    int i;
    for(i = 0; i < i1; i++) {
        this->str[i] = v[i];
    }
    for(int j = 0; j < i2; j++, i++) {
        this->str[i] = str[j];
    }
    this->str[i3] = '\0';
	return;
}
void Rstring::operator+=(char str){
    Rvector<char> h = this->str;
    this->str.setSize(this->str.size() + 1);
    for(int i = 0; i < h.size()-1; i++) {
        this->str[i] = h[i];
    }
    this->str[h.size()-1] = str;
    this->str[this->str.size()-1] = '\0';
    return;

}
int Rstring::size() {
    return this->str.size();
}
char *Rstring::operator+(char* str) {
    int i1 = this->str.size() - 1, i3 = strlen(str) , i2 = i1 + i3;
    char* str1 = new char[i2 + 1];
    int i = 0;
    for(;i < i1; i++)
        str1[i] = this->str[i];

    for(int j = 0; j < i3; j++, i++)
        str1[i] = str[j];

    str1[i2] = '\0';
    delete [] str;
    return str1;
}
char *Rstring::operator+(const char* str) {
    int i1 = this->str.size() - 1, i3 = strlen(str) , i2 = i1 + i3;
    char* str1 = new char[i2 + 1];
    int i = 0;
    for(;i < i1; i++)
        str1[i] = this->str[i];

    for(int j = 0; j < i3; j++, i++)
        str1[i] = str[j];

    str1[i2] = '\0';
    return str1;
}
void Rstring::operator<<(char* str) {
    this->operator+=(str);
    return;
}
void Rstring::operator<<(char str){
    this->operator+=(str);
    return;
}
char& Rstring::operator[](int i) {
    return this->str[i];
}
Rstring::operator char*() {
    char *str = new char[this->size()];
    for(int i = 0; i < this->size(); i++) {
        str[i] = this->str[i];
    }
    return str;
}
void Rstring::getLineFCMD(){
    char str[100];
    scanf("%s", str);
    this->operator=(str);
}
bool Rstring::operator==(char* str){
    int size = strlen(str);
    if(size != this->str.size()-1) return false;
    for(int i = 0; i < this->str.size() - 1;i++) {
        if(this->str[i] != str[i])
            return false;
    }
    return true;
}
bool Rstring::operator!=(char* str){
    return !operator==(str);
}
