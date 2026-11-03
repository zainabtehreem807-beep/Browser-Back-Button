#include "../include/PriorityRequestNode.h"
PriorityRequestNode::PriorityRequestNode(int sID, string sName, int bID,
                                         string bTitle, int p)
{
    studentID = sID;
    studentName = sName;
    bookID = bID;
    bookTitle = bTitle;
    priority = p;
    next = nullptr;
}