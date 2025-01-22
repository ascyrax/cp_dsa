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

//...............................

//...............................

void suraj()
{
  int mod = 1e9 + 7;
  int h, w;
  cin >> h >> w;

  vector<string> grid(h);

  for (int i = 0; i < h; i++)
  {
    string row;
    cin >> row;
    grid[i] = row;
  }

  vector<vector<int>> dp(h, vector<int>(w, 0));
  dp[0][0] = 1;
  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      if (grid[i][j] == '.')
      {
        if (i - 1 >= 0)
          dp[i][j] += dp[i - 1][j];
        if (j - 1 >= 0)
          dp[i][j] += dp[i][j - 1];
      }
      dp[i][j] %= mod;
      // cout << "i= " << i << " , j = " << j << endl;
      // cout << dp[i][j] << endl;
    }
  }
  cout << dp[h - 1][w - 1] << endl;
}

//................................

// int

// int

// int

// int
