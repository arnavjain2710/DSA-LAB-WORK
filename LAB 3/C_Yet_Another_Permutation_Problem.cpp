#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lli long long int
#define pb push_back
#define rep(var, start, num) for(ulli var = start; var <start + num; var++)
#define all(x) x.begin(), x.end()
#define ulli unsigned long long int
#define ull unsigned long long
// function to check if a given number is prime
bool isPrime(int n)
{
    // since 0 and 1 is not prime return false.
    if (n == 1 || n == 0)
        return false;
 
    // Run a loop from 2 to n-1
    for (int i = 2; i < n; i++) {
        // if the number is divisible by i, then n is not a
        // prime number.
        if (n % i == 0)
            return false;
    }
    // otherwise, n is prime number.
    return true;
}
void solve()
{
      lli n;
      cin>>n;
      lli t=n;
      lli a[n+1];
      for(lli i=0;i<=n;i++)
      {
        a[i] =i;
      }
      vector<lli> v;
      v.pb(2);
     for(lli i=1;;i++)
     {
        lli x=6*i-1;
        if(isPrime(x))
        {
            v.pb(x);
        }
        x=6*i+1;
        if(x>n)
        {
            break;
        }
        if(isPrime(x))
        {
            v.pb(x);
        }
     }
    cout<<"1 ";
    a[1]=0;
    for(lli i=0;i<v.size();i++)
    {
        lli x=v[i];
        while(x<=n)
        {
            cout<<x<<" ";
            a[x]=0;
            x*=2;
        }
    }
    for(lli i=1;i<=n;i++)
    {
        if(a[i]!=0)
        {
            cout<<i<<" ";
        }
    }
    cout<<endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        solve();
    }
}