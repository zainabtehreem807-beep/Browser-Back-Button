#ifndef BOOKREQUESTNODE_H
#define BOOKREQUESTNODE_H

#include <string>
using namespace std;

class BookRequestNode
{
public:
    int studentID;
    string studentName;
    int bookID;
    string bookTitle;
    BookRequestNode* next;

    BookRequestNode(int sID, string sName, int bID, string bTitle);
};

#endif