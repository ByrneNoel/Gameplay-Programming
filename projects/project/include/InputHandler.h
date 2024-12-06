#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <unordered_map>
#include "Command.h"

class InputHandler 
{
public:
    void handleInput(GameObject& gameObject);
    void bindCommand(int key, Command* command);
private:
    std::unordered_map<int, Command*> commandMap;
};

#endif // INPUT_HANDLER_H
