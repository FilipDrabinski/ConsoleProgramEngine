#include "Input.h"
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

/**---InputQueueNode---**/
InputQueueNode::InputQueueNode(InputQueueNode* previous,KeyAndAction data,InputQueueNode* next)
                               :_previous(previous),_data(data),_next(next){}

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

/**--InputQueue--**/
