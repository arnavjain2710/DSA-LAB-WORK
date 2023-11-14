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
int main()
{
	double wall0 = get_wall_time();
	int n;
	cout<<"Enter the length if the array"<<endl;
	cin>>n;
	cout<<"Enter the elemnts of the array"<<endl;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"Enter the number to be searched"<<endl;
	int search;
	cin>>search;
	int flag =0;
	for(int i=0;i<n;i++)
	{
		if(a[i] == search)
		{
			cout<<"Element fouond! at index "<<i+1<<endl;
			flag =1;
		}
	}
	if(flag ==0)
	{
	cout<<"Element not found"<<endl;
	}
	double wall1 = get_wall_time();
	cout << "Wall Time = " << wall1 - wall0 << endl;
return 0;
}

