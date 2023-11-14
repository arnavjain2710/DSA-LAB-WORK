#include<bits/stdc++.h>
using namespace std;
#include <time.h>
#include <sys/time.h>
double get_wall_time(){
    struct timeval time;
    if (gettimeofday(&time,NULL)){
        //  Handle error
        return 0;
    }
    return (double)time.tv_sec + (double)time.tv_usec * .000001;
}
void insertarray()
{
	double wall0 = get_wall_time();
	int n;
	cout<<"Enter the length of the array"<<endl;
	cin>>n;
	int a[n+1];
	cout<<"Enter the elements of the array"<<endl;
	for(int i=0;i<n;i++)
	{
	    cin>>a[i];
	}
	cout<<"Enter the element to be inserted"<<endl;
	int insert;
	cin>>insert;
	a[n] = insert;
	cout<<"The new array is :"<<endl;
	for(int i=0;i<n+1;i++)
	{
	  cout<<a[i]<<" ";
	}
	 cout<<endl;
	double wall1 = get_wall_time();
	cout << "Wall Time = " << wall1 - wall0 << endl;
}
void deletearray()
{
    int n;
	double wall0 = get_wall_time();
	cout<<"Enter the length of the array"<<endl;
	cin>>n;
	int a[n];
	cout<<"Enter the elements of the array"<<endl;
	for(int i=0;i<n;i++)
	{
	cin>>a[i];
	}
	int b[n-1];
	cout<<"The array after deletion is:"<<endl;
	for(int i=0;i<n-1;i++)
	{
	  b[i]=a[i];
	  cout<<b[i]<<" ";
	}
	cout<<endl;
	double wall1 = get_wall_time();
	cout << "Wall Time = " << wall1 - wall0 << endl;
	
}
int main()
{
insertarray();
deletearray();
return 0;
}
