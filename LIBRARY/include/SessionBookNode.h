#ifndef SESSIONBOOKNODE_H
#define SESSIONBOOKNODE_H

#include <string>
using namespace std;

class SessionBookNode
{
public:
    int bookID;
    string bookTitle;

    SessionBookNode* next;
    SessionBookNode* prev;

    SessionBookNode(int id, string title);
};

#endif