#include "../include/SessionBookNode.h"

SessionBookNode::SessionBookNode(int id, string title)
{
    bookID = id;
    bookTitle = title;

    next = nullptr;
    prev = nullptr;
}