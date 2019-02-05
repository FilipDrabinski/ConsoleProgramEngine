#ifndef INPUT_H
#define INPUT_H
#include <conio.h>
#include <mutex>
#include <vector>
/**TODO:
    Calibrate repeat timer
*/
class Input{
private:
    char _keyboardKeyState[127];
    char _PrevKeys[4];
    std::mutex mtxKeys;
    void (*_KeyboardKeyPressedCallback)(char);
    void (*_KeyboardKeyRepeatCallback)(char);
    void (*_KeyboardKeyReleasedCallback)(char);
    bool Exit;
public:
    Input(void (*KeyboardKeyPressedCallback)(char),void (*KeyboardKeyRepeatCallback)(char),void (*KeyboardKeyReleasedCallback)(char));
    /**Setters*/
    void SetkeyboardKeyState(char key, char state);
    void SetPrevKeys(char key,unsigned int index);
    void AddPrevKey(char key);
    void SetExit(bool value);
    /**Getters*/
    char GetkeyboardKeyState(char key);
    char GetPrevKey(unsigned int index);
    bool GetExit();

    void Run();

};


#endif // INPUT_H
