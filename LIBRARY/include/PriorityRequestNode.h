#ifndef PRIORITYREQUESTNODE_H
#define PRIORITYREQUESTNODE_H

#include <string>
using namespace std;

class PriorityRequestNode
{
public:
    int studentID;
    string studentName;
    int bookID;
    string bookTitle;
    int priority;

    PriorityRequestNode* next;

    PriorityRequestNode(int sID, string sName, int bID,
                        string bTitle, int p);
};

#endif