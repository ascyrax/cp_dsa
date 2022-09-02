// @author: ascyrax
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl "\n"
#define ioss                   \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define int long long
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front

double startTime;

double gct() // get_current_time
{
  return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}

void suraj();

signed main()
{

  ioss

      // startTime=(double)clock();

      // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);

      // cout << setprecision(15) << fixed;

      int t = 1;

  // cin >> t;

  for (int i = 1; i <= t; i++)
  {

    // cout<<"Case #"<<i<<": ";

    suraj();
  }

  return 0;
}

int inf = 1e18;
//.....................................

//.....................................

//.....................................

//.....................................

void suraj()
{
  int n, m;
  cin >> n >> m;

  vector<int> v(n);
  for (int &i : v)
    cin >> i;

  int ans = n + (n * (n - 1)) / 2;

  for (int i = 0; i <= n - 2; i++)
  {
    if (v[i] != v[i + 1])
    {
      ans += (i + 1) * (n - 1 - i + 1);
    }
  }

  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    a--;


    if(n==1){

    }else if (a > 0 && a < n - 1)
    {
      if(v[a-1]!=v[a]){ans+= }
    }else if(a==0){

    }else if(a==n-1){

    }
  }
}
