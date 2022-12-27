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

  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  int ans = (v[n - 1] - v[0]) + (v[n - 1] - v[n - 2]);

  for (int i = 1; i <= n - 2; i++)
  {
    // bag 1 -> v[0]
    // bag 2 -> v[i+1] .. v[n-1]
    // bag 3 -> v[1] .. v[i]
    ans = max(ans, (v[i + 1] - v[0]) + (v[i + 1] - v[i]));
  }

  for (int i = n - 3; i >= 0; i--)
  {
    // bag 1 -> v[n-1]
    // bag 2 => v[0]...v[i]
    // bag 3 -> v[i+1]..v[n-2]
    ans = max(ans, (v[n - 1] - v[i]) + (v[i + 1] - v[i]));
  }

  cout << ans << endl;
}
