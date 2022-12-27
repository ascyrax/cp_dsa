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

      startTime = (double)clock();

  freopen("input_4.in", "r", stdin);
  freopen("output_4b.out", "w", stdout);

  // cout << setprecision(15) << fixed;

  int t = 1;

  // cin >> t;

  for (int i = 1; i <= t; i++)
  {

    // cout<<"Case #"<<i<<": ";

    // cout << "start time : " << gct() << endl;
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

  vector<vector<int>> dp(x + 1, vector<int>(n + 1, 0));
  // dp[i][j] = no of ordered ways of forming the sum i using the first j coins
  // dp[0][0] = 1;
  for (int i = 0; i <= x; i++)
  {
    // cout << "i: " << i << endl;
    for (int j = 0; j <= n; j++)
    {
      if (i == 0)
      {
        dp[i][j] = 1;
        continue;
      }
      // cout << "j: " << j << endl;
      // say coins[k] is the last coin for sum
      for (int k = 1; k <= j; k++)
      {
        // cout << "k: " << k << endl;
        int coin = coins[k - 1];
        if (i - coin >= 0)
          dp[i][j] += dp[i - coin][k];
        dp[i][j] %= mod;
      }
    }
  }
  // cout << "dp:" << endl;
  // for (int i = 0; i <= x; i++)
  // {
  //   for (int j = 0; j <= n; j++)
  //     cout << dp[i][j] << " ";
  //   cout << endl;
  // }
  // cout << "hi" << endl;

  cout << dp[x][n] << endl;
  // cout << "end time : " << gct() << endl;
}
