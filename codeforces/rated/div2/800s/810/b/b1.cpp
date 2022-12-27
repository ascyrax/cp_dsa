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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> grid(n, vector<int>());
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  for (int i = 0; i < m; i++)
  {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    grid[x].pb(y);
    grid[y].pb(x);
  }

  if (m % 2 == 0)
  {
    cout << 0 << endl;
  }
  else
  {
    // remove a guy who has odd no of friendships
    int ans = inf;
    vector<int> even;
    for (int i = 0; i < n; i++)
    {
      if (grid[i].size() == 0)
        continue;
      // cout << "I: " << i << endl;
      // cout << "grid[i].size(): " << grid[i].size() << endl;
      if ((grid[i].size() % 2) == 1)
      {
        ans = min(ans, a[i]);
      }
      else if ((grid[i].size() % 2) == 0)
      {
        // say i remove i => grid[i] people will miss a friend .
        int ansa = a[i];
        int ansb = inf;
        for (auto el : grid[i])
        {
          if ((grid[el].size()) % 2 == 0)
          {
            ansb = min(ansb, a[el]);
          }
        }
        ans = min(ans, ansa + ansb);
      }
    }
    cout << ans << endl;
  }
}
