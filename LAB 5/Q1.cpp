// Question 1
#include<iostream>
using namespace std;

bool check(int a[] , int n , int x)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==x)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int table[256] = {0};
    string a,b;
    cout<<"Enter the first string: "<<endl;
    cin>>a;
    cout<<"Enter the second string: "<<endl;
    cin>>b;
    int l = a.length();
    for(int i=0;i<l;i++)
    {
        char x = a[i];
        if(table[(int)x - (int)' ']== 0)
        {
            if(!check(table , 256 , (int)b[i] - (int)' '))
            {
                table[(int)x - (int)' '] = (int)b[i] - (int)' ';
            }
            else
            {
                cout<<"Not isomorphic"<<endl;
                return 0;
            }
        }
        else if (table[(int)x - (int)' '] != (int)b[i] - (int)' ')
        {
            cout<<"Not isomorphic"<<endl;
            return 0;
        }
    }
    cout<<"Isomorphic"<<endl;
    return 0;
}