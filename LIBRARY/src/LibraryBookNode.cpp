#include "../include/LibraryBookNode.h"
LibraryBookNode::LibraryBookNode(int id, string title)
{
    bookID = id;
    bookTitle = title;
    next = nullptr;
}