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

void print(string s, vector<int> v)
{
  cout << s << endl;
  for (auto el : v)
    cout << el << " ";
  cout << endl;
}
void print(string s, set<int> st)
{
  cout << s << endl;
  for (auto el : st)
    cout << el << " ";
  cout << endl;
}
void print(string s, vector<pair<int, int>> vp)
{
  cout << s << endl;
  for (auto el : vp)
  {
    cout << el.first << " " << el.second << endl;
  }
}
int inf = 1e18;
int mod = 1e9 + 7;
// int mod = 998244353;
//.....................................

//.....................................

//.....................................

void suraj()
{
  int n;
  cin >> n;
  vector<int> v(n);
  int mx = 0, sum = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
    sum += v[i];
    mx = max(mx, v[i]);
  }
  if (n >= 4)
    cout << mx * n << endl;
  else if (n == 2)
  {
    cout << max(sum, abs(v[0] - v[1]) * 2) << endl;
  }
  else if (n == 3)
  {
    if (v[0] == mx || v[n - 1] == mx)
      cout << mx * 3 << endl;
    else
    {
      int ans = sum;
      // 0 2
      ans = max(ans, 3 * abs(v[0] - v[2]));
      // v[1] == mx
      // 0 1
      int a = abs(v[0] - v[1]);
      int b = v[2];
      int mx = max(a, b);
      ans = max(ans, mx * 3);
      // 1 2
      a = v[0];
      b = abs(v[1] - v[2]);
      mx = max(a, b);
      ans = max(ans, mx * 3);

      cout
          << ans << endl;
    }
  }
}
