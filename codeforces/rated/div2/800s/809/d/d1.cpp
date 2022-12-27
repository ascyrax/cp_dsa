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
  int n, k;
  cin >> n >> k;
  int mn = inf;
  int mx = -inf;
  vector<set<int>> grid(3001, set<int>());
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    for (int i = 1; i <= k; i++)
    {
      grid[a].insert(a / i);
      if (a / i == 0)
        break;
    }
  }
  // cout << "grid" << endl;
  // for (int i = 0; i <= 11; i++)
  // {
  //   for (auto el : grid[i])
  //     cout << el << " ";
  //   cout << endl;
  // }
  int ans = inf;
  for (int i = 0; i <= 3000; i++)
  {
    // cout << "i: " << i << endl;
    int mn = inf, mx = -inf;
    for (int j = 1; j <= 3000; j++)
    {
      if (grid[j].size())
      {
        // cout << "j: " << j << endl;
        // find the closes no to i
        auto loc = grid[j].upper_bound(i);
        if (loc == grid[j].end())
        {
          --loc;
          mn = min(mn, *loc);
          mx = max(mx, *loc);
        }
        else if (loc == grid[j].begin())
        {
          // cout << "elseif" << endl;
          // --loc;
          mn = min(mn, *loc);
          mx = max(mx, *loc);
        }
        else
        {
          int r = *loc;
          --loc;
          int l = *loc;
          if (r - i <= i - l)
          {
            mn = min(mn, r);
            mx = max(mx, r);
          }
          else
          {
            mn = min(mn, l);
            mx = max(mx, l);
          }
        }
      }
    }
    // cout << "mn: " << mn << " , mx: " << mx << endl;
    ans = min(ans, mx - mn);
  }
  cout << ans << endl;
}
