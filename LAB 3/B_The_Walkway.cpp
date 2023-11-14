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
      lli n,m,d;
      cin>>n>>m>>d;
      lli s[m];
      lli counter=0;
      for(lli i=0;i<m;i++)
      {
        cin>>s[i];
        if((s[i]-1)%d==0)
        {
            counter++;
        }
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