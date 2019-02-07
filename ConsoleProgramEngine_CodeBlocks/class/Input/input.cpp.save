#include "Input.h"
#include "InputDebug.h"
/**==================================================================**/
/**---KeyAndAction---**/
KeyAndAction::KeyAndAction(char key,unsigned int action){
    this->key = key;
    if (action < 3)this->action = action;
    else this->action = 3;// Unknown
}
KeyAndAction& KeyAndAction::operator()(char key, unsigned int action){
    this->key = key;
    if (action < 3)this->action = action;
    else this->action = 3;// Unknown
}
/**==================================================================**/
/**---InputQueueNode---**/
InputQueueNode::InputQueueNode(InputQueueNode* previous,KeyAndAction data,InputQueueNode* next):_previous(previous),_data(data),_next(next){}

void InputQueueNode::SetPreviousPtr(InputQueueNode* newPrevious){
    _previous = newPrevious;
}
InputQueueNode* InputQueueNode::GetPreviousPtr(){
    return _previous;
}

void InputQueueNode::SetData(KeyAndAction newData){
    _data = newData;
}
KeyAndAction InputQueueNode::GetData(){
    return _data;
}

void InputQueueNode::SetNextPtr(InputQueueNode* newNext){
    _next = newNext;
}
InputQueueNode* InputQueueNode::GetNextPtr(){
    return _next;
}

void InputQueueNode::CreateNext(KeyAndAction data){
    _next = new InputQueueNode(this,data);
}
void InputQueueNode::DeleteNext(){
    if(_next != nullptr) delete _next;
}

void InputQueueNode::DeletePrevious(){
    InputQueueNode* tmp = _previous->_previous;
    delete tmp->_next;
    tmp->_next = this;
}
/**==================================================================**/
/**--InputQueue--**/
InputQueue::InputQueue():_head(nullptr),_tail(nullptr),_size(0){}

void InputQueue::SetHead(InputQueueNode* newHead){
    _head = newHead;
}
InputQueueNode* InputQueue::GetHead(){
    return _head;
}

void InputQueue::SetTail(InputQueueNode* newTail){
    _tail = newTail;
}
InputQueueNode* InputQueue::GetTail(){
    return _tail;
}

unsigned int InputQueue::GetSize(){
    return _size;
}
bool InputQueue::IsEmpty(){
    return (_size == 0);
}

void InputQueue::AddLast(KeyAndAction data){
    if(_size == 0){
        _head = new InputQueueNode(nullptr,data);
        _tail = _head;
        _size++;
        return;
    }
    while((data.action == 0)&&(_tail->GetData().action == 2)&&(data.key = _tail->GetData().key)&&(_tail !=_head)){
        _tail = _tail->GetPreviousPtr();
        _tail->DeleteNext();
        _size--;
    }
    while((data.action == 0)&&(_tail->GetData().action == 0)){
        _tail = _tail->GetPreviousPtr();
        _tail->DeleteNext();
        _size--;
    }
    _tail->CreateNext(data);
    _tail = _tail->GetNextPtr();
    _size++;
    return;
}

KeyAndAction InputQueue::GetFirst(){
    return _head->GetData();
}
void InputQueue::DeleteFirst(){
    InputQueueNode* tmp = _head->GetNextPtr();
    delete _head;
    _head = tmp;
    _size --;
}

void InputQueue::_DebugPrint(){
    if(_head == nullptr)return;
    InputQueueNode* tmp = _head;
    while(tmp != nullptr){
        std::cout << "(" << tmp->GetData().key <<", "<< tmp->GetData().action<<") ";
        tmp = tmp->GetNextPtr();
    }
}











