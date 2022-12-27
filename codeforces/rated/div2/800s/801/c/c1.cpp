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

  cin >> t;

  for (int i = 1; i <= t; i++)
  {

    // cout<<"Case #"<<i<<": ";

    suraj();
  }

  return 0;
}

int inf = 1e18;
//.....................................

//.....................................
int n, m;
//.....................................
void printDP(vector<vector<pair<int, int>>> dp)
{

  cout << "dp" << endl;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << dp[i][j].first << " " << dp[i][j].second << "   ,   ";
    }
    cout << endl;
  }
}
void printGrid(vector<vector<int>> grid)
{
  cout << "grid" << endl;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }
}
//.....................................

void suraj()
{
  // int n, m;
  cin >> n >> m;
  vector<vector<int>> grid(n, vector<int>(m, 0));
  vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(m, pair<int, int>()));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> grid[i][j];
      dp[i][j] = make_pair(inf, -1 * inf);
    }
  }
  // cout << "a" << endl;
  dp[n - 1][m - 1] = make_pair(grid[n - 1][m - 1], grid[n - 1][m - 1]);
  // printGrid(grid);
  // printDP(dp);

  for (int i = n - 1; i >= 0; i--)
  {
    // cout << "i = " << i << endl;
    for (int j = m - 1; j >= 0; j--)
    {
      // cout << "j = " << j << endl;
      if ((i == n - 1) && (j == m - 1))
      {
        // cout << "else if 1" << endl;
        // bottom right corner
        // do nothing
        continue;
      }
      if (j == m - 1)
      {
        // cout << "else if 2" << endl;
        // rightmost column
        dp[i][j] = make_pair(dp[i + 1][j].first + grid[i][j], dp[i + 1][j].second + grid[i][j]);
        continue;
      }
      if (i == n - 1)
      {
        // cout << "else if 3" << endl;
        // bottommost row
        dp[i][j] = make_pair(dp[i][j + 1].first + grid[i][j], dp[i][j + 1].second + grid[i][j]);
        continue;
      }
      if ((j + 1 <= m - 1) && (i + 1 <= n - 1))
      {
        // cout << "if" << endl;
        int mn = min(dp[i + 1][j].first, dp[i][j + 1].first) + grid[i][j];
        int mx = max(dp[i + 1][j].second, dp[i][j + 1].second) + grid[i][j];
        dp[i][j] = make_pair(mn, mx);
        continue;
      }
    }
  }
  // cout << "b" << endl;

  int pathLen = m + (n - 1);
  if (pathLen & 1)
  {
    cout << "NO" << endl;
  }
  else
  {
    if (dp[0][0].first <= 0ll && dp[0][0].second >= 0ll)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
