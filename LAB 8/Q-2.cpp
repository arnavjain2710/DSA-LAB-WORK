#include <bits/stdc++.h>
using namespace std;
void heapifyMin(vector<int>& a ,  int index)
{
    int n= a.size();
    int temp = index;
    int left_child = 2*index + 1;
    int right_child = 2*index + 2;
    if(left_child <n &&a[left_child]< a[index])
    {
        index=left_child;
    }
    if(right_child<n && a[right_child]<a[index])
    {
        index = right_child;
    }
    if(index!= temp)
    {
        swap(a[index] , a[temp]);
        heapifyMin(a,index);
    }
}
void BuildMinHeap(vector<int>& a)
{
    int n= a.size();
    for(int i=n/2 + n%2;i>=0;i--)
    {
        heapifyMin(a,i);
    }
}

void heapifyMax(vector<int>& a ,  int index)
{
    int n= a.size();
    int temp = index;
    int left_child = 2*index + 1;
    int right_child = 2*index + 2;
    if(left_child <n &&a[left_child]>a[index])
    {
        index=left_child;
    }
    if(right_child<n && a[right_child]>a[index])
    {
        index = right_child;
    }
    if(index!= temp)
    {
        swap(a[index] , a[temp]);
        heapifyMax(a,index);
    }
}
void BuildMaxHeap(vector<int>& a)
{
    int n= a.size();
    for(int i=n/2 + n%2;i>=0;i--)
    {
        heapifyMax(a,i);
    }
}
int main()
{
    vector<int> a;
    a.push_back(41);
    a.push_back(41);
    a.push_back(51);
    a.push_back(100);
    a.push_back(16);
    a.push_back(31);
    a.push_back(13);
    cout<<"Before BuilHeapMin"<<endl;
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<endl;
    BuildMinHeap(a);
    cout<<"After BuildMinHeap"<<endl;
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<endl;
    cout<<"After BuildMaxHeap"<<endl;
    BuildMaxHeap(a);
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    return 0;
}