#ifndef BROWSERTASKNODE_H
#define BROWSERTASKNODE_H

#include <string>
using namespace std;

class BrowserTaskNode
{
public:
    string task;
    int priority;
    BrowserTaskNode* next;

    BrowserTaskNode(string t, int p);
};

#endif