// @author: ascyrax
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl "\n"
#define ioss                   \
  ios::sync_with_stdio(false); \
  cin.tie(0);
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

  // freopen("input_4.in", "r", stdin);
  // freopen("output_4suraj.out", "w", stdout);

  // cout << setprecision(15) << fixed;

  int t = 1;

  // cin >> t;
  // cout << "start time : " << gct() << endl;
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
// int mod = 998244353;
//.....................................

//.....................................

//.....................................

void suraj()
{
  int mod = 1e9 + 7;
  int n, x;
  cin >> n >> x;
  vector<int> coins(n);
  for (int i = 0; i < n; i++)
  {
    cin >> coins[i];
  }

  vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
  // dp[i][j] = no of ordered ways of forming the sum j using the first i coins
  // dp[0][0] = 1;
  // for (int i = 0; i <= x; i++)
  // {
  //   // cout << "i: " << i << endl;
  //   for (int j = 0; j <= n; j++)
  //   {
  //     if (i == 0)
  //     {
  //       dp[i][j] = 1;
  //       continue;
  //     }
  //     if (j - 1 >= 0)
  //       dp[i][j] = dp[i][j - 1];
  //     int coin = coins[j - 1];
  //     if (i - coin >= 0)
  //       dp[i][j] += dp[i - coin][j];
  //     dp[i][j] %= mod;
  //   }
  // }
  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= x; j++)
    {
      if (j == 0)
      {
        dp[i][j] = 1;
        continue;
      }
      if (i - 1 >= 0)
        dp[i][j] = dp[i - 1][j];
      int coin = coins[i - 1];
      if (j - coin >= 0)
        dp[i][j] += dp[i][j - coin];
      dp[i][j] %= mod;
    }
  }

  cout << dp[n][x] << endl;

  // cout << "end time : " << gct() << endl;
}
