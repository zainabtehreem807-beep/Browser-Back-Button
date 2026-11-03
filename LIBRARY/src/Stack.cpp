
#include "../include/Stack.h"
#include <iostream>
using namespace std;

// Default Constructor
Stack::Stack()
{
    top = nullptr;
}

// Push: Add a new book
void Stack::Push(string name)
{
    Node* newNode = new Node(name);

    newNode->next = top;
    top = newNode;

    cout << "Book added successfully!\n";
}

// Pop: Remove top book
void Stack::Pop()
{
    if (IsEmpty())
    {
        cout << "Stack is empty!\n";
        return;
    }

    Node* temp = top;

    cout << "Removed Book: " << temp->bookName << endl;

    top = top->next;
    delete temp;
}

// GetTopValue: Return top book
string Stack::GetTopValue()
{
    if (IsEmpty())
    {
        return "";
    }

    return top->bookName;
}

// Check if stack is empty
bool Stack::IsEmpty()
{
    return top == nullptr;
}

// Check if stack is not empty
bool Stack::IsNotEmpty()
{
    return top != nullptr;
}

// Display all books
void Stack::PrintStack()
{
    if (IsEmpty())
    {
        cout << "Stack is empty!\n";
        return;
    }

    Node* temp = top;

    cout << "\nBooks in Stack:\n";

    while (temp != nullptr)
    {
        cout << temp->bookName << endl;
        temp = temp->next;
    }
}

// Copy Constructor
Stack::Stack(const Stack& other)
{
    top = nullptr;

    Node* temp = other.top;
    Node* tail = nullptr;

    while (temp != nullptr)
    {
        Node* newNode = new Node(temp->bookName);

        if (top == nullptr)
        {
            top = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        temp = temp->next;
    }
}

// Assignment Operator
Stack& Stack::operator=(const Stack& other)
{
    if (this == &other)
    {
        return *this;
    }

    while (top != nullptr)
    {
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    Node* current = other.top;
    Node* tail = nullptr;

    while (current != nullptr)
    {
        Node* newNode = new Node(current->bookName);

        if (top == nullptr)
        {
            top = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        current = current->next;
    }

    return *this;
}

// Destructor
Stack::~Stack()
{
    while (top != nullptr)
    {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}
