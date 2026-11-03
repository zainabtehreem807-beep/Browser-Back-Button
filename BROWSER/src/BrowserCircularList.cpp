#include "../include/BrowserCircularList.h"
#include <iostream>
using namespace std;

BrowserCircularList::BrowserCircularList()
{
    head = NULL;
}

void BrowserCircularList::InsertPage(string url)
{
    BrowserCircularNode* newNode = new BrowserCircularNode(url);

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        BrowserCircularNode* temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }

    cout << "Page added successfully!\n";
}

void BrowserCircularList::DeletePage(string url)
{
    if (head == NULL)
    {
        cout << "Browser list is empty!\n";
        return;
    }

    BrowserCircularNode* temp = head;
    BrowserCircularNode* previous = NULL;

    do
    {
        if (temp->url == url)
            break;

        previous = temp;
        temp = temp->next;

    } while (temp != head);

    if (temp->url != url)
    {
        cout << "Page not found!\n";
        return;
    }

    if (temp == head && head->next == head)
    {
        head = NULL;
    }
    else if (temp == head)
    {
        BrowserCircularNode* last = head;

        while (last->next != head)
        {
            last = last->next;
        }

        head = head->next;
        last->next = head;
    }
    else
    {
        previous->next = temp->next;
    }

    delete temp;
    cout << "Page deleted successfully!\n";
}

void BrowserCircularList::Display()
{
    if (IsEmpty())
    {
        cout << "Browser list is empty!\n";
        return;
    }

    BrowserCircularNode* temp = head;

    cout << "\nCircular Browser Pages:\n";

    do
    {
        cout << temp->url << endl;
        temp = temp->next;

    } while (temp != head);
}

void BrowserCircularList::MoveNext()
{
    if (IsEmpty())
    {
        cout << "Browser list is empty!\n";
        return;
    }

    head = head->next;

    cout << "Moved to next page: " << head->url << endl;
}

bool BrowserCircularList::IsEmpty()
{
    return head == NULL;
}

bool BrowserCircularList::IsNotEmpty()
{
    return head != NULL;
}

BrowserCircularList::~BrowserCircularList()
{
    if (head == NULL)
        return;

    BrowserCircularNode* current = head->next;

    while (current != head)
    {
        BrowserCircularNode* temp = current;
        current = current->next;
        delete temp;
    }

    delete head;
    head = NULL;
}