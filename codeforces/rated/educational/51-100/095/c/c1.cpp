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

int inf = 1e18;
//.....................................

//.....................................

//.....................................

//.....................................

void suraj()
{
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }

  vector<vector<int>> dp(n, vector<int>(2, 0));

  // dp[i][0] = min no of skip points used by my friend if we together killed the first i monsters such that it was my turn while killing the ith monster.

  for (int i = 0; i < n; i++)
  {
    if (i - 2 >= 0)
    {
      dp[i][0] = min(dp[i - 1][1], dp[i - 2][1]);
      dp[i][1] = min(dp[i - 1][0] + v[i], dp[i - 2][0] + v[i - 1] + v[i]);
    }
    else if (i - 1 >= 0)
    {
      // => i = 1.
      dp[i][0] = dp[i - 1][1];
      dp[i][1] = dp[i - 1][1] + v[i];
    }
    else
    {
      // => i = 0
      dp[0][0] = inf; // since first session is my friends session
      dp[0][1] = v[0];
    }
  }

  cout << min(dp[n - 1][0], dp[n - 1][1]) << endl;
}
