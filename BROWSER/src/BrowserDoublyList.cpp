#include "../include/BrowserDoublyList.h"
#include <iostream>
using namespace std;

BrowserDoublyList::BrowserDoublyList()
{
    head = NULL;
    tail = NULL;
    current = NULL;
}

void BrowserDoublyList::InsertPage(string url)
{
    BrowserDoublyNode* newNode = new BrowserDoublyNode(url);

    if (head == NULL)
    {
        head = tail = current = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        current = newNode;
    }

    cout << "Page added successfully!\n";
}

void BrowserDoublyList::DeletePage(string url)
{
    if (IsEmpty())
    {
        cout << "Browser history is empty!\n";
        return;
    }

    BrowserDoublyNode* temp = head;

    while (temp != NULL && temp->url != url)
        temp = temp->next;

    if (temp == NULL)
    {
        cout << "Page not found!\n";
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    else
        tail = temp->prev;

    if (current == temp)
        current = (temp->prev != NULL) ? temp->prev : temp->next;

    delete temp;

    cout << "Page deleted successfully!\n";
}

void BrowserDoublyList::DisplayForward()
{
    if (IsEmpty())
    {
        cout << "Browser history is empty!\n";
        return;
    }

    BrowserDoublyNode* temp = head;

    cout << "\nBrowser History (First to Last):\n";

    while (temp != NULL)
    {
        cout << temp->url;

        if (temp == current)
            cout << "  <-- Current Page";

        cout << endl;
        temp = temp->next;
    }
}

void BrowserDoublyList::DisplayBackward()
{
    if (IsEmpty())
    {
        cout << "Browser history is empty!\n";
        return;
    }

    BrowserDoublyNode* temp = tail;

    cout << "\nBrowser History (Last to First):\n";

    while (temp != NULL)
    {
        cout << temp->url << endl;
        temp = temp->prev;
    }
}

void BrowserDoublyList::GoBack()
{
    if (current == NULL || current->prev == NULL)
    {
        cout << "No previous page available!\n";
        return;
    }

    current = current->prev;
    cout << "Previous page: " << current->url << endl;
}

void BrowserDoublyList::GoForward()
{
    if (current == NULL || current->next == NULL)
    {
        cout << "No next page available!\n";
        return;
    }

    current = current->next;
    cout << "Next page: " << current->url << endl;
}

bool BrowserDoublyList::IsEmpty()
{
    return head == NULL;
}

bool BrowserDoublyList::IsNotEmpty()
{
    return head != NULL;
}

BrowserDoublyList::~BrowserDoublyList()
{
    BrowserDoublyNode* temp = head;

    while (temp != NULL)
    {
        BrowserDoublyNode* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    head = tail = current = NULL;
}