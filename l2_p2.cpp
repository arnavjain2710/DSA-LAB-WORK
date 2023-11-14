#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x;
    node* next;
};
int main()
{
    // initiallising the linked list
    node a[5];
    a[0].x=0; 
    a[0].next = &a[1];
    for(int i=1;i<=3;i++)
    {
        a[i].x=i;
        a[i].next = &a[i+1];
    }
    a[4].x=4;
    a[4].next = NULL;
     cout<<"The Linked List is:"<<endl;
    node e = a[0];
    while(e.next != NULL)
    {
        e = *(e.next);
        cout<<e.x<<endl;
    }
    cout<<endl;

    // deleting at the start
    a[0].next = &a[2];
     cout<<"The Linked List is:"<<endl;
    e = a[0];
    while(e.next != NULL)
    {
        e = *(e.next);
        cout<<e.x<<endl;
    }
    cout<<endl;

    // deleting at the end
    a[3].next = a[4].next;
     cout<<"The Linked List is:"<<endl;
    e = a[0];
    while(e.next != NULL)
    {
        e = *(e.next);
        cout<<e.x<<endl;
    }
    cout<<endl;

    // deleting at any position
    cout<<"Enter the position"<<endl;
    int n;
    cin>>n;
    n++;
    // a[n-1].next = a[n].next;
    e = a[0];
    int c=0;
    while(c<=n-2)
    {
        e = *(e.next);
        // cout<<e.x<<endl;
        c++;
    }
    cout<<e.x<<" test"<<endl;
    node f =*(e.next);
    node g = *(f.next);
    // &(e.next).next = f.next;

    // cout<<c<<endl;
    cout<<"The Linked List is:"<<endl;
    e = a[0];
    while(e.next != NULL)
    {
        e = *(e.next);
        cout<<e.x<<endl;
    }

    return 0;
}