#include "../include/CircularBookList.h"
#include <iostream>
using namespace std;

// Constructor
CircularBookList::CircularBookList()
{
    head = nullptr;
    current = nullptr;
}

// Count total books
int CircularBookList::CountBooks()
{
    if (head == nullptr)
        return 0;

    int count = 0;
    CircularBookNode* temp = head;

    do
    {
        count++;
        temp = temp->next;
    }
    while (temp != head);

    return count;
}

// Display all books
void CircularBookList::DisplayAllBooks()
{
    if (IsEmpty())
    {
        cout << "Book Collection is Empty!\n";
        return;
    }

    CircularBookNode* temp = head;

    cout << "\n===== ALL BOOKS =====\n";

    do
    {
        cout << "Book ID: " << temp->bookID << endl;
        cout << "Book Title: " << temp->bookTitle << endl;
        cout << "----------------------\n";

        temp = temp->next;
    }
    while (temp != head);
}

// Insert book at head
void CircularBookList::InsertAtHead(int id, string title)
{
    CircularBookNode* newNode =
        new CircularBookNode(id, title);

    if (IsEmpty())
    {
        head = newNode;
        newNode->next = head;
        current = head;
    }
    else
    {
        CircularBookNode* temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    cout << "Book Inserted at Head Successfully!\n";
}

// Remove book from head
void CircularBookList::RemoveFromHead()
{
    if (IsEmpty())
    {
        cout << "Book Collection is Empty!\n";
        return;
    }

    CircularBookNode* temp = head;

    if (head->next == head)
    {
        head = nullptr;
        current = nullptr;
    }
    else
    {
        CircularBookNode* last = head;

        while (last->next != head)
        {
            last = last->next;
        }

        head = head->next;
        last->next = head;

        if (current == temp)
        {
            current = head;
        }
    }

    cout << "Removed Book: " << temp->bookTitle << endl;
    delete temp;
}

// Insert book at index (0-based)
void CircularBookList::InsertAtIndex(
    int index, int id, string title)
{
    int total = CountBooks();

    if (index < 0 || index > total)
    {
        cout << "Invalid Index!\n";
        return;
    }

    if (index == 0)
    {
        InsertAtHead(id, title);
        return;
    }

    CircularBookNode* temp = head;

    for (int i = 0; i < index - 1; i++)
    {
        temp = temp->next;
    }

    CircularBookNode* newNode =
        new CircularBookNode(id, title);

    newNode->next = temp->next;
    temp->next = newNode;

    cout << "Book Inserted Successfully!\n";
}

// Remove book at index (0-based)
void CircularBookList::RemoveAtIndex(int index)
{
    int total = CountBooks();

    if (index < 0 || index >= total)
    {
        cout << "Invalid Index!\n";
        return;
    }

    if (index == 0)
    {
        RemoveFromHead();
        return;
    }

    CircularBookNode* temp = head;

    for (int i = 0; i < index - 1; i++)
    {
        temp = temp->next;
    }

    CircularBookNode* nodeToDelete = temp->next;

    temp->next = nodeToDelete->next;

    if (current == nodeToDelete)
    {
        current = nodeToDelete->next;
    }

    cout << "Removed Book: "
         << nodeToDelete->bookTitle << endl;

    delete nodeToDelete;
}

// Swap books using indexes
void CircularBookList::SwapBooks(int index1, int index2)
{
    int total = CountBooks();

    if (index1 < 0 || index2 < 0 ||
        index1 >= total || index2 >= total)
    {
        cout << "Invalid Index!\n";
        return;
    }

    if (index1 == index2)
    {
        cout << "Both indexes are same!\n";
        return;
    }

    CircularBookNode* node1 = head;
    CircularBookNode* node2 = head;

    for (int i = 0; i < index1; i++)
        node1 = node1->next;

    for (int i = 0; i < index2; i++)
        node2 = node2->next;

    int tempID = node1->bookID;
    string tempTitle = node1->bookTitle;

    node1->bookID = node2->bookID;
    node1->bookTitle = node2->bookTitle;

    node2->bookID = tempID;
    node2->bookTitle = tempTitle;

    cout << "Books Swapped Successfully!\n";
}

// Sort books by ID
void CircularBookList::SortBooksByID()
{
    int total = CountBooks();

    if (total < 2)
    {
        cout << "Not Enough Books to Sort!\n";
        return;
    }

    CircularBookNode* i = head;

    for (int x = 0; x < total - 1; x++)
    {
        CircularBookNode* j = i->next;

        for (int y = x + 1; y < total; y++)
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

            j = j->next;
        }

        i = i->next;
    }

    cout << "Books Sorted by ID Successfully!\n";
}

// Reverse book collection
void CircularBookList::ReverseBookCollection()
{
    if (IsEmpty() || head->next == head)
    {
        cout << "Not Enough Books to Reverse!\n";
        return;
    }

    CircularBookNode* previous = head;
    CircularBookNode* currentNode = head->next;
    CircularBookNode* nextNode = nullptr;

    while (currentNode != head)
    {
        nextNode = currentNode->next;
        currentNode->next = previous;

        previous = currentNode;
        currentNode = nextNode;
    }

    head->next = previous;
    head = previous;

    cout << "Book Collection Reversed Successfully!\n";
}

// Move to next book
void CircularBookList::MoveToNextBook()
{
    if (IsEmpty())
    {
        cout << "Book Collection is Empty!\n";
        return;
    }

    current = current->next;

    cout << "\nCurrent Book:\n";
    cout << "Book ID: " << current->bookID << endl;
    cout << "Book Title: " << current->bookTitle << endl;
}

// Check if empty
bool CircularBookList::IsEmpty()
{
    return head == nullptr;
}

// Check if not empty
bool CircularBookList::IsNotEmpty()
{
    return head != nullptr;
}

// Destructor
CircularBookList::~CircularBookList()
{
    if (head == nullptr)
        return;

    CircularBookNode* temp = head->next;

    while (temp != head)
    {
        CircularBookNode* nodeToDelete = temp;
        temp = temp->next;
        delete nodeToDelete;
    }

    delete head;

    head = nullptr;
    current = nullptr;
}