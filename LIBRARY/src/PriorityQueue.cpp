#include "../include/PriorityQueue.h"
#include <iostream>
using namespace std;

// Constructor
PriorityQueue::PriorityQueue()
{
    front = nullptr;
}

// EnQueue: Add request according to priority
void PriorityQueue::EnQueue(PriorityRequestNode* newNode)
{
    if (IsEmpty() || newNode->priority > front->priority)
    {
        newNode->next = front;
        front = newNode;
    }
    else
    {
        PriorityRequestNode* temp = front;

        while (temp->next != nullptr &&
               temp->next->priority >= newNode->priority)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    cout << "Priority Request Added Successfully!\n";
}

// DeQueue: Remove highest priority request
PriorityRequestNode* PriorityQueue::DeQueue()
{
    if (IsEmpty())
    {
        cout << "Priority Queue is Empty!\n";
        return nullptr;
    }

    PriorityRequestNode* temp = front;
    front = front->next;
    temp->next = nullptr;

    return temp;
}

// Check if empty
bool PriorityQueue::IsEmpty()
{
    return front == nullptr;
}

// Check if not empty
bool PriorityQueue::IsNotEmpty()
{
    return front != nullptr;
}

// Display requests
void PriorityQueue::Display()
{
    if (IsEmpty())
    {
        cout << "Priority Queue is Empty!\n";
        return;
    }

    PriorityRequestNode* temp = front;

    cout << "\nPending Requests (Highest to Lowest Priority):\n";

    while (temp != nullptr)
    {
        cout << "\nStudent ID: " << temp->studentID;
        cout << "\nStudent Name: " << temp->studentName;
        cout << "\nBook ID: " << temp->bookID;
        cout << "\nBook Title: " << temp->bookTitle;
        cout << "\nPriority: " << temp->priority << endl;

        temp = temp->next;
    }
}

// Destructor
PriorityQueue::~PriorityQueue()
{
    while (front != nullptr)
    {
        PriorityRequestNode* temp = front;
        front = front->next;
        delete temp;
    }
}