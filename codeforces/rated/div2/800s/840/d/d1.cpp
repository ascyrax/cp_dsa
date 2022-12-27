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
// int mod = 998244353;
//.....................................

//.....................................
int dp[101][101][2];
void printdp()
{
  cout << "dp" << endl;
  for (int i = 1; i <= 5; i++)
  {
    for (int j = 1; j <= 5; j++)
    {
      cout << dp[i][j][0] << " " << dp[i][j][1] << "  ,  ";
    }
    cout << endl;
  }
}
//.....................................

void suraj()
{
  int mod = 1e9 + 7;
  int n, I, J, x, y;
  cin >> n >> I >> J >> x >> y;

  for (int i = 0; i <= 100; i++)
  {
    for (int j = 0; j <= 100; j++)
    {
      dp[i][j][0] = 0;
      dp[i][j][1] = 0;
    }
  }

  // state
  // dp[i][j][k]
  // printdp();
  // base case
  for (int i = 1; i <= 1; i++)
  {
    for (int j = 1; j < n; j++)
    {
      if (i == I)
      {
        if (j != x)
          continue;
      }
      else if (i == J)
      {
        if (j != y)
          continue;
      }
      dp[i][j][0] = 1;
      dp[i][j][1] = 1;
    }
  }

  // cout << dp[1][2][0] << endl;
  // printdp();

  // transition
  for (int i = 2; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {

      if (i == I)
      {
        if (j != x)
          continue;
      }
      else if (i == J)
      {
        if (j != y)
          continue;
      }
      // cout << i << " " << j << endl;
      // printdp();
      // k=0 ie increasing
      // dp[i][j][0] = ?
      for (int temp = 1; temp < j; temp++)
      {
        // cout << "dp[i-1][temp][0] " << dp[i - 1][temp][0] << endl;
        dp[i][j][0] += dp[i - 1][temp][0];
        dp[i][j][0] %= mod;
      }

      // k=1 ie decreasing
      for (int temp = j + 1; temp <= n; temp++)
      {
        dp[i][j][1] += dp[i - 1][temp][1];
        dp[i][j][1] %= mod;
        dp[i][j][1] += dp[i - 1][temp][0];
        dp[i][j][1] %= mod;
      }

      // int ab = dp[i][j][0] + dp[i][j][1];
      // dp[i][j][0] = ab;
      // dp[i][j][1] = ab;
      // cout << "after ";
      // printdp();
    }
  }

  int ans = 0;

  for (int j = 1; j <= n; j++)
  {
    // cout << dp[n][j][1] << endl;
    ans += dp[n][j][1];
    ans %= mod;
  }
  cout << ans << endl;
}
