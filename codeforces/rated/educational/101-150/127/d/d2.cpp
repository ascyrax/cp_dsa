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

  int vmin = 2e5, vmax = 0;

  int arrSum = 0;

  for (int i = 0; i < n; i++)
  {
    vmin = min(vmin, v[i]);
    vmax = max(vmax, v[i]);
    if (i == 0)
      continue;
    arrSum += abs(v[i] - v[i - 1]);
  }

  int ans = 1e18, sum = 0;

  if (x <= vmin)
  {
    // all on the left
    sum += x - 1;
    sum += abs(v[0] - x);
    ans = min(ans, arrSum + sum);

    sum = 0;

    // all on the right
    sum += x - 1;
    sum += abs(v[n - 1] - x);
    ans = min(ans, arrSum + sum);

    sum = 0;

    // all btwn vmin & vmin+1
    sum += (x - 1);
    if (x < vmin)
      sum += (vmin - x) + ((vmin + 1) - 1);
    else if (x == vmin) // => we can have 2 vmin in our array. hence we can place 1-x between both the vmins.
      sum += (vmin - x) + (vmin - 1);
    ans = min(ans, arrSum + sum);

    sum = 0;
  }
  else if (x > vmin && x < vmax)
  {
    // all on the left
    x = vmin - 1;
    sum += x - 1;
    sum += abs(v[0] - x);
    ans = min(ans, arrSum + sum);

    sum = 0;

    // all on the right
    sum += x - 1;
    sum += abs(v[n - 1] - x);
    ans = min(ans, arrSum + sum);

    sum = 0;

    // all btwn vmin & vmin
    sum += (x - 1);
    sum += (vmin - x) + (vmin - 1);
    ans = min(ans, arrSum + sum);

    sum = 0;
  }
  else if (x >= vmax)
  {
    int xcopy = x;

    // all on the left
    x = vmin - 1;
    sum += x - 1;
    sum += abs(v[0] - x);
    ans = min(ans, arrSum + sum);

    sum = 0;

    // all on the right
    sum += x - 1;
    sum += abs(v[n - 1] - x);
    ans = min(ans, arrSum + sum);

    sum = 0;

    // all btwn vmin & vmin
    sum += (x - 1);
    sum += (vmin - x) + (vmin - 1);
    ans = min(ans, arrSum + sum);

    sum = 0;

    x = xcopy;
    // all on the left
    sum += x - (vmax + 1);
    sum += abs(v[0] - x);
    ans = min(ans, arrSum + sum);

    sum = 0;

    // all on the right
    sum += x - 1;
    sum += abs(v[n - 1] - x);
    ans = min(ans, arrSum + sum);

    sum = 0;

    // all btwn vmin & vmin
    sum += (x - 1);
    sum += (vmin - x) + (vmin - 1);
    ans = min(ans, arrSum + sum);
  }

  cout << ans << endl;
}
