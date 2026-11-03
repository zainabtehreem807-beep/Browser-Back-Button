#ifndef BOOKLIST_H
#define BOOKLIST_H

#include "LibraryBookNode.h"

class BookList
{
private:
    LibraryBookNode* head;

public:
    BookList();
    ~BookList();

    void DisplayAllBooks();

    void InsertAtHead(int id, string title);
    void RemoveFromHead();

    void InsertAtIndex(int index, int id, string title);
    void RemoveAtIndex(int index);

    void SwapBooks(int index1, int index2);

    void SortBooksByID();
    void ReverseBookCollection();

    bool IsEmpty();
    bool IsNotEmpty();
};

#endif