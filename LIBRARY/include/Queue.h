#ifndef QUEUE_H
#define QUEUE_H

#include "BookRequestNode.h"

class Queue
{
private:
    BookRequestNode* front;
    BookRequestNode* rear;

public:
    Queue();
    ~Queue();

    void EnQueue(BookRequestNode* newNode);
    BookRequestNode* DeQueue();

    bool IsEmpty();
    bool IsNotEmpty();

    void Display();
};

#endif