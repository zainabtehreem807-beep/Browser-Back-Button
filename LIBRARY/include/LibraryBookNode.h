#ifndef LIBRARYBOOKNODE_H
#define LIBRARYBOOKNODE_H

#include <string>
using namespace std;

class LibraryBookNode
{
public:
    int bookID;
    string bookTitle;
    LibraryBookNode* next;

    LibraryBookNode(int id, string title);
};

#endif