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

// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int array[], int const left, int const mid,
		int const right)
{
	int const subArrayOne = mid - left + 1;
	int const subArrayTwo = right - mid;

	// Create temp arrays
	auto *leftArray = new int[subArrayOne],
		*rightArray = new int[subArrayTwo];

	// Copy data to temp arrays leftArray[] and rightArray[]
	for (auto i = 0; i < subArrayOne; i++)
		leftArray[i] = array[left + i];
	for (auto j = 0; j < subArrayTwo; j++)
		rightArray[j] = array[mid + 1 + j];

	auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
	int indexOfMergedArray = left;

	// Merge the temp arrays back into array[left..right]
	while (indexOfSubArrayOne < subArrayOne
		&& indexOfSubArrayTwo < subArrayTwo) {
		if (leftArray[indexOfSubArrayOne]
			<= rightArray[indexOfSubArrayTwo]) {
			array[indexOfMergedArray]
				= leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			array[indexOfMergedArray]
				= rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}

	// Copy the remaining elements of
	// left[], if there are any
	while (indexOfSubArrayOne < subArrayOne) {
		array[indexOfMergedArray]
			= leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}

	// Copy the remaining elements of
	// right[], if there are any
	while (indexOfSubArrayTwo < subArrayTwo) {
		array[indexOfMergedArray]
			= rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
	delete[] leftArray;
	delete[] rightArray;
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(int array[], int const begin, int const end)
{
	if (begin >= end)
		return;

	int mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
}

// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size)
{
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";
	cout << endl;
}

// Driver code
int main()
{
    cout<<"MERGE SORT"<<endl;
    cout<<endl;
    int n=500 , m=pow(10,5);
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
    mergeSort(a, 0, n-1);
    end = get_wall_time();
    cout<<"For 500 entries it is: "<<end-start<<endl;
    start = get_wall_time();
    mergeSort(b, 0, m-1);
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
    mergeSort(a, 0, n - 1);
    end = get_wall_time();
    cout<<"For 500 entries it is: "<<end-start<<endl;
    start = get_wall_time();
    mergeSort(b, 0, m-1);
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
    mergeSort(a, 0, n-1);
    end = get_wall_time();
    cout<<"For 500 entries it is: "<<end-start<<endl;
    start = get_wall_time();
    mergeSort(b, 0, m-1);
    end = get_wall_time();
    cout<<"For 1 million enttries it is: "<<end-start<<endl;
	return 0;
}

// This code is contributed by Mayank Tyagi
// This code was revised by Joshua Estes
