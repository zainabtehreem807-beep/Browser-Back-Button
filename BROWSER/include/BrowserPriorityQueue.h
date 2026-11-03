#ifndef BROWSERPRIORITYQUEUE_H
#define BROWSERPRIORITYQUEUE_H

#include "BrowserTaskNode.h"
#include <string>
using namespace std;

class BrowserPriorityQueue
{
private:
    BrowserTaskNode* front;

public:
    BrowserPriorityQueue();

    void Enqueue(string task, int priority);
    string Dequeue();
    string Peek();

    bool IsEmpty();
    bool IsNotEmpty();

    void Display();

    ~BrowserPriorityQueue();
};

#endif