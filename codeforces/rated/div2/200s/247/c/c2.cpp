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

  // cin>>t;

  for (int i = 1; i <= t; i++)
  {

    // cout<<"Case #"<<i<<": ";

    suraj();
  }

  return 0;
}

//.....................................
int n, k, d;
int mod = 1e9 + 7;
int dp[101][2];
map<pair<int, int>, int> visited;

int dfs(int sum, int flag)
{

  // cout << "sum = " << sum << " , flag = " << flag << endl;

  if (visited[make_pair(sum, flag)])
  {
    return dp[sum][flag];
  }

  visited[make_pair(sum, flag)] = true;

  if (sum == 0)
  {
    if (flag == 1)
      dp[sum][1] = 1;
    else
      dp[sum][0] = 0;
    return dp[sum][flag];
  }

  for (int i = 1; i <= k; i++)
  {
    // cout << "i = " << i << endl;
    if (sum - i < 0)
      break;

    if (i >= d)
    {
      // dp[sum][flag] += dp[sum - i][1];
      (dp[sum][flag] += dfs(sum - i, 1)) %= mod;
    }
    else
    {
      // dp[sum][flag] += dp[sum - i][flag];
      (dp[sum][flag] += dfs(sum - i, flag)) %= mod;
    }
  }
  return dp[sum][flag];
}

//.....................................

void suraj()
{
  cin >> n >> k >> d;
  // dp[i][0] means we still havent used any edge with weight>=d .
  // dp[i][1] means we have used atleast one edge with weight >=d .

  for (int i = 1; i <= n; i++)
  {
    visited[make_pair(i, 0)] = false;
    visited[make_pair(i, 1)] = false;
  }

  dfs(n, 0);

  // for (int i = 1; i <= n; i++)
  // {
  //   cout << dp[i][0] << "," << dp[i][1] << "    ";
  // }
  // cout << endl;

  cout << dp[n][0] << endl;
}
