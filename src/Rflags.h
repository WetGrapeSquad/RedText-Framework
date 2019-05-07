#pragma once

namespace rt {
    class Rflags
    {
    public:
        Rflags();
        Rflags(const char* str);
        Rflags(const char* str,const  char fg);
        char* GetFlag(int i);
        int GetCountFlag();
        void operator()(char* str);
        void SetClear();
        bool ifflag(char *ch);
    private:
        char* str;
        char fg;
        bool Clear;
        int fc;
    };

}
