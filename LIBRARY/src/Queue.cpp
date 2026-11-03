#include "../include/Queue.h"
#include <iostream>
using namespace std;

// Constructor
Queue::Queue()
{
    front = nullptr;
    rear = nullptr;
}

// EnQueue: Add request at the rear
void Queue::EnQueue(BookRequestNode* newNode)
{
    newNode->next = nullptr;

    if (IsEmpty())
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    cout << "Book Request Added Successfully!\n";
}

// DeQueue: Remove request from the front
BookRequestNode* Queue::DeQueue()
{
    if (IsEmpty())
    {
        cout << "Queue is Empty!\n";
        return nullptr;
    }

    BookRequestNode* temp = front;
    front = front->next;

    if (front == nullptr)
    {
        rear = nullptr;
    }

    temp->next = nullptr;
    return temp;
}

// Check if Queue is Empty
bool Queue::IsEmpty()
{
    return front == nullptr;
}

// Check if Queue is Not Empty
bool Queue::IsNotEmpty()
{
    return front != nullptr;
}

// Display all requests
void Queue::Display()
{
    if (IsEmpty())
    {
        cout << "Queue is Empty!\n";
        return;
    }

    BookRequestNode* temp = front;

    cout << "\nBook Requests (FRONT to REAR):\n";

    while (temp != nullptr)
    {
        cout << "\nStudent ID: " << temp->studentID;
        cout << "\nStudent Name: " << temp->studentName;
        cout << "\nBook ID: " << temp->bookID;
        cout << "\nBook Title: " << temp->bookTitle << endl;

        temp = temp->next;
    }
}

// Destructor
Queue::~Queue()
{
    while (front != nullptr)
    {
        BookRequestNode* temp = front;
        front = front->next;
        delete temp;
    }

    rear = nullptr;
}