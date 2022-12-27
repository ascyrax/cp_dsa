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

//.....................................
int n;
vector<int> v;
int ans = 1e18;
int solve(int i, int j)
{
  int mn = min(v[i], v[j]);
  int mx = max(v[i], v[j]);

  int diff = mx - mn;
  // after diff shots on mx, both mx and mn will be equal
  if (mn - diff < 0)
  {
    return (mx + 1) / 2;
  }
  else
  {
    return diff + (mn - diff + mx - 2 * diff + 2) / 3;
  }
}

int solve2(int i, int j)
{
  // i == j-2.
  int shots = 0;
  shots = min(v[i], v[j]);
  shots += (max(v[i], v[j]) - min(v[i], v[j]) + 1) / 2;
  return shots;
}
//.....................................

void suraj()
{
  cin >> n;
  v = vector<int>(n);
  for (int &i : v)
    cin >> i;

  for (int i = 0; i < n - 1; i++)
  {
    ans = min(ans, solve(i, i + 1));

    // cout << "i = " << i << endl;
    // cout << "ans = " << ans << endl;
  }

  for (int i = 0; i <= n - 3; i++)
  {
    ans = min(ans, solve2(i, i + 2));
    // cout << "i = " << i << endl;
    // cout << "ans = " << ans << endl;
  }
  vector<int> temp = v;
  sort(temp.begin(), temp.end());

  ans = min(ans, (temp[0] + 1) / 2 + (temp[1] + 1) / 2);

  cout << ans << endl;
}
