#include <bits/stdc++.h>
using namespace std;
int n = 500;

int part(int *a, int low, int high)
{
    int pi = a[high];
    int i = (low - 1);
    for (int j = low; j <= high; j++)
    {
        if (a[j] < pi)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return (i + 1);
}

void quick_sort(int *a, int start, int end)
{
    if (end < start)
        return;
    int pi = part(a, start, end);
    quick_sort(a, start, pi - 1);
    quick_sort(a, pi + 1, end);
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
        quick_sort(a, 0, n - 1);
        clock_t end = clock();
        string duration = to_string((float)(end - init) / CLOCKS_PER_SEC);
        v.push_back(duration);
    }
    for(auto i : v) cout<<i<<", ";
    cout<<endl;
    return 0;
}
