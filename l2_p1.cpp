#include <bits/stdc++.h>
using namespace std;
struct node
{
    int x;
    node* next;
};
int main() {
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

    // inserting at the start
    node b;
    b.x=6;
    b.next = &a[1];
    a[0].next = &b;

    // at the end of the list
    node c;
    c.x=7;
    c.next=NULL;
    a[4].next = &c;

    // at any position
    cout<<"Enter the position"<<endl;
    int n;
    cin>>n;
    node d;
    d.x= 8;
    node e = a[0];
    int c1=0;
    while(c1<=n-1)
    {
        e = *(e.next);
        // cout<<e.x<<endl;
        c1++;
    }
    d.next=&a[n];
    a[n-1].next = &d;
 
    cout<<"The Linked List is:"<<endl;
     e = a[0];
    while(e.next != NULL)
    {
        e = *(e.next);
        cout<<e.x<<endl;
    }
   
   return 0;
}