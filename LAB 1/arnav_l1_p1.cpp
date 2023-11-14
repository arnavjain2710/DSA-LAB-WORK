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
	int a[(int)pow(10,2)];
	int b[(int)pow(10,3)];
	for(int i=0;i<pow(10,2);i++)
	{
		a[i] = rand();
	}
	for(int i=0;i<pow(10,3);i++)
	{
		b[i] = rand();
	}
	double wall1 = get_wall_time();
	cout << "Wall Time = " << wall1 - wall0 << endl;
	return 0;
}

