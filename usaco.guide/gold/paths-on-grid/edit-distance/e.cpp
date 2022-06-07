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

  // cin >> t;

  for (int i = 1; i <= t; i++)
  {

    // cout<<"Case #"<<i<<": ";

    suraj();
  }

  return 0;
}

//.....................................
int dp[5001][5001];
//.....................................

void suraj()
{
  string a, b;
  cin >> a >> b;

  int lena = a.size();
  int lenb = b.size();

  int dpMin[lenb];
  for (int i = 1; i <= lenb; i++)
    dpMin[i] = 1e18;

  // dp[i][j] = min no of moves to make the first i chars of a equal to first j chars of b.

  for (int i = 1; i <= lena; i++)
  {
    for (int j = 1; j <= lenb; j++)
    {
      dpMin[j] = min(dpMin[j], dp[i][j]);
      dp[i][j] = min(dp[i][j], dpMin[j]); // dpMin[j] corresponds to dp[i=1 to i=lena][j].
    }
  }

  cout << dp[lena][lenb] << endl;
}
