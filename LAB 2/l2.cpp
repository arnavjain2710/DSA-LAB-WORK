#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL; // defining the global head

// A function to insert an element at the start of the LL
void insertAtStart(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

// A function to insert an element at any position of the LL
void insertAtPosition(int data, int position)
{
    if (position == 1)
    {
        insertAtStart(data);
        return;
    }

    Node *currentNode = head;
    int i = 1;
    while (i < position && currentNode != NULL)
    {
        currentNode = currentNode->next;
        i++;
    }

    if (currentNode == NULL)
    {
        cout << "Position " << position << " does not exist" << endl;
        return;
    }

    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = currentNode->next;
    currentNode->next = newNode;
}

// A function to print the LL
void printList()
{
    cout<<"The Linked List is:"<<endl;
    for (Node *currentNode = head; currentNode != NULL; currentNode = currentNode->next)
    {
        cout << currentNode->data << " ";
    }
    cout << endl;
}

//  A function to insert an element at the end of the LL
void insertAtEnd(int data)
{
    Node *currentNode = head;
    while (currentNode->next != NULL)
    {
        currentNode = currentNode->next;
    }

    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    currentNode->next = newNode;
}

// A function to delete an element at the start of the LL
void deleteAtStart()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    Node *temp = head;
    head = head->next;
    delete temp;
}


// A function to delete an element at any position of the LL
void deleteAtPosition(int position)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    if (position == 1)
    {
        deleteAtStart();
        return;
    }

    Node *currentNode = head;
    int i = 1;
    while (i < position && currentNode != NULL)
    {
        currentNode = currentNode->next;
        i++;
    }

    if (currentNode == NULL)
    {
        cout << "Position " << position << " does not exist" << endl;
        return;
    }

    Node *temp = currentNode->next;
    currentNode->next = temp->next;
    delete temp;
}

// A function to delete an element at the end of the LL
void deleteAtEnd()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    Node *currentNode = head;
    while (currentNode->next->next != NULL)
    {
        currentNode = currentNode->next;
    }

    Node *temp = currentNode->next;
    currentNode->next = NULL;
    delete temp;
}

int main()
{
    // Creating the LL using the insertAtStart function
    insertAtStart(10);
    printList();

    insertAtStart(20);
    printList();

    insertAtStart(20);
    printList();

    insertAtPosition(30, 2);
    printList();

    insertAtEnd(40);
    printList();

    // Deletinf the elements from the LL
    deleteAtStart();
    printList();

    deleteAtPosition(2);
    printList();

    deleteAtEnd();
    printList();

    return 0;
}
