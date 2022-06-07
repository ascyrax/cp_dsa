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
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &i : a)
    cin >> i;

  // dp[l][r][1] = max(dp[l+1][r][0] - a[l],dp[l][r-1][0]-a[r]);
  // dp[l][r][0] = sth similar.

  // ans = dp[0][n-1][]

  int dp[n][n][2];

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      dp[i][j][0] = dp[i][j][1] = 0;
    }
  }

  for (int i = 0; i < n; i++)
  {
    dp[i][i][0] = a[i];
    dp[i][i][1] = -a[i];
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {

      dp[i][j][0] = max(dp[i + 1][j][1] + a[i], dp[i][j - 1][1] + a[j]);
      dp[i][j][1] = min(dp[i + 1][j][1] - a[i], dp[i][j - 1][1] - a[j]);
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      // cout << "i = " << i << " , j = " << j << endl;
      cout << dp[i][j][0] << " " << dp[i][j][1] << " , ";
    }
    cout << endl;
  }
  int flag = 0;
  if (n & 1)
    flag = 0;
  else
    flag = 1;

  cout << dp[0][n - 1][flag] << endl;
}

//................................

// int

// int

// int

// int
