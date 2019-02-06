#include "class/Engine/Engine.h"

int main()
{
    InputQueue a;
    KeyAndAction tmp(' ',2);
    a.AddLast(tmp);
    std::cout << a.GetSize() << "\n";
    a._DebugPrint();
    for(int i = 32; i < 127; i++){
        tmp(i,1);
        a.AddLast(tmp);
        tmp(i,0);
        a.AddLast(tmp);
    }
    std::cout << a.GetSize() << "\n";
    a._DebugPrint();

    return 0;
}
