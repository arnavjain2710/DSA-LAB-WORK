#include <bits/stdc++.h>
#include <time.h>
#include <sys/time.h>
using namespace std;
double get_wall_time()
{
    struct timeval time;
    if (gettimeofday(&time,NULL)){
        return 0;
    }
    return (double)time.tv_sec + (double)time.tv_usec * .000001;
}

int partition(int arr[], int start, int end)
{
 
    int pivot = arr[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}
 
void quickSort(int arr[], int start, int end)
{
 
    // base case
    if (start >= end)
        return;
 
    // partitioning the array
    int p = partition(arr, start, end);
 
    // Sorting the left part
    quickSort(arr, start, p - 1);
 
    // Sorting the right part
    quickSort(arr, p + 1, end);
}
int main() 
{ 
    // since the code is unable to run on 10^5 , im running it on 10^4
	cout<<"QUICK SORT"<<endl;
    cout<<endl;
    int n=500 , m=pow(10,4);
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
    quickSort(a, 0, n-1);
    end = get_wall_time();
    cout<<"For 500 entries it is: "<<end-start<<endl;
    start = get_wall_time();
    quickSort(b, 0, m-1);
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
    start = get_wall_time();
    quickSort(a, 0, n - 1);
    end = get_wall_time();
    cout<<"For 500 entries it is: "<<end-start<<endl;
    start = get_wall_time();
    quickSort(b, 0, m-1);
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
    quickSort(a, 0, n-1);
    end = get_wall_time();
    cout<<"For 500 entries it is: "<<end-start<<endl;
    start = get_wall_time();
    quickSort(b, 0, m-1);
    end = get_wall_time();
    cout<<"For 1 million enttries it is: "<<end-start<<endl;
	return 0;
}
