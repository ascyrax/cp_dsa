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
  int n, q;
  cin >> n >> q;

  int sum = 0;

  map<int, int> mp;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
    mp[i] = v[i];
    sum += v[i];
  }

  int prev = 0;
  for (int i = 0; i < q; i++)
  {
    int diff = 0;
    int a;
    cin >> a;

    if (a == 1)
    {
      int i, x;
      cin >> i >> x;
      i--;
      if (mp.count(i) > 0)
      {
        diff = x - mp[i];
      }
      else
      {
        diff = x - prev;
      }
      sum += diff;
      cout << sum << endl;
      mp[i] = x;
    }
    else
    {
      int x;
      cin >> x;
      cout << x * n << endl;
      sum = x * n;
      prev = x;
      mp.clear();
    }
  }
}
