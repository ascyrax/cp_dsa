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

  // ioss

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
vector<vector<int>> grid;
//.....................................

//.....................................

void suraj()
{
  int n, m;
  cin >> n >> m;
  grid = vector<vector<int>>(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> grid[i][j];
    }
  }

  vector<vector<pair<bool, int>>> dp(n, vector<pair<bool, int>>(1024, make_pair(false, -1)));
  // dp[i][j] = till the ith row, whether the xor j is possible or not, if yes then what was the index of the element chosen in the last i.e. the ith row.

  for (int k = 0; k < m; k++)
  {
    dp[0][grid[0][k]] = make_pair(true, k);
  }
  // for (int i = 0; i < n; i++)
  // {
  //   for (int j = 0; j <= 20; j++)
  //   {
  //     cout << dp[i][j].first << " " << dp[i][j].second << " , ";
  //   }
  //   cout << endl;
  // }
  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j <= 1023; j++)
    {
      for (int k = 0; k < m; k++)
      {
        int val = grid[i][k] ^ j;
        if (dp[i - 1][val].first)
        {
          dp[i][j] = make_pair(dp[i - 1][val].first, k);
          break;
        }
      }
    }
  }

  for (int j = 1; j <= 1023; j++)
  {
    if (dp[n - 1][j].first)
    {
      int totXor = j;
      vector<int> ans;
      ans.pb(dp[n - 1][j].second);
      totXor ^= grid[n - 1][dp[n - 1][j].second];
      for (int i = n - 2; i >= 0; i--)
      {
        ans.pb(dp[i][totXor].second);
        totXor ^= grid[i][dp[i][totXor].second];
      }
      reverse(ans.begin(), ans.end());
      cout << "TAK" << endl;
      for (auto el : ans)
        cout << el + 1 << " ";
      cout << endl;
      return;
    }
  }

  cout << "NIE" << endl;
}
