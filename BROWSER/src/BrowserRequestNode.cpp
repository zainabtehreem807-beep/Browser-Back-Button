#include "../include/BrowserRequestNode.h"

BrowserRequestNode::BrowserRequestNode(string page)
{
    url = page;
    next = NULL;
}