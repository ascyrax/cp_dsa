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

  cin >> t;

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
  int n;
  cin >> n;
  vector<int> v(n);
  int mn = inf;
  for (int &i : v)
  {
    cin >> i;
    mn = min(mn, i);
  }
  int ans = 0;
  mn = min(mn, 0ll);

  ans = abs(mn);
  for (int i = 0; i < n; i++)
  {
    v[i] += abs(mn);
  }

  int left = v[0];
  ans += left;
  for (int i = 0; i < n; i++)
  {
    if (v[i] <= left)
    {
      left = v[i];
      v[i] = 0;
    }
    else if (v[i] > left)
    {
      v[i] -= left;
    }
    if (left == 0)
      break;
  }
  int right = v[n - 1];
  ans += right;
  for (int i = n - 1; i >= 0; i--)
  {
    if (v[i] <= right)
    {
      right = v[i];
      v[i] = 0;
    }
    else if (v[i] > right)
    {
      v[i] -= right;
    }
    if (right == 0)
      break;
  }
}
