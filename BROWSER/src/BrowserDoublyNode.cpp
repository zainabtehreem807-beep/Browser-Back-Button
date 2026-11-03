#include "../include/BrowserDoublyNode.h"

BrowserDoublyNode::BrowserDoublyNode(string page)
{
    url = page;
    prev = NULL;
    next = NULL;
}