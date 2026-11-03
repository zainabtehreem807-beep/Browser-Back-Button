#ifndef BROWSERQUEUE_H
#define BROWSERQUEUE_H

#include "BrowserRequestNode.h"
#include <string>
using namespace std;

class BrowserQueue
{
private:
    BrowserRequestNode* front;
    BrowserRequestNode* rear;

public:
    BrowserQueue();

    void Enqueue(string url);
    string Dequeue();
    string Peek();

    bool IsEmpty();
    bool IsNotEmpty();

    void Display();

    ~BrowserQueue();
};

#endif