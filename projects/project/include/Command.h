#ifndef COMMAND_H
#define COMMAND_H

class GameObject;

class Command {
public:
    virtual ~Command() {}
    virtual void execute(GameObject& gameObject) = 0;
};

#endif // COMMAND_H
