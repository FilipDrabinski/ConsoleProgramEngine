#ifndef INPUT_H
#define INPUT_H

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

public:
};

class Input{
private:

public:

};
#endif // INPUT_H
