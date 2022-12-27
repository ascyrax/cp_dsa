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

  ioss

      // startTime=(double)clock();

      // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);

      // cout << setprecision(15) << fixed;

      int t = 1;

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
int mod = 1e9 + 7;
// int mod = 998244353;
//.....................................

//.....................................

//.....................................

void suraj()
{
  int n, m;
  cin >> n >> m;
  vector<int> arr(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> arr[i];

  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
  // 1. state. dp[i][j] = no of arrays using the first j elements with i as the last element

  // 3. base cases
  // dp[0][0] = 1;

  // j=1
  if (arr[1] == 0)
    for (int i = 1; i <= m; i++)
      dp[i][1] = 1;
  else
    dp[arr[1]][1] = 1;

  // 2. transition
  for (int j = 2; j <= n; j++)
  {
    for (int i = 1; i <= m; i++)
    {
      if (arr[j] != 0)
        if (i != arr[j])
        {
          dp[i][j] = 0;
          continue;
        }

      dp[i][j] += dp[i - 1][j - 1];
      dp[i][j] += dp[i][j - 1];
      dp[i][j] %= mod;
      if (i + 1 <= m)
        dp[i][j] += dp[i + 1][j - 1];
      dp[i][j] %= mod;
    }
  }

  // for (int i = 0; i <= m; i++)
  // {
  //   for (int j = 0; j <= n; j++)
  //   {
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  // 4. final subproblem
  int ans = 0;
  for (int i = 1; i <= m; i++)
  {
    ans += dp[i][n];
    ans %= mod;
  }
  cout << ans << endl;
}
