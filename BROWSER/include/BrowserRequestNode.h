#ifndef BROWSERREQUESTNODE_H
#define BROWSERREQUESTNODE_H

#include <string>
using namespace std;

class BrowserRequestNode
{
public:
    string url;
    BrowserRequestNode* next;

    BrowserRequestNode(string page);
};

#endif