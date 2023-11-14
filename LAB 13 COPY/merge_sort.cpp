#include <bits/stdc++.h>
using namespace std;
const int n = 100000;


void merge(int* a, int left, int mid, int right)
{
    int s1 = mid - left + 1;
    int s2 = right - mid;
 
    auto *la = new int[s1],
         *ra = new int[s2];

    for (auto i = 0; i < s1; i++)
        la[i] = a[left + i];
    for (auto j = 0; j < s2; j++)
        ra[j] = a[mid + 1 + j];
 
    auto is1 = 0, is2 = 0;
    int ima = left;
 
    while (is1 < s1
           && is2 < s2) {
        if (la[is1]
            <= ra[is2]) {
            a[ima]
                = la[is1];
            is1++;
        }
        else {
            a[ima]
                = ra[is2];
            is2++;
        }
        ima++;
    }
 
    while (is1 < s1) {
        a[ima]
            = la[is1];
        is1++;
        ima++;
    }
 
    // Copy the remaining elements of
    // right[], if there are any
    while (is2 < s2) {
        a[ima]
            = ra[is2];
        is2++;
        ima++;
    }
    delete[] la;
    delete[] ra;
}
 
void merge_sort(int* a, int begin, int end)
{
    if (begin >= end)
        return;
 
    int mid = begin + (end - begin) / 2;
    merge_sort(a, begin, mid);
    merge_sort(a, mid + 1, end);
    merge(a, begin, mid, end);
}

int main()
{
    vector<string> v;
    for(int n=5000; n<100001; n+=5000)
    {
        int a[n];
        for (int i = 0; i < n; ++i)
            a[i] = i + 1;

        random_shuffle(a, a + n);
        clock_t init = clock();
        merge_sort(a, 0, n - 1);
        clock_t end = clock();
        string duration = to_string((float)(end - init) / CLOCKS_PER_SEC);
        v.push_back(duration);
    }
    for(auto i : v) cout<<i<<" ,";
    cout<<endl;
    return 0;
}