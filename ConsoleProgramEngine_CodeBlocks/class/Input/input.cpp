#include "Input.h"
#include "InputDebug_Mode.h"
/**---KeyAndAction---**/
KeyAndAction::KeyAndAction(char key,unsigned int action){
    this->key = key;
    if (action < 3)this->action = action;
    else this->action = 3;// Unknown
    $I_MSG(_PF_ << ":\n\t-KeyAndAction instance created ["<< this <<"] ('" << this->key <<"',"<<this->action<<")" << _END_I_MSG_)
}
KeyAndAction& KeyAndAction::operator()(char key, unsigned int action){
    $I_MSG(_PF_ << ":\n\t-KeyAndAction instance edited  ["<< this <<"] ('" << this->key <<"',"<<this->action<<")->(")
    this->key = key;
    if (action < 3)this->action = action;
    else this->action = 3;// Unknown
    $I_MSG(this->key <<","<<this->action << ")"<<_END_I_MSG_)
}

/**---InputQueueNode---**/
InputQueueNode::InputQueueNode(InputQueueNode* previous,KeyAndAction data,InputQueueNode* next)
:_previous(previous),_data(data),_next(next){
    $I_MSG(_PF_ << ":\n\t-InputQueueNode instance created ["<<this<<"]: (["<< _previous <<"], '"<< _data.key <<"', "<< _data.action <<", ["<< _next <<"])"<<_END_I_MSG_)
}

void InputQueueNode::SetPreviousPtr(InputQueueNode* newPrevious){
    $I_MSG(_PF_ << ":\n\t-InputQueueNode instance edited ["<<this<<"]: (["<< _previous <<"], '"<< _data.key <<"', "<< _data.action <<", ["<< _next <<"])"<<"->(["<< newPrevious <<"], "<< _data.key <<", "<< _data.action <<", ["<< _next <<"])"<<_END_I_MSG_)
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
