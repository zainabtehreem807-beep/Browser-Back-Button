#include "../include/BookRequestNode.h"

BookRequestNode::BookRequestNode(int sID, string sName, int bID, string bTitle)
{
    studentID = sID;
    studentName = sName;
    bookID = bID;
    bookTitle = bTitle;
    next = nullptr;
}