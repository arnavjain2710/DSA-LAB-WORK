// C++ code to convert infix expression to postfix

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    Node *next;
};

Node *head = NULL; // defining the global head
Node *tail=NULL;
int s=0;
char access_top()
{
    return tail->data;
}
// A function to insert an element at the start of the LL
void insertAtStart(char data)
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
void insertAtEnd(char data)
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

// Function to return precedence of operators
int prec(char c)
{
	if (c == '^')
		return 3;
	else if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}

// The main function to convert infix expression
// to postfix expression
void infixToPostfix(string s)
{

	
	string result;
    int n=0;
    insertAtStart('a');
	for (int i = 0; i < s.length(); i++) {
		char c = s[i];

		// If the scanned character is
		// an operand, add it to output string.
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
			|| (c >= '0' && c <= '9'))
			result += c;

		// If the scanned character is an
		// ‘(‘, push it to the stack.
		else if (c == '(')
        {
			insertAtEnd('(');
            n++;
        }

		// If the scanned character is an ‘)’,
		// pop and add to output string from the stack
		// until an ‘(‘ is encountered.
		else if (c == ')') {
			while (access_top() != '(') {
				result += access_top();
				deleteAtEnd();
                n--;
			}
			deleteAtEnd();
            n--;
		}

		// If an operator is scanned
		else {
			while (n!=0
				&& prec(s[i]) <= prec(access_top())) {
				result += access_top();
				deleteAtEnd();
                n--;
			}
			insertAtEnd(c);
            n++;
		}
	}

	// Pop all the remaining elements from the stack
	while (n!=0) {
		result += access_top();
		deleteAtEnd();
        n--;
	}

	cout << result << endl;
}

// Driver code
int main()
{
	string exp = "a+(b*c)+d";

	// Function call
	infixToPostfix(exp);
	
	return 0;
}
