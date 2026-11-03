#ifndef BROWSERCIRCULARLIST_H
#define BROWSERCIRCULARLIST_H

#include "BrowserCircularNode.h"
#include <string>
using namespace std;

class BrowserCircularList
{
private:
    BrowserCircularNode* head;

public:
    BrowserCircularList();

    void InsertPage(string url);
    void DeletePage(string url);
    void Display();
    void MoveNext();

    bool IsEmpty();
    bool IsNotEmpty();

    ~BrowserCircularList();
};

#endif