#ifndef BROWSERCIRCULARNODE_H
#define BROWSERCIRCULARNODE_H

#include <string>
using namespace std;

class BrowserCircularNode
{
public:
    string url;
    BrowserCircularNode* next;

    BrowserCircularNode(string page);
};

#endif