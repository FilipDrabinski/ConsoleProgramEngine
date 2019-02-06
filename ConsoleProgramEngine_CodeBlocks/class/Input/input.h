#ifndef INPUT_H
#define INPUT_H
#include "InputDebug_Mode.h"
#include <thread>
#include <mutex>

struct KeyAndAction{
    char key;
    unsigned int action:2;
    KeyAndAction(char key, unsigned int action);
    KeyAndAction& operator()(char key, unsigned int action);
};

class InputQueueNode{
private:
    InputQueueNode* _previous;
    KeyAndAction _data;
    InputQueueNode* _next;
public:
    InputQueueNode(InputQueueNode* previous,KeyAndAction data,InputQueueNode* next = nullptr);

    void SetPreviousPtr(InputQueueNode* newPrevious);
    InputQueueNode* GetPreviousPtr();

    void SetData(KeyAndAction newData);
    KeyAndAction GetData();

    void SetNextPtr(InputQueueNode* newNext);
    InputQueueNode* GetNextPtr();

    void CreateNext(KeyAndAction data);
    void DeleteNext();

    void DeletePrevious();



};

class InputQueue{
private:
    InputQueueNode* _head;
    InputQueueNode* _tail;
    unsigned int _size;
public:
    InputQueue();

    void SetHead(InputQueueNode* newHead);
    InputQueueNode* GetHead();

    void SetTail(InputQueueNode* newTail);
    InputQueueNode* GetTail();

    KeyAndAction GetFirst();
    void DeleteFirst();
#if DEBUG_MODE
    void DebugPrint();
#endif // DEBUG_MODE
};

class Input{
private:
    KeyAndAction history[4];
    InputQueue _queue;
    bool newInput;
    std::thread* _releaseTimer;
    std::thread* _InputLoop;
    std::mutex _mtxInput;

public:

};
#endif // INPUT_H
