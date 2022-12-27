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
map<pair<int, int>, int> dp;
map<pair<int, int>, bool> dpFlag;

int dfs(int sum, bool flag)
{
  cout << "sum = " << sum << " , flag = " << flag << endl;
  if (dpFlag[make_pair(sum, flag)])
  {
    cout << "dpFlag[make_pair(sum, flag) = true." << endl;
    return dp[make_pair(sum, flag)];
  }

  dpFlag[make_pair(sum, flag)] = true;

  // cout << sum << " " << flag << endl;
  for (int i = 1; i <= k; i++)
  {
    if (sum - i < 0)
      break;
    if (flag == true || i >= d)
      dp[make_pair(sum, flag)] += dfs(sum - i, true);
    else
      dp[make_pair(sum, flag)] += dfs(sum - i, false);
  }
  if (sum == 0 && (flag == true))
  {
    cout << "if" << endl;
    dp[make_pair(sum, flag)]++;
    dp[make_pair(sum, flag)] %= mod;
  }
  cout << "dp[make_pair(sum, flag)] = " << dp[make_pair(sum, flag)] << endl;
  return dp[make_pair(sum, flag)];
}

//.....................................

void suraj()
{
  cin >> n >> k >> d;

  // dp = vector<int>(n + 1, 0);
  // dpFlag = vector<bool>(n + 1, false);

  dfs(n, false);

  // cout << ans << endl;
  cout << dp[make_pair(n, true)] << endl;
}
