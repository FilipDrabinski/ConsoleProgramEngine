#ifndef INPUT_H
#define INPUT_H
#define PREV_KEY_BUFFER_SIZE 4
#include "InputDebug.h"
#include <thread>
#include <mutex>
#include <chrono>


struct KeyAndAction{
    char key;
    unsigned int action:2;
    KeyAndAction(){}
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
    ~InputQueue();
    void SetHead(InputQueueNode* newHead);
    InputQueueNode* GetHead();

    void SetTail(InputQueueNode* newTail);
    InputQueueNode* GetTail();

    unsigned int GetSize();
    bool IsEmpty();

    void AddLast(KeyAndAction data);

    KeyAndAction GetFirst();
    void DeleteFirst();

    void _DebugPrint();
};

class Input{
private:
    InputQueue _queue;
    KeyAndAction _history[PREV_KEY_BUFFER_SIZE];
    bool _exit;
    bool _pause;
    std::mutex _mtxKeys;
    std::chrono::steady_clock::time_point _lastUpdate;
    std::thread* _inputLoop;
    std::thread* _releaseTimer;
    bool _repeatedFlag;
public:
    Input();

    void PauseInput();
    void ResumeInput();
    bool IsPaused();

    KeyAndAction GetQueueElement();
    KeyAndAction GetPreviousKey(unsigned int index);

    void SetExit(bool newState);
    bool GetExit();
private:
    void _InputLoop();
    void _ReleaseTimer();


};
#endif // INPUT_H
//test
