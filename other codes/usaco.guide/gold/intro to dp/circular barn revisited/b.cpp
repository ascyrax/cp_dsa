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
int dp[101][8];
//.....................................

void suraj()
{
  int n, nDoors;
  cin >> n >> nDoors;

  vector<int> v(n);
  for (int &i : v)
    cin >> i;

  vector<int> ps(n);
  ps[0] = v[0];

  for (int i = 1; i < n; i++)
    ps[i] = ps[i - 1] + v[i];

  cout << "PS" << endl;
  for (auto el : ps)
    cout << el << " ";
  cout << endl;

  // dp[i][j] => min amount of distance the cows need to travel if there is the jth door at the ith room.

  for (int door1 = 0; door1 < n; door1++)
  {
    for (int i = door1 + 1; i < n + door1; i++)
    {
      for (int j = 1; j < nDoors; j++)
      {
        for (int k = 0; k < i; k++)
        {
          if (k - 1 >= 0)
            dp[i % n][j] = min(dp[i % n][j], dp[k][j - 1] + (ps[i % n] - ps[k - 1]));
          else
            dp[i % n][j] = min(dp[i % n][j], dp[k][j - 1] + (ps[i % n] - 0));
        }
      }
    }
  }

  cout << "dp" << endl;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < nDoors; j++)
    {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }

  int ans = 1e18;
  for (int i = 0; i < n; i++)
    ans = min(ans, dp[i][nDoors - 1]);
  cout << ans << endl;
}
