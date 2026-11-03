#ifndef BROWSERDOUBLYLIST_H
#define BROWSERDOUBLYLIST_H

#include "BrowserDoublyNode.h"
#include <string>
using namespace std;

class BrowserDoublyList
{
private:
    BrowserDoublyNode* head;
    BrowserDoublyNode* tail;
    BrowserDoublyNode* current;

public:
    BrowserDoublyList();

    void InsertPage(string url);
    void DeletePage(string url);
    void DisplayForward();
    void DisplayBackward();
    void GoBack();
    void GoForward();

    bool IsEmpty();
    bool IsNotEmpty();

    ~BrowserDoublyList();
};

#endif