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
// int mod = 998244353;
//.....................................

//.....................................

//.....................................

void suraj()
{
  int mod = 1e9 + 7;
  int n;
  cin >> n;

  int sum = (n * (n + 1)) / 2;

  if ((sum & 1) == 1)
  {
    cout << 0 << endl;
    return;
  }

  vector<vector<int>> dp(sum / 2 + 1, vector<int>(n + 1, 0));
  // dp[i][j] = no of ways to form the sum i using the first j coins
  dp[0][0] = 1; // sum 0 using 0 coins
  for (int j = 1; j <= n; j++)
  {
    for (int i = 0; i <= sum / 2; i++)
    {
      if (i - j >= 0)
        dp[i][j] = dp[i][j - 1] + dp[i - j][j - 1];
      else
        dp[i][j] = dp[i][j - 1];
      dp[i][j] %= mod;
    }
  }

  // for (int i = 0; i <= sum / 2; i++)
  // {
  //   for (int j = 0; j <= n; j++)
  //   {
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  cout << dp[sum / 2][n - 1] << endl;
  // cout << dp[sum / 2][n] << endl;
  // cout << (dp[sum / 2][n] + (dp[sum/2][n])) / 2 << endl;
  // int ans = dp[sum / 2][n];
  // cout << ans / 2 << endl;
}
