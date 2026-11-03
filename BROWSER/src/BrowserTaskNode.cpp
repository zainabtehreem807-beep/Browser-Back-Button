#include "../include/BrowserTaskNode.h"

BrowserTaskNode::BrowserTaskNode(string t, int p)
{
    task = t;
    priority = p;
    next = NULL;
}