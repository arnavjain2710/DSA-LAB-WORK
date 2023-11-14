#include <iostream>
using namespace std;

const int MAX_SIZE = 5;

int queue[MAX_SIZE];
int front = -1, rear = -1;

bool isEmpty()
{
    return front == -1;
}

bool isFull()
{
    return rear == MAX_SIZE - 1;
}

void insert(int value)
{
    if (isFull())
    {
        cout << "Queue is full. Cannot insert." << endl;
        return;
    }
    if (isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }
    queue[rear] = value;
    cout << "Inserted " << value << " into the queue." << endl;
}

void remove()
{
    if (isEmpty())
    {
        cout << "Queue is empty. Cannot delete." << endl;
        return;
    }
    int removedValue = queue[front];
    front++;
    cout << "Deleted " << removedValue << " from the queue." << endl;
}

void display()
{
    if (isEmpty())
    {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Queue: ";
    for (int i = front; i <= rear; ++i)
    {
        cout << queue[i] << " ";
    }
    cout << endl;
}

int main()
{
    while (true)
    {
        cout << "\nQueue Operations:" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int value;
            cout << "Enter the value to insert: ";
            cin >> value;
            insert(value);
            break;
        }
        case 2:
            remove();
            break;
        case 3:
            display();
            break;
        case 4:
            cout << "Exiting the program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please choose again." << endl;
        }
    }

    return 0;
}
