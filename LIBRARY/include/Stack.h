
#ifndef STACK_H
#define STACK_H

#include "Node.h"

class Stack
{
private:
    Node* top;

public:
    Stack();
    Stack(const Stack& other);
    Stack& operator=(const Stack& other);
    ~Stack();

    void Push(string name);
    void Pop();
    string GetTopValue();

    bool IsEmpty();
    bool IsNotEmpty();

    void PrintStack();
};

#endif
