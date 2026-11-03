#ifndef BORROWINGSESSION_H
#define BORROWINGSESSION_H

#include "SessionBookNode.h"

class BorrowingSession
{
private:
    SessionBookNode* head;
    SessionBookNode* tail;
    SessionBookNode* current;

public:
    BorrowingSession();
    ~BorrowingSession();

    void DisplayCurrentBook();

    void MoveToNextBook();
    void MoveToPreviousBook();

    void InsertBookAtEnd(int id, string title);
    void InsertBookAfterCurrent(int id, string title);

    void RemoveCurrentBook();

    void DisplaySessionForward();
    void DisplaySessionBackward();

    bool IsEmpty();
};

#endif