#ifndef BROWSERPAGENODE_H
#define BROWSERPAGENODE_H

#include <string>
using namespace std;

class BrowserPageNode
{
public:
    string url;
    BrowserPageNode* next;

    BrowserPageNode(string page);
};

#endif