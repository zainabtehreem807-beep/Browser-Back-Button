#include "../include/BookList.h"
#include <iostream>
using namespace std;

// Constructor
BookList::BookList()
{
    head = nullptr;
}

// Display all books
void BookList::DisplayAllBooks()
{
    if (IsEmpty())
    {
        cout << "Book Collection is Empty!\n";
        return;
    }

    LibraryBookNode* temp = head;

    cout << "\n===== ALL BOOKS =====\n";

    while (temp != nullptr)
    {
        cout << "Book ID: " << temp->bookID << endl;
        cout << "Book Title: " << temp->bookTitle << endl;
        cout << "----------------------\n";

        temp = temp->next;
    }
}

// Insert book at head
void BookList::InsertAtHead(int id, string title)
{
    LibraryBookNode* newNode = new LibraryBookNode(id, title);

    newNode->next = head;
    head = newNode;

    cout << "Book Inserted at Head Successfully!\n";
}

// Remove book from head
void BookList::RemoveFromHead()
{
    if (IsEmpty())
    {
        cout << "Book Collection is Empty!\n";
        return;
    }

    LibraryBookNode* temp = head;

    cout << "Removed Book: " << temp->bookTitle << endl;

    head = head->next;
    delete temp;
}

// Insert book at index (0-based)
void BookList::InsertAtIndex(int index, int id, string title)
{
    if (index < 0)
    {
        cout << "Invalid Index!\n";
        return;
    }

    if (index == 0)
    {
        InsertAtHead(id, title);
        return;
    }

    LibraryBookNode* temp = head;

    for (int i = 0; i < index - 1 && temp != nullptr; i++)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "Index Out of Range!\n";
        return;
    }

    LibraryBookNode* newNode = new LibraryBookNode(id, title);

    newNode->next = temp->next;
    temp->next = newNode;

    cout << "Book Inserted Successfully!\n";
}

// Remove book at index (0-based)
void BookList::RemoveAtIndex(int index)
{
    if (index < 0 || IsEmpty())
    {
        cout << "Invalid Index or Empty Collection!\n";
        return;
    }

    if (index == 0)
    {
        RemoveFromHead();
        return;
    }

    LibraryBookNode* temp = head;

    for (int i = 0; i < index - 1 && temp != nullptr; i++)
    {
        temp = temp->next;
    }

    if (temp == nullptr || temp->next == nullptr)
    {
        cout << "Index Out of Range!\n";
        return;
    }

    LibraryBookNode* nodeToDelete = temp->next;

    temp->next = nodeToDelete->next;

    cout << "Removed Book: " << nodeToDelete->bookTitle << endl;

    delete nodeToDelete;
}

// Swap books using indexes
void BookList::SwapBooks(int index1, int index2)
{
    if (index1 < 0 || index2 < 0)
    {
        cout << "Invalid Index!\n";
        return;
    }

    if (index1 == index2)
    {
        cout << "Both indexes are same. No swapping needed.\n";
        return;
    }

    LibraryBookNode* node1 = head;
    LibraryBookNode* node2 = head;

    for (int i = 0; i < index1 && node1 != nullptr; i++)
        node1 = node1->next;

    for (int i = 0; i < index2 && node2 != nullptr; i++)
        node2 = node2->next;

    if (node1 == nullptr || node2 == nullptr)
    {
        cout << "Index Out of Range!\n";
        return;
    }

    int tempID = node1->bookID;
    string tempTitle = node1->bookTitle;

    node1->bookID = node2->bookID;
    node1->bookTitle = node2->bookTitle;

    node2->bookID = tempID;
    node2->bookTitle = tempTitle;

    cout << "Books Swapped Successfully!\n";
}

// Sort books by ID
void BookList::SortBooksByID()
{
    if (IsEmpty() || head->next == nullptr)
    {
        cout << "Not Enough Books to Sort!\n";
        return;
    }

    for (LibraryBookNode* i = head; i != nullptr; i = i->next)
    {
        for (LibraryBookNode* j = i->next; j != nullptr; j = j->next)
        {
            if (i->bookID > j->bookID)
            {
                int tempID = i->bookID;
                string tempTitle = i->bookTitle;

                i->bookID = j->bookID;
                i->bookTitle = j->bookTitle;

                j->bookID = tempID;
                j->bookTitle = tempTitle;
            }
        }
    }

    cout << "Books Sorted by ID Successfully!\n";
}

// Reverse book collection
void BookList::ReverseBookCollection()
{
    LibraryBookNode* previous = nullptr;
    LibraryBookNode* current = head;
    LibraryBookNode* nextNode = nullptr;

    while (current != nullptr)
    {
        nextNode = current->next;
        current->next = previous;

        previous = current;
        current = nextNode;
    }

    head = previous;

    cout << "Book Collection Reversed Successfully!\n";
}

// Check if empty
bool BookList::IsEmpty()
{
    return head == nullptr;
}

// Check if not empty
bool BookList::IsNotEmpty()
{
    return head != nullptr;
}

// Destructor
BookList::~BookList()
{
    while (head != nullptr)
    {
        LibraryBookNode* temp = head;
        head = head->next;
        delete temp;
    }
}