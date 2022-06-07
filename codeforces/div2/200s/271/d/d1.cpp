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

int k;
signed main()
{

  ioss

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
int mod = 1e9 + 7;
int dp[100001];
//.....................................

void suraj()
{

  int t, k;
  cin >> t >> k;

  // dp[i] = no of ways to eat i flowers if Marmot eat white flowers only in groups of k.

  dp[1] = 1;
  dp[k]++;

  for (int i = 2; i <= 1e5; i++)
  {
    if (i - 1 >= 0)
    {
      dp[i] += dp[i - 1];
      dp[i] %= mod;
    }
    if (i - k >= 0)
    {
      dp[i] += dp[i - k];
      dp[i] %= mod;
    }
  }

  // for (int i = 0; i <= 5; i++)
  //   cout << dp[i] << " ";
  // cout << endl;

  for (int i = 1; i <= 1e5; i++)
  {
    dp[i] += dp[i - 1];
    dp[i] %= mod;
  }

  for (int i = 0; i < t; i++)
  {
    int a, b;
    cin >> a >> b;

    cout << (dp[b] - dp[a - 1] + mod) % mod << endl;
  }
}
