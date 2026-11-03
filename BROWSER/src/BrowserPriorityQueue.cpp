#include "../include/BrowserPriorityQueue.h"
#include <iostream>
using namespace std;

BrowserPriorityQueue::BrowserPriorityQueue()
{
    front = NULL;
}

void BrowserPriorityQueue::Enqueue(string task, int priority)
{
    BrowserTaskNode* newNode = new BrowserTaskNode(task, priority);

    if (front == NULL || priority < front->priority)
    {
        newNode->next = front;
        front = newNode;
    }
    else
    {
        BrowserTaskNode* temp = front;

        while (temp->next != NULL &&
               temp->next->priority <= priority)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    cout << "Task added successfully!\n";
}

string BrowserPriorityQueue::Dequeue()
{
    if (IsEmpty())
        return "";

    BrowserTaskNode* temp = front;
    string task = temp->task;

    front = front->next;

    delete temp;
    return task;
}

string BrowserPriorityQueue::Peek()
{
    if (IsEmpty())
        return "";

    return front->task;
}

bool BrowserPriorityQueue::IsEmpty()
{
    return front == NULL;
}

bool BrowserPriorityQueue::IsNotEmpty()
{
    return front != NULL;
}

void BrowserPriorityQueue::Display()
{
    if (IsEmpty())
    {
        cout << "Priority queue is empty!\n";
        return;
    }

    BrowserTaskNode* temp = front;

    cout << "\nBrowser Tasks (Highest Priority First):\n";

    while (temp != NULL)
    {
        cout << "Task: " << temp->task
             << " | Priority: " << temp->priority << endl;

        temp = temp->next;
    }
}

BrowserPriorityQueue::~BrowserPriorityQueue()
{
    while (IsNotEmpty())
    {
        Dequeue();
    }
}