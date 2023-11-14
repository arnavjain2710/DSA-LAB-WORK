// Question 2
#include<iostream>
using namespace std;
int main()
{
    int positive[10000]={0};
    int negative[10000]={0};
    cout<<"Enter the lenght of the array"<<endl;
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter the elements of the array"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>=0)
        {
            positive[a[i]]++;
        }
        else
        {
            negative[abs(a[i])]++;
        }
    }
    cout<<"Enter the sum to be searched"<<endl;
    int sum;
    cin>>sum;
    for(int i=0;i<n;i++)
    {
        int x = sum-a[i];
        if(x>=0)
        {
            if(x==a[i])
            {
                if(positive[x]==2)
                {
                    // cout<<a[i]<<endl;
                    cout<<"YES"<<endl;
                    return 0;
                }
            }
            else if(positive[x]==1)
            {
                // cout<<a[i]<<endl;
                cout<<"YES"<<endl;
                return 0;
            }
        }
        else 
        {
            if(x==a[i])
            {
                if(negative[abs(x)]==2)
                {
                    // cout<<a[i]<<endl;
                    cout<<"YES"<<endl;
                    return 0;
                }
            }
            else if(negative[abs(x)]==1)
            {
                // cout<<a[i]<<endl;
                cout<<"YES"<<endl;
                return 0;
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}