#include "../include/BrowserStack.h"
#include <iostream>
using namespace std;

BrowserStack::BrowserStack()
{
    top = NULL;
}

void BrowserStack::Push(string url)
{
    BrowserNode* newNode = new BrowserNode(url);

    newNode->next = top;
    top = newNode;

    cout << "Page visited successfully!\n";
}

string BrowserStack::Pop()
{
    if (IsEmpty())
    {
        return "";
    }

    BrowserNode* temp = top;
    string page = temp->url;

    top = top->next;
    delete temp;

    return page;
}

string BrowserStack::Peek()
{
    if (IsEmpty())
    {
        return "";
    }

    return top->url;
}

bool BrowserStack::IsEmpty()
{
    return top == NULL;
}

bool BrowserStack::IsNotEmpty()
{
    return top != NULL;
}

void BrowserStack::Display()
{
    if (IsEmpty())
    {
        cout << "Browser history is empty!\n";
        return;
    }

    BrowserNode* temp = top;

    cout << "\nBrowser History (Most Recent First):\n";

    while (temp != NULL)
    {
        cout << temp->url << endl;
        temp = temp->next;
    }
}

void BrowserStack::GoBack()
{
    if (IsEmpty() || top->next == NULL)
    {
        cout << "No previous page available!\n";
        return;
    }

    string currentPage = Pop();

    cout << "Going back from: " << currentPage << endl;
    cout << "Previous page: " << Peek() << endl;
}

BrowserStack::~BrowserStack()
{
    while (IsNotEmpty())
    {
        Pop();
    }
}