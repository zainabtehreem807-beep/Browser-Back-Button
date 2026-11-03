#ifndef CIRCULARBOOKNODE_H
#define CIRCULARBOOKNODE_H

#include <string>
using namespace std;

class CircularBookNode
{
public:
    int bookID;
    string bookTitle;
    CircularBookNode* next;

    CircularBookNode(int id, string title);
};

#endif