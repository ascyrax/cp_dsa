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
  int r, c;
  cin >> r >> c;

  vector<vector<int>> dp(r, vector<int>(c, -1));
  for (int i = 0; i < r / 2; i++)
  {
    for (int j = 0; j < c / 2; j++)
    {
      cout << "i: " << i << " , j: " << j << endl;
      if (i == 0 && j == 0)
        dp[i][j] = 1;
      else if (j == 0)
        dp[i][j] = (dp[i - 1][j] + 1) % 2;
      else if (i == 0)
        dp[i][j] = (dp[i][j - 1] + 1) % 2;
      cout << "dp[i][j]: " << dp[i][j] << endl;
      // bottom left quad
      dp[r - 1 - i][j] = dp[i][j];
      // top right quad
      dp[i][c - 1 - j] = dp[i][j];
      // bottom right quad
      dp[r - 1 - i][c - 1 - j] = dp[i][j];
    }
  }
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
      cout << dp[i][j] << " ";
    cout << endl;
  }
}
