#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lli long long int
#define pb push_back
#define rep(var, start, num) for(ulli var = start; var <start + num; var++)
#define all(x) x.begin(), x.end()
#define ulli unsigned long long int
#define ull unsigned long long
void solve()
{
      lli a,b,c;
      cin>>a>>b>>c;
      if(c%2!=0)
      {
        b--;
      }
      if(a>b)
      {
        cout<<"First"<<endl;
      }
      else
      {
        cout<<"Second"<<endl;
      }
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