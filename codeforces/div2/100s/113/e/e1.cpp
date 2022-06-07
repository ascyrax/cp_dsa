// @author: ascyrax
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl "\n"
#define ioss                   \
  ios::sync_with_stdio(false); \
  cin.tie(0);
// #define int long long
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

  // cin>>t;

  for (int i = 1; i <= t; i++)
  {

    // cout<<"Case #"<<i<<": ";

    suraj();
  }

  return 0;
}

//.....................................
// int dp[4][10000001];
int dp[10000001][4];
//.....................................

void suraj()
{
  int mod = 1e9 + 7;
  int n;
  cin >> n;

  // vector<vector<int>> dp(4, vector<int>(n + 1, 0));

  for (int i = 0; i < 4; i++)
  {
    if (i == 0)
    {
      // dp[0][0] = 1;
      // dp[0][1] = 0;
      dp[0][0] = 1;
    }
    else
    {
      dp[0][i] = 0;
      // dp[i][0] = 0;
      // dp[i][1] = 1;
    }
  }

  for (int i = 0; i <= n; i++)
  {
    // int sum = ((dp[1][i] + dp[0][i]) % mod + (dp[3][i] + dp[2][i]) % mod) % mod;
    int sum = ((dp[i][0] + dp[i][1]) % mod + (dp[i][2] + dp[i][3]) % mod) % mod;

    for (int j = 0; j < 4; j++)
    {
      dp[i + 1][j] = (sum - dp[i][j] + mod) % mod;
    }
  }

  // cout << dp[0][n] << endl;
  cout << dp[n][0] << endl;
}
