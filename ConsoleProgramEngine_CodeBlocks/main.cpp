#include "class/Engine/Engine.h"

int main()
{
    KeyAndAction a('a',0);
    a('b',1);
    InputQueueNode IQN(nullptr,a,nullptr);
    InputQueueNode IQN2(&IQN,a,nullptr);
    IQN2.SetPreviousPtr(nullptr);
    return 0;
}
