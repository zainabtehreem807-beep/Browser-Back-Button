#include "../include/BrowserQueue.h"
#include <iostream>
using namespace std;

BrowserQueue::BrowserQueue()
{
    front = NULL;
    rear = NULL;
}

void BrowserQueue::Enqueue(string url)
{
    BrowserRequestNode* newNode = new BrowserRequestNode(url);

    if (IsEmpty())
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    cout << "Request added successfully!\n";
}

string BrowserQueue::Dequeue()
{
    if (IsEmpty())
    {
        return "";
    }

    BrowserRequestNode* temp = front;
    string page = temp->url;

    front = front->next;

    if (front == NULL)
    {
        rear = NULL;
    }

    delete temp;
    return page;
}

string BrowserQueue::Peek()
{
    if (IsEmpty())
    {
        return "";
    }

    return front->url;
}

bool BrowserQueue::IsEmpty()
{
    return front == NULL;
}

bool BrowserQueue::IsNotEmpty()
{
    return front != NULL;
}

void BrowserQueue::Display()
{
    if (IsEmpty())
    {
        cout << "Request queue is empty!\n";
        return;
    }

    BrowserRequestNode* temp = front;

    cout << "\nPending Browser Requests:\n";

    while (temp != NULL)
    {
        cout << temp->url << endl;
        temp = temp->next;
    }
}

BrowserQueue::~BrowserQueue()
{
    while (IsNotEmpty())
    {
        Dequeue();
    }
}