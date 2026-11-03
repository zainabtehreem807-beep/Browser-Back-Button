#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "PriorityRequestNode.h"

class PriorityQueue
{
private:
    PriorityRequestNode* front;

public:
    PriorityQueue();
    ~PriorityQueue();

    void EnQueue(PriorityRequestNode* newNode);
    PriorityRequestNode* DeQueue();

    bool IsEmpty();
    bool IsNotEmpty();

    void Display();
};

#endif