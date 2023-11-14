// Question 3
#include<iostream>
using namespace std;
int main()
{
    int table1[256]={0};
    int table2[256]={0};
    cout<<"Enter the two strings"<<endl;
    string a,b;
    cin>>a>>b;
    int l=a.length();
    for(int i=0;i<l;i++)
    {
        table1[a[i]-' ']++;
        table2[b[i]-' ']++;
    }
    for(int i=0;i<256;i++)
    {
        if(table1[i]!=table2[i])
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}