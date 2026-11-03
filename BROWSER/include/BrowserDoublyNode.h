#ifndef BROWSERDOUBLYNODE_H
#define BROWSERDOUBLYNODE_H

#include <string>
using namespace std;

class BrowserDoublyNode
{
public:
    string url;
    BrowserDoublyNode* prev;
    BrowserDoublyNode* next;

    BrowserDoublyNode(string page);
};

#endif