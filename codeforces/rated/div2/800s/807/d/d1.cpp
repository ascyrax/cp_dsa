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
  string s, t;
  cin >> s >> t;

  vector<char> vs, vt;
  vs.pb(s[0]);
  vt.pb(t[0]);
  char prev = s[0];
  for (int i = 0; i < n; i++)
  {
    if (s[i] != prev)
    {
      vs.pb(s[i]);
      prev = s[i];
    }
  }
  prev = t[0];
  for (int i = 0; i < n; i++)
  {
    if (t[i] != prev)
    {
      vt.pb(t[i]);
      prev = t[i];
    }
  }
  if (vs != vt)
  {
    cout << -1 << endl;
    return;
  }
  int ps = 1;
  int ans = 0;
  for (int i = 1; i <= n - 2; i++)
  {
    if (t[i] == s[ps])
    {
      ans--;
    }
    if (s[ps] != t[i])
    {
      // find first instance of t[i] in s, to the right of index i.
      for (; ps <= n - 1; ps++)
      {

        if (s[ps] = t[i])
          break;
        s[ps] = t[i];
      }
      int diff = ps - i;
      ans += 2 * diff;
    }
  }
  cout << ans << endl;
}
