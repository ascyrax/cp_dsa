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

//.....................................

//.....................................

void suraj()
{
  int n, x;
  cin >> n >> x;
  vector<int> v(n);
  for (int &i : v)
    cin >> i;

  map<int, int> m;

  int mn = 2e5, mx = 0;

  int sum = 0;

  for (int i = 0; i < n; i++)
  {
    mn = min(mn, v[i]);
    mx = max(mx, v[i]);
    m[v[i]]++;
    if (i == 0)
      continue;

    sum += abs(v[i] - v[i - 1]);
  }

  cout << "sum = " << sum << endl;

  // sum+=()

  if (x <= mn)
  {
    sum += (x - 1);
    sum += min(abs(v[0] - x), abs(v[n - 1] - x));
    // sum += (mn + 1 - 1);
  }
  else if (x > mn && x < mx)
  {
    // assumning x = mn-1
    if (v[0] == mn || v[n - 1] == mn)
    {
      sum += ((mn - 1) - 1);
      sum += (mn - (mn - 1));
    }
    else
    {
      sum += ((mn - 1) - 1);
      sum += (mn - (mn - 1));
      sum += (mn + 1 - 1);
      sum -= (mn + 1) - (mn);
    }
  }
  else if (x >= mx)
  {
    if (v[0] == mn || v[n - 1] == mn)
    {
      sum += ((mn - 1) - 1);
      sum += (mn - (mn - 1));
    }
    else
    {
      sum += ((mn - 1) - 1);
      sum += (mn - (mn - 1));
      sum += (mn + 1 - 1);
      sum -= (mn + 1) - (mn);
    }

    if (v[0] == mx || v[n - 1] == mx)
    {
      sum += (x - (mx + 1));
      sum += (mx + 1 - mx);
    }
    else
    {
      sum += (x - (mx + 1));
      sum += (mx + 1 - (mx));
      sum += (x - (mx - 1));
    }
    // assumning x = mn-1
    // sum += ((mn - 1) - 1);
    // sum += (mn - (mn - 1));
    // sum += (mn + 1 - 1);
    // // now assuming x = x
    // sum += (x - (mx + 1));
    // sum += ((mx + 1) - mx);
    // sum += ((mx + 1) - (mx - 1));
  }

  cout << sum << endl;
}
