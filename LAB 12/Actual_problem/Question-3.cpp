#include <bits/stdc++.h>
#include <time.h>
#include <sys/time.h>
using namespace std;
double get_wall_time()
{
    struct timeval time;
    if (gettimeofday(&time,NULL)){
        //  Handle error
        return 0;
    }
    return (double)time.tv_sec + (double)time.tv_usec * .000001;
}
int main()
{
    cout<<"INSERTION SORT"<<endl;
    cout<<endl;
    int n=500 , m=pow(10,6);
    int a[n],b[m];
    for(int i=0;i<n;i++)
    {
        a[i]=i;
    }
    for(int i=0;i<m;i++)
    {
        b[i]=i;
    }
    cout<<"For sorted inputs:"<<endl;
    double start ,end;
    start = get_wall_time();
    for(int i=1; i<n; ++i) {
        int key = a[i];
        int j = i-1;
        while(j>=0 && a[j] > key) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
    end = get_wall_time();
    cout<<"For 500 entries it is: "<<end-start<<endl;
    start = get_wall_time();
    for(int i=1; i<m; ++i) {
        int key = b[i];
        int j = i-1;
        while(j>=0 && b[j] > key) {
            b[j+1] = b[j];
            j--;
        }
        b[j+1] = key;
    }
    end = get_wall_time();
    cout<<"For 1 million enttries it is: "<<end-start<<endl;
    
    cout<<endl;
    cout<<"For reversed sorted inputs:"<<endl;
    for(int i=0;i<n;i++)
    {
        a[i]=n-i;
    }
    for(int i=0;i<m;i++)
    {
        b[i]=m-i;
    }
    // double start ,end;
    start = get_wall_time();
    for(int i=1; i<n; ++i) {
        int key = a[i];
        int j = i-1;
        while(j>=0 && a[j] > key) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
    end = get_wall_time();
    cout<<"For 500 entries it is: "<<end-start<<endl;
    start = get_wall_time();
    for(int i=1; i<m; ++i) {
        int key = b[i];
        int j = i-1;
        while(j>=0 && b[j] > key) {
            b[j+1] = b[j];
            j--;
        }
        b[j+1] = key;
    }
    end = get_wall_time();
    cout<<"For 1 million enttries it is: "<<end-start<<endl;

    cout<<endl;
    cout<<"For randomised inputs inputs:"<<endl;
    for(int i=0;i<n;i++)
    {
        a[i]=rand();
    }
    for(int i=0;i<m;i++)
    {
        b[i]=rand();
    }
    start = get_wall_time();
    for(int i=1; i<n; ++i) {
        int key = a[i];
        int j = i-1;
        while(j>=0 && a[j] > key) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
    end = get_wall_time();
    cout<<"For 500 entries it is: "<<end-start<<endl;
    start = get_wall_time();
    for(int i=1; i<m; ++i) {
        int key = b[i];
        int j = i-1;
        while(j>=0 && b[j] > key) {
            b[j+1] = b[j];
            j--;
        }
        b[j+1] = key;
    }
    end = get_wall_time();
    cout<<"For 1 million enttries it is: "<<end-start<<endl;

    return 0;
}