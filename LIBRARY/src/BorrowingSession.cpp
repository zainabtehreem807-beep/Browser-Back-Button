#include "../include/BorrowingSession.h"
#include <iostream>
using namespace std;

// Constructor
BorrowingSession::BorrowingSession()
{
    head = nullptr;
    tail = nullptr;
    current = nullptr;
}

// Check if session is empty
bool BorrowingSession::IsEmpty()
{
    return head == nullptr;
}

// Display current book
void BorrowingSession::DisplayCurrentBook()
{
    if (IsEmpty())
    {
        cout << "Borrowing Session is Empty!\n";
        return;
    }

    if (current == nullptr)
    {
        cout << "No Current Book Selected!\n";
        return;
    }

    cout << "\n===== CURRENT BOOK =====\n";
    cout << "Book ID: " << current->bookID << endl;
    cout << "Book Title: " << current->bookTitle << endl;
}

// Move to next book
void BorrowingSession::MoveToNextBook()
{
    if (IsEmpty())
    {
        cout << "Borrowing Session is Empty!\n";
        return;
    }

    if (current == nullptr || current->next == nullptr)
    {
        cout << "No Next Book Available!\n";
        return;
    }

    current = current->next;

    cout << "Moved to Next Book Successfully!\n";
    DisplayCurrentBook();
}

// Move to previous book
void BorrowingSession::MoveToPreviousBook()
{
    if (IsEmpty())
    {
        cout << "Borrowing Session is Empty!\n";
        return;
    }

    if (current == nullptr || current->prev == nullptr)
    {
        cout << "No Previous Book Available!\n";
        return;
    }

    current = current->prev;

    cout << "Moved to Previous Book Successfully!\n";
    DisplayCurrentBook();
}

// Insert book at the end
void BorrowingSession::InsertBookAtEnd(int id, string title)
{
    SessionBookNode* newNode =
        new SessionBookNode(id, title);

    if (IsEmpty())
    {
        head = newNode;
        tail = newNode;
        current = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;

        tail = newNode;
    }

    cout << "Book Inserted at End Successfully!\n";
}

// Insert book after current book
void BorrowingSession::InsertBookAfterCurrent(int id, string title)
{
    if (IsEmpty() || current == nullptr)
    {
        cout << "No Current Book Available!\n";
        return;
    }

    SessionBookNode* newNode =
        new SessionBookNode(id, title);

    newNode->next = current->next;
    newNode->prev = current;

    if (current->next != nullptr)
    {
        current->next->prev = newNode;
    }
    else
    {
        tail = newNode;
    }

    current->next = newNode;

    cout << "Book Inserted After Current Book Successfully!\n";
}

// Remove current book
void BorrowingSession::RemoveCurrentBook()
{
    if (IsEmpty() || current == nullptr)
    {
        cout << "No Current Book Available!\n";
        return;
    }

    SessionBookNode* temp = current;

    cout << "Removed Book: " << temp->bookTitle << endl;

    if (temp->prev != nullptr)
    {
        temp->prev->next = temp->next;
    }
    else
    {
        head = temp->next;
    }

    if (temp->next != nullptr)
    {
        temp->next->prev = temp->prev;
        current = temp->next;
    }
    else
    {
        tail = temp->prev;
        current = temp->prev;
    }

    delete temp;

    if (head == nullptr)
    {
        tail = nullptr;
        current = nullptr;
    }
}

// Display session from first to last
void BorrowingSession::DisplaySessionForward()
{
    if (IsEmpty())
    {
        cout << "Borrowing Session is Empty!\n";
        return;
    }

    SessionBookNode* temp = head;

    cout << "\n===== SESSION: FIRST TO LAST =====\n";

    while (temp != nullptr)
    {
        cout << "Book ID: " << temp->bookID << endl;
        cout << "Book Title: " << temp->bookTitle << endl;
        cout << "----------------------\n";

        temp = temp->next;
    }
}

// Display session from last to first
void BorrowingSession::DisplaySessionBackward()
{
    if (IsEmpty())
    {
        cout << "Borrowing Session is Empty!\n";
        return;
    }

    SessionBookNode* temp = tail;

    cout << "\n===== SESSION: LAST TO FIRST =====\n";

    while (temp != nullptr)
    {
        cout << "Book ID: " << temp->bookID << endl;
        cout << "Book Title: " << temp->bookTitle << endl;
        cout << "----------------------\n";

        temp = temp->prev;
    }
}

// Destructor
BorrowingSession::~BorrowingSession()
{
    SessionBookNode* temp = head;

    while (temp != nullptr)
    {
        SessionBookNode* nodeToDelete = temp;
        temp = temp->next;

        delete nodeToDelete;
    }

    head = nullptr;
    tail = nullptr;
    current = nullptr;
}