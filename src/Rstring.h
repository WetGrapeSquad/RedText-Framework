#pragma once
#include "Rvector.h"

int strlen(const char *str);
namespace rt {
	class Rstring
	{
	public:
        Rstring();
        ~Rstring();
        Rstring(char* str);
        Rstring(const char* str);
        Rstring(Rvector<char> str);
        Rstring(char ch);
        void operator=(char* str);
        void operator=(Rvector<char> str);
        void operator+=(char* str);
        void operator+=(char str);
        char* operator+(char* str);
        char* operator+(const char* str);
        void operator<<(char* str);
        void operator<<(char str);
        char& operator[](int i);
        bool operator==(char* str);
        bool operator!=(char* str);
        int size();
        operator char*();
        void getLineFCMD();
	private:
        Rvector<char> str;
	};
}
