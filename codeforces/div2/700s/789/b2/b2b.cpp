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

  string v;
  cin >> v;

  int cnt = 0;
  vector<int> ans(n);
  int prev = -1;
  for (int i = 0; i < n; i += 2)
  {
    // cout << "i: " << i << endl;
    if (v[i] == v[i + 1])
    {
      prev = v[i] - '0';
      break;
    }
  }
  if (prev == -1)
    prev = 0;
  // cout << "prev: " << prev << endl;
  for (int i = 0; i < n; i += 2)
  {
    if (v[i] != v[i + 1])
      cnt++;
    else
      prev = v[i] - '0';
    ans[i] = prev;
    ans[i + 1] = prev;
  }
  cout << cnt << " ";
  cnt = 1;
  for (int i = 1; i < n; i++)
  {
    if (ans[i] != ans[i - 1])
    {
      cnt++;
    }
  }
  cout << cnt << endl;
}
