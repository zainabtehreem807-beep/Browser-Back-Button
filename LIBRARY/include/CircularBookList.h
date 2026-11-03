#ifndef CIRCULARBOOKLIST_H
#define CIRCULARBOOKLIST_H

#include "CircularBookNode.h"

class CircularBookList
{
private:
    CircularBookNode* head;
    CircularBookNode* current;

    int CountBooks();

public:
    CircularBookList();
    ~CircularBookList();

    void DisplayAllBooks();

    void InsertAtHead(int id, string title);
    void RemoveFromHead();

    void InsertAtIndex(int index, int id, string title);
    void RemoveAtIndex(int index);

    void SwapBooks(int index1, int index2);

    void SortBooksByID();
    void ReverseBookCollection();

    void MoveToNextBook();

    bool IsEmpty();
    bool IsNotEmpty();
};

#endif