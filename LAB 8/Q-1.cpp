#include <bits/stdc++.h>
using namespace std;
void heapify(vector<int>& a ,  int index)
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
        heapify(a,index);
    }
}
void BuildMinHeap(vector<int>& a)
{
    int n= a.size();
    for(int i=n/2 + n%2;i>=0;i--)
    {
        heapify(a,i);
    }
}
int main()
{
    // int a[7]={41,41,51,100,16,31,13};
    vector<int> a;
    a.push_back(41);
    a.push_back(41);
    a.push_back(51);
    a.push_back(100);
    a.push_back(16);
    a.push_back(31);
    a.push_back(13);
    cout<<"Before BuildMinHeap"<<endl;
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
    return 0;
}