#ifndef BROWSERNODE_H
#define BROWSERNODE_H

#include <string>
using namespace std;

class BrowserNode
{
public:
    string url;
    BrowserNode* next;

    BrowserNode(string page);
};

#endif