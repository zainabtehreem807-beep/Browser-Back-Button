#include <iostream>
#include <string>
#include "../include/Stack.h"
#include "../include/Queue.h"
#include "../include/BookRequestNode.h"
#include "../include/PriorityQueue.h"
#include "../include/PriorityRequestNode.h"
#include "../include/BookList.h"
#include "../include/CircularBookList.h"
#include "../include/BorrowingSession.h"

using namespace std;

// LAB 2: QUEUE SYSTEM
void runQueueSystem()
{
    Queue requests;
    int choice, studentID, bookID;
    string studentName, bookTitle;

    do
    {
        cout << "\n===== BOOK REQUEST QUEUE SYSTEM =====\n";
        cout << "1. Add Book Request\n";
        cout << "2. Serve Next Request\n";
        cout << "3. Display All Requests\n";
        cout << "4. Check if Queue is Empty\n";
        cout << "5. Check if Queue is Not Empty\n";
        cout << "6. Back to Main Menu\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter Student ID: ";
            cin >> studentID;

            cin.ignore();
            cout << "Enter Student Name: ";
            getline(cin, studentName);

            cout << "Enter Book ID: ";
            cin >> bookID;

            cin.ignore();
            cout << "Enter Book Title: ";
            getline(cin, bookTitle);

            BookRequestNode* newNode =
                new BookRequestNode(studentID, studentName, bookID, bookTitle);

            requests.EnQueue(newNode);
            break;
        }

        case 2:
        {
            BookRequestNode* served = requests.DeQueue();

            if (served != nullptr)
            {
                cout << "\nServed Request:\n";
                cout << "Student ID: " << served->studentID << endl;
                cout << "Student Name: " << served->studentName << endl;
                cout << "Book ID: " << served->bookID << endl;
                cout << "Book Title: " << served->bookTitle << endl;

                delete served;
            }
            break;
        }

        case 3:
            requests.Display();
            break;

        case 4:
            cout << (requests.IsEmpty() ? "Queue is Empty.\n" : "Queue is Not Empty.\n");
            break;

        case 5:
            cout << (requests.IsNotEmpty() ? "Queue is Not Empty.\n" : "Queue is Empty.\n");
            break;

        case 6:
            cout << "Returning to Main Menu...\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 6);
}

// LAB 3: PRIORITY QUEUE SYSTEM
void runPriorityQueueSystem()
{
    PriorityQueue requests;
    int choice, studentID, bookID, priority;
    string studentName, bookTitle;

    do
    {
        cout << "\n===== URGENT BOOK REQUEST MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Book Request\n";
        cout << "2. Process Highest Priority Request\n";
        cout << "3. Display All Requests\n";
        cout << "4. Check Queue Status\n";
        cout << "5. Back to Main Menu\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter Student ID: ";
            cin >> studentID;

            cin.ignore();
            cout << "Enter Student Name: ";
            getline(cin, studentName);

            cout << "Enter Book ID: ";
            cin >> bookID;

            cin.ignore();
            cout << "Enter Book Title: ";
            getline(cin, bookTitle);

            cout << "Enter Priority (higher number = higher priority): ";
            cin >> priority;

            PriorityRequestNode* newNode =
                new PriorityRequestNode(studentID, studentName,
                                        bookID, bookTitle, priority);

            requests.EnQueue(newNode);
            break;
        }

        case 2:
        {
            PriorityRequestNode* served = requests.DeQueue();

            if (served != nullptr)
            {
                cout << "\nProcessed Highest Priority Request:\n";
                cout << "Student ID: " << served->studentID << endl;
                cout << "Student Name: " << served->studentName << endl;
                cout << "Book ID: " << served->bookID << endl;
                cout << "Book Title: " << served->bookTitle << endl;
                cout << "Priority: " << served->priority << endl;

                delete served;
            }
            break;
        }

        case 3:
            requests.Display();
            break;

        case 4:
            if (requests.IsEmpty())
                cout << "Priority Queue is Empty.\n";
            else
                cout << "Priority Queue is Not Empty.\n";
            break;

        case 5:
            cout << "Returning to Main Menu...\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 5);
}

// LAB 4: LIBRARY BOOK COLLECTION SYSTEM
void runBookCollectionSystem()
{
    BookList books;
    int choice, id, index, index1, index2;
    string title;

    do
    {
        cout << "\n========================================\n";
        cout << "       LIBRARY BOOK COLLECTION SYSTEM\n";
        cout << "========================================\n";
        cout << "1. Display All Books\n";
        cout << "2. Insert Book at Head\n";
        cout << "3. Remove Book from Head\n";
        cout << "4. Insert Book at Index\n";
        cout << "5. Remove Book at Index\n";
        cout << "6. Swap Books\n";
        cout << "7. Sort Books by ID\n";
        cout << "8. Reverse Book Collection\n";
        cout << "9. Check Collection Status\n";
        cout << "10. Exit to Main Menu\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            books.DisplayAllBooks();
            break;

        case 2:
            cout << "Enter Book ID: ";
            cin >> id;
            cin.ignore();

            cout << "Enter Book Title: ";
            getline(cin, title);

            books.InsertAtHead(id, title);
            break;

        case 3:
            books.RemoveFromHead();
            break;

        case 4:
            cout << "Enter Index (starting from 0): ";
            cin >> index;

            cout << "Enter Book ID: ";
            cin >> id;
            cin.ignore();

            cout << "Enter Book Title: ";
            getline(cin, title);

            books.InsertAtIndex(index, id, title);
            break;

        case 5:
            cout << "Enter Index to Remove (starting from 0): ";
            cin >> index;

            books.RemoveAtIndex(index);
            break;

        case 6:
            cout << "Enter First Index: ";
            cin >> index1;

            cout << "Enter Second Index: ";
            cin >> index2;

            books.SwapBooks(index1, index2);
            break;

        case 7:
            books.SortBooksByID();
            break;

        case 8:
            books.ReverseBookCollection();
            break;

        case 9:
            if (books.IsEmpty())
                cout << "Book Collection is Empty.\n";
            else
                cout << "Book Collection is Not Empty.\n";
            break;

        case 10:
            cout << "Returning to Main Menu...\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 10);
}

// LAB 5: CIRCULAR LINKED LIST SYSTEM
void runCircularBookCollectionSystem()
{
    CircularBookList books;
    int choice, id, index, index1, index2;
    string title;

    do
    {
        cout << "\n========================================\n";
        cout << "   CIRCULAR LIBRARY BOOK COLLECTION\n";
        cout << "========================================\n";
        cout << "1. Display All Books\n";
        cout << "2. Insert Book at Head\n";
        cout << "3. Remove Book from Head\n";
        cout << "4. Insert Book at Index\n";
        cout << "5. Remove Book at Index\n";
        cout << "6. Swap Books\n";
        cout << "7. Sort Books by ID\n";
        cout << "8. Reverse Book Collection\n";
        cout << "9. Move to Next Book\n";
        cout << "10. Check Collection Status\n";
        cout << "11. Exit to Main Menu\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            books.DisplayAllBooks();
            break;

        case 2:
            cout << "Enter Book ID: ";
            cin >> id;
            cin.ignore();

            cout << "Enter Book Title: ";
            getline(cin, title);

            books.InsertAtHead(id, title);
            break;

        case 3:
            books.RemoveFromHead();
            break;

        case 4:
            cout << "Enter Index (starting from 0): ";
            cin >> index;

            cout << "Enter Book ID: ";
            cin >> id;
            cin.ignore();

            cout << "Enter Book Title: ";
            getline(cin, title);

            books.InsertAtIndex(index, id, title);
            break;

        case 5:
            cout << "Enter Index to Remove (starting from 0): ";
            cin >> index;

            books.RemoveAtIndex(index);
            break;

        case 6:
            cout << "Enter First Index: ";
            cin >> index1;

            cout << "Enter Second Index: ";
            cin >> index2;

            books.SwapBooks(index1, index2);
            break;

        case 7:
            books.SortBooksByID();
            break;

        case 8:
            books.ReverseBookCollection();
            break;

        case 9:
            books.MoveToNextBook();
            break;

        case 10:
            if (books.IsEmpty())
                cout << "Book Collection is Empty.\n";
            else
                cout << "Book Collection is Not Empty.\n";
            break;

        case 11:
            cout << "Returning to Main Menu...\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 11);
}

// LAB 6: STUDENT BORROWING SESSION SYSTEM
void runBorrowingSessionSystem()
{
    BorrowingSession session;

    int choice, id;
    string title;

    do
    {
        cout << "\n========================================\n";
        cout << "       STUDENT BORROWING SESSION\n";
        cout << "========================================\n";
        cout << "1. Display Current Book\n";
        cout << "2. Move to Next Book\n";
        cout << "3. Move to Previous Book\n";
        cout << "4. Insert Book at the End\n";
        cout << "5. Insert Book After Current Book\n";
        cout << "6. Remove Current Book\n";
        cout << "7. Display Session from First to Last\n";
        cout << "8. Display Session from Last to First\n";
        cout << "9. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            session.DisplayCurrentBook();
            break;

        case 2:
            session.MoveToNextBook();
            break;

        case 3:
            session.MoveToPreviousBook();
            break;

        case 4:
            cout << "Enter Book ID: ";
            cin >> id;
            cin.ignore();

            cout << "Enter Book Title: ";
            getline(cin, title);

            session.InsertBookAtEnd(id, title);
            break;

        case 5:
            cout << "Enter Book ID: ";
            cin >> id;
            cin.ignore();

            cout << "Enter Book Title: ";
            getline(cin, title);

            session.InsertBookAfterCurrent(id, title);
            break;

        case 6:
            session.RemoveCurrentBook();
            break;

        case 7:
            session.DisplaySessionForward();
            break;

        case 8:
            session.DisplaySessionBackward();
            break;

        case 9:
            cout << "Exiting Borrowing Session...\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 9);
}

// MAIN MENU: LAB 1 TO LAB 6
int main()
{
    Stack books;
    int choice, stackChoice;
    string name;

    do
    {
        cout << "\n========== LIBRARY MANAGEMENT SYSTEM ==========\n";
        cout << "1. Lab 1 - Returned Book Stack System\n";
        cout << "2. Lab 2 - Book Request Queue System\n";
        cout << "3. Lab 3 - Urgent Book Priority Queue System\n";
        cout << "4. Lab 4 - Library Book Collection System\n";
        cout << "5. Lab 5 - Circular Linked List System\n";
        cout << "6. Lab 6 - Student Borrowing Session System\n";
        cout << "7. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        // LAB 1
        case 1:
        {
            do
            {
                cout << "\n===== RETURNED BOOK STACK SYSTEM =====\n";
                cout << "1. Push Book\n";
                cout << "2. Pop Book\n";
                cout << "3. Get Top Book\n";
                cout << "4. Display All Books\n";
                cout << "5. Check if Stack is Empty\n";
                cout << "6. Check if Stack is Not Empty\n";
                cout << "7. Demonstrate Copy Constructor\n";
                cout << "8. Demonstrate Assignment Operator\n";
                cout << "9. Back to Main Menu\n";

                cout << "\nEnter your choice: ";
                cin >> stackChoice;

                switch (stackChoice)
                {
                case 1:
                    cout << "Enter Book Name: ";
                    cin.ignore();
                    getline(cin, name);
                    books.Push(name);
                    break;

                case 2:
                    books.Pop();
                    break;

                case 3:
                    if (books.IsEmpty())
                        cout << "Stack is Empty!\n";
                    else
                        cout << "Top Book: " << books.GetTopValue() << endl;
                    break;

                case 4:
                    books.PrintStack();
                    break;

                case 5:
                    if (books.IsEmpty())
                        cout << "Stack is Empty.\n";
                    else
                        cout << "Stack is Not Empty.\n";
                    break;

                case 6:
                    if (books.IsNotEmpty())
                        cout << "Stack is Not Empty.\n";
                    else
                        cout << "Stack is Empty.\n";
                    break;

                case 7:
                {
                    Stack copiedBooks(books);
                    cout << "\nCopied Stack:\n";
                    copiedBooks.PrintStack();
                    break;
                }

                case 8:
                {
                    Stack assignedBooks;
                    assignedBooks = books;
                    cout << "\nAssigned Stack:\n";
                    assignedBooks.PrintStack();
                    break;
                }

                case 9:
                    cout << "Returning to Main Menu...\n";
                    break;

                default:
                    cout << "Invalid Choice!\n";
                }

            } while (stackChoice != 9);

            break;
        }

        // LAB 2
        case 2:
            runQueueSystem();
            break;

        // LAB 3
        case 3:
            runPriorityQueueSystem();
            break;

        // LAB 4
        case 4:
            runBookCollectionSystem();
            break;

        // LAB 5
        case 5:
            runCircularBookCollectionSystem();
            break;

        // LAB 6
        case 6:
            runBorrowingSessionSystem();
            break;

        case 7:
            cout << "Program Exited!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 7);

    return 0;
}
