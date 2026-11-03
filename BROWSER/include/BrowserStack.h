#ifndef BROWSERSTACK_H
#define BROWSERSTACK_H

#include "BrowserNode.h"
#include <string>
using namespace std;

class BrowserStack
{
private:
    BrowserNode* top;

public:
    BrowserStack();

    void Push(string url);
    string Pop();
    string Peek();

    bool IsEmpty();
    bool IsNotEmpty();

    void Display();
    void GoBack();

    ~BrowserStack();
};

#endif