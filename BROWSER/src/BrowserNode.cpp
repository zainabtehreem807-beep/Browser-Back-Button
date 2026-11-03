#include "../include/BrowserNode.h"

BrowserNode::BrowserNode(string page)
{
    url = page;
    next = NULL;
}