#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL; // defining the global head
Node *tail=NULL;
int s=0;

// A function to insert an element at the start of the LL
void insertAtStart(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    tail=newNode;
}

// A function to print the LL
void print()
{
    if(s==0)
    {
        cout<<"Empty Stack"<<endl;
        return;
    }
    cout<<"The Linked List is:"<<endl;
    for (Node *currentNode = head->next; currentNode != NULL; currentNode = currentNode->next)
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
    tail = newNode;
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
    tail = currentNode;
    delete temp;
}

int main()
{
    // int s =0;
    insertAtStart(0);
    cout<<"Enter what you want to do"<<endl;
    cout<<"1 for printing the existing stack"<<endl;
    cout<<"2 for inserting elements in the stack"<<endl;
    cout<<"3 for deleting elements from the stack"<<endl;
    int quit;
    do
    {
    cout<<"Enter your choice"<<endl;
    int choice;
    cin>>choice;
    if(choice==1)
    {
        print();
    }
    else if(choice==2)
    {
        cout<<"Enter the amount of integers you want to enter "<<endl;
        int x;
        cin>>x;
        for(int i=0;i<x;i++)
        {
            s++;
            if(s>5)
            {
                s=5;
                cout<<"Stack Overflow"<<endl;
                break;
            }
            cout<<"Enter the number to be inserted"<<endl;
            int c;
            cin>>c;
            insertAtEnd(c);
        }
        print();
    }
    else if(choice ==3)
    {
        cout<<"Enter the amount of integers you want to delete "<<endl;
        int x;
        cin>>x;
        for(int i=0;i<x;i++)
        {
            s--;
            if(s<0)
            {
                s=0;
                cout<<"Stack underflow"<<endl;
                break;
            }
            deleteAtEnd();
        }
        print();
    }
    else
    {
        cout<<"Wrong choice"<<endl;
    }
    cout<<"Do you wanna quit?"<<endl;
    cout<<"1 for yes"<<endl;
    cout<<"2 for no"<<endl;
    cin>>quit;
    } while (quit!=1);
    cout<<"Thank You"<<endl;
    return 0;
}
