#include "input.h"
#include <iostream>
#include "../MutexLock/MutexLock.h"
#include <algorithm>
Input::Input(void (*KeyboardKeyPressedCallback)(char),void (*KeyboardKeyRepeatCallback)(char),void (*KeyboardKeyReleasedCallback)(char)):
_KeyboardKeyPressedCallback(KeyboardKeyPressedCallback),_KeyboardKeyRepeatCallback(KeyboardKeyRepeatCallback),_KeyboardKeyReleasedCallback(KeyboardKeyReleasedCallback),Exit(0){
    for(int i = 0; i < 127; i++){
        if(i < 4) _PrevKeys[i] = 0;
        _keyboardKeyState[i] = 0;
    }
}
/**Setters*/
void Input::SetkeyboardKeyState(char key, char state){
    mutexLock lock(mtxKeys,1);
    _keyboardKeyState[key] = state;
}
void Input::SetPrevKeys(char key,unsigned int index){
    mutexLock lock(mtxKeys,1);
    _PrevKeys[index] = key;
}
void Input::AddPrevKey(char key){
    for(int i = 0; i < 3; _PrevKeys[i + 1] = _PrevKeys[i++]);
    _PrevKeys[0] = key;
}
void Input::SetExit(bool value){
    mutexLock lock(mtxKeys,1);
    Exit = value;
}
/**Getters*/
char Input::GetkeyboardKeyState(char key){
    mutexLock lock(mtxKeys,1);
    return _keyboardKeyState[key];

}
 char Input::GetPrevKey(unsigned int index){
    mutexLock lock(mtxKeys,1);
    return _PrevKeys[index];
}
bool Input::GetExit(){
    mutexLock lock(mtxKeys,1);
    return Exit;
}
void Input::Run(){
    auto _lastUpdate = std::chrono::high_resolution_clock::now();
    while(! GetExit()){
        AddPrevKey(_getch());
        if(GetPrevKey(0) == 27) SetExit(true);
        auto Now = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> time = Now - _lastUpdate;
        auto _lastUpdate = std::chrono::high_resolution_clock::now();
        if((GetPrevKey(1) == GetPrevKey(0))){
            SetkeyboardKeyState(GetPrevKey(0),2);
            _KeyboardKeyRepeatCallback(GetPrevKey(0));
        }
        else{SetkeyboardKeyState(GetPrevKey(0),1);
        _KeyboardKeyPressedCallback(GetPrevKey(0));}


        SetkeyboardKeyState(GetPrevKey(0),0);
        _KeyboardKeyReleasedCallback(GetPrevKey(0));
    }
}
