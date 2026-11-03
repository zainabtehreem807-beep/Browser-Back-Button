#include "../include/BrowserPageList.h"
#include <iostream>
using namespace std;

BrowserPageList::BrowserPageList()
{
    head = NULL;
}

void BrowserPageList::InsertPage(string url)
{
    BrowserPageNode* newNode = new BrowserPageNode(url);

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        BrowserPageNode* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    cout << "Page added successfully!\n";
}

void BrowserPageList::DeletePage(string url)
{
    if (head == NULL)
    {
        cout << "Browser page list is empty!\n";
        return;
    }

    if (head->url == url)
    {
        BrowserPageNode* temp = head;
        head = head->next;
        delete temp;

        cout << "Page deleted successfully!\n";
        return;
    }

    BrowserPageNode* temp = head;

    while (temp->next != NULL && temp->next->url != url)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        cout << "Page not found!\n";
        return;
    }

    BrowserPageNode* deleteNode = temp->next;
    temp->next = deleteNode->next;
    delete deleteNode;

    cout << "Page deleted successfully!\n";
}

void BrowserPageList::Display()
{
    if (IsEmpty())
    {
        cout << "Browser page list is empty!\n";
        return;
    }

    BrowserPageNode* temp = head;

    cout << "\nBrowser Pages:\n";

    while (temp != NULL)
    {
        cout << temp->url << endl;
        temp = temp->next;
    }
}

bool BrowserPageList::IsEmpty()
{
    return head == NULL;
}

bool BrowserPageList::IsNotEmpty()
{
    return head != NULL;
}

BrowserPageList::~BrowserPageList()
{
    while (head != NULL)
    {
        BrowserPageNode* temp = head;
        head = head->next;
        delete temp;
    }
}