#ifndef BROWSERPAGELIST_H
#define BROWSERPAGELIST_H

#include "BrowserPageNode.h"
#include <string>
using namespace std;

class BrowserPageList
{
private:
    BrowserPageNode* head;

public:
    BrowserPageList();

    void InsertPage(string url);
    void DeletePage(string url);
    void Display();

    bool IsEmpty();
    bool IsNotEmpty();

    ~BrowserPageList();
};

#endif