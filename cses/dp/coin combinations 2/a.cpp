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
  int n, x;
  cin >> n >> x;

  vector<int> coins(n);
  for (int &i : coins)
    cin >> i;

  // dp[i][j] = no of distinct ordered ways to form the sum i with the jth coin being the last coin.
  vector<vector<int>> dp(x + 1, vector<int>(n, 0));

  // base case
  // for (int i = 0; i <= x; i++)
  //   dp[i][0] = 1;
  dp[0][0] = 1;

  for (int i = 1; i <= x; i++)
  {
    for (int j = 0; j < n; j++)
    {
      for (int k = 0; k <= j; k++)
      {
        // cout << i << " " << j << " " << k << endl;
        if (i - coins[j] >= 0)
          dp[i][j] += dp[i - coins[j]][k];
        dp[i][j] %= mod;
      }
    }
  }

  // for (int i = 0; i < dp.size(); i++)
  // {
  //   for (int j = 0; j < dp[i].size(); j++)
  //   {
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  int ans = 0;
  for (int j = 0; j < n; j++)
  {
    ans += dp[x][j];
    ans %= mod;
  }
  cout << ans << endl;
}