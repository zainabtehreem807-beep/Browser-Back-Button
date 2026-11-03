#include "../include/CircularBookNode.h"

CircularBookNode::CircularBookNode(int id, string title)
{
    bookID = id;
    bookTitle = title;
    next = nullptr;
}