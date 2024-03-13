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

// int dp[10001][3];
void suraj()
{
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }
  vector<vector<int>> dp(n, vector<int>(3, inf));
  int del[3] = {-1, 0, 1};

  dp[0][0] = (int)pow(2, abs(1 - 0));
  dp[0][1] = (int)pow(2, abs(1 - 1));
  dp[0][2] = (int)pow(2, abs(1 - 2));
  for (int i = 1; i <= n - 1; i++)
  {
    for (int j = 0; j <= 2; j++)
    {
      // dp[i][j] = inf;
      for (int k = 0; k <= 2; k++)
      {
        if (__gcd(v[i] + del[j], v[i - 1] + del[k]) == 1)
        {
          if (dp[i - 1][k] < inf)
          {
            dp[i][j] = min(dp[i][j], dp[i - 1][k] + (int)pow(2, abs(1 - j)));
            dp[i][j] %= mod;
          }
        }
      }
      // if (dp[i][j] != inf)
    }
  }

  int ans = min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
  cout << ans << endl;
}
