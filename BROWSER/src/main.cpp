
#include <iostream>
#include <string>
#include "../include/BrowserStack.h"
#include "../include/BrowserQueue.h"
#include "../include/BrowserPriorityQueue.h"
#include "../include/BrowserPageList.h"
#include "../include/BrowserCircularList.h"
#include "../include/BrowserDoublyList.h"

using namespace std;

int main()
{
    BrowserStack browser;
    BrowserQueue requests;
    BrowserPriorityQueue tasks;
    BrowserPageList pages;
    BrowserCircularList circularPages;
    BrowserDoublyList doublyPages;

    int choice, priority;
    string url, task;

    do
    {
        cout << "\n===== BROWSER BACK BUTTON =====\n";

        cout << "\n--- LAB 2: STACK ---\n";
        cout << "1. Visit New Page\n";
        cout << "2. Go Back\n";
        cout << "3. Display Browser History\n";
        cout << "4. Check Stack IsEmpty\n";
        cout << "5. Check Stack IsNotEmpty\n";

        cout << "\n--- LAB 3: QUEUE ---\n";
        cout << "6. Add Browser Request\n";
        cout << "7. Process Browser Request\n";
        cout << "8. Display Pending Requests\n";
        cout << "9. Check Queue IsEmpty\n";
        cout << "10. Check Queue IsNotEmpty\n";

        cout << "\n--- LAB 4: PRIORITY QUEUE ---\n";
        cout << "11. Add Browser Task\n";
        cout << "12. Process Highest Priority Task\n";
        cout << "13. Display Priority Tasks\n";
        cout << "14. Check Priority Queue IsEmpty\n";
        cout << "15. Check Priority Queue IsNotEmpty\n";

        cout << "\n--- LAB 5: LINKED LIST ---\n";
        cout << "16. Add Browser Page\n";
        cout << "17. Delete Browser Page\n";
        cout << "18. Display Browser Pages\n";
        cout << "19. Check Linked List IsEmpty\n";
        cout << "20. Check Linked List IsNotEmpty\n";

        cout << "\n--- LAB 6: CIRCULAR LINKED LIST ---\n";
        cout << "21. Add Circular Browser Page\n";
        cout << "22. Delete Circular Browser Page\n";
        cout << "23. Display Circular Browser Pages\n";
        cout << "24. Move to Next Page\n";
        cout << "25. Check Circular List IsEmpty\n";
        cout << "26. Check Circular List IsNotEmpty\n";

        cout << "\n--- LAB 7: DOUBLY LINKED LIST ---\n";
        cout << "27. Add Browser Page\n";
        cout << "28. Delete Browser Page\n";
        cout << "29. Display Forward\n";
        cout << "30. Display Backward\n";
        cout << "31. Go Back to Previous Page\n";
        cout << "32. Go Forward to Next Page\n";
        cout << "33. Check Doubly List IsEmpty\n";
        cout << "34. Check Doubly List IsNotEmpty\n";

        cout << "\n35. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter website URL: ";
            cin >> url;
            browser.Push(url);
            break;

        case 2:
            browser.GoBack();
            break;

        case 3:
            browser.Display();
            break;

        case 4:
            cout << (browser.IsEmpty() ? "Stack is empty.\n" : "Stack is not empty.\n");
            break;

        case 5:
            cout << (browser.IsNotEmpty() ? "Stack contains pages.\n" : "Stack is empty.\n");
            break;

        case 6:
            cout << "Enter website URL: ";
            cin >> url;
            requests.Enqueue(url);
            break;

        case 7:
            if (requests.IsEmpty())
                cout << "No pending requests!\n";
            else
                cout << "Processing request: " << requests.Dequeue() << endl;
            break;

        case 8:
            requests.Display();
            break;

        case 9:
            cout << (requests.IsEmpty() ? "Queue is empty.\n" : "Queue is not empty.\n");
            break;

        case 10:
            cout << (requests.IsNotEmpty() ? "Queue contains requests.\n" : "Queue is empty.\n");
            break;

        case 11:
            cout << "Enter browser task: ";
            cin.ignore();
            getline(cin, task);

            cout << "Enter priority (1 = Highest, 2 = Medium, 3 = Low): ";
            cin >> priority;

            if (priority >= 1 && priority <= 3)
                tasks.Enqueue(task, priority);
            else
                cout << "Invalid priority!\n";
            break;

        case 12:
            if (tasks.IsEmpty())
                cout << "No browser tasks!\n";
            else
                cout << "Processing task: " << tasks.Dequeue() << endl;
            break;

        case 13:
            tasks.Display();
            break;

        case 14:
            cout << (tasks.IsEmpty() ? "Priority Queue is empty.\n" : "Priority Queue is not empty.\n");
            break;

        case 15:
            cout << (tasks.IsNotEmpty() ? "Priority Queue contains tasks.\n" : "Priority Queue is empty.\n");
            break;

        case 16:
            cout << "Enter website URL: ";
            cin >> url;
            pages.InsertPage(url);
            break;

        case 17:
            cout << "Enter URL to delete: ";
            cin >> url;
            pages.DeletePage(url);
            break;

        case 18:
            pages.Display();
            break;

        case 19:
            cout << (pages.IsEmpty() ? "Linked List is empty.\n" : "Linked List is not empty.\n");
            break;

        case 20:
            cout << (pages.IsNotEmpty() ? "Linked List contains pages.\n" : "Linked List is empty.\n");
            break;

        case 21:
            cout << "Enter website URL: ";
            cin >> url;
            circularPages.InsertPage(url);
            break;

        case 22:
            cout << "Enter URL to delete: ";
            cin >> url;
            circularPages.DeletePage(url);
            break;

        case 23:
            circularPages.Display();
            break;

        case 24:
            circularPages.MoveNext();
            break;

        case 25:
            cout << (circularPages.IsEmpty() ? "Circular List is empty.\n" : "Circular List is not empty.\n");
            break;

        case 26:
            cout << (circularPages.IsNotEmpty() ? "Circular List contains pages.\n" : "Circular List is empty.\n");
            break;

        case 27:
            cout << "Enter website URL: ";
            cin >> url;
            doublyPages.InsertPage(url);
            break;

        case 28:
            cout << "Enter URL to delete: ";
            cin >> url;
            doublyPages.DeletePage(url);
            break;

        case 29:
            doublyPages.DisplayForward();
            break;

        case 30:
            doublyPages.DisplayBackward();
            break;

        case 31:
            doublyPages.GoBack();
            break;

        case 32:
            doublyPages.GoForward();
            break;

        case 33:
            cout << (doublyPages.IsEmpty() ? "Doubly List is empty.\n" : "Doubly List is not empty.\n");
            break;

        case 34:
            cout << (doublyPages.IsNotEmpty() ? "Doubly List contains pages.\n" : "Doubly List is empty.\n");
            break;

        case 35:
            cout << "Exiting Browser Back Button...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 35);

    return 0;
}

