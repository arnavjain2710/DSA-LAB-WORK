#include<bits/stdc++.h>
using namespace std;

// creating a stack of integers using arrays
int size1=5;
int a[5];
int* top = &a[0];
int c = 0;

void print()
{
    if(c==0)
    {
        cout<<"Empty Stack"<<endl;
        return;
    }
    for(int* i=&a[0];i<top;i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
}
void insert_stack(int n)
{
    for(int i=0;i<n;i++)
    {
        c++;
        if(c>size1)
        {
            c=100;
            cout<<"Stack overlfow"<<endl;
            break;
        }
        cout<<"Enter the number"<<endl;
        int x;
        cin>>x;
        *top = x;
        top++;
    }
    print();
}
void delete_stack(int n)
{
    for(int i=0;i<n;i++)
    {
        c--;
        if(c<0)
        {
            c=0;
            cout<<"Stack underflow"<<endl;
            break;
        }
        top--;
    }
    print();
}
int main()
{
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
        insert_stack(x);
    }
    else if(choice ==3)
    {
        cout<<"Enter the amount of integers you want to delete "<<endl;
        int x;
        cin>>x;
        delete_stack(x);
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
