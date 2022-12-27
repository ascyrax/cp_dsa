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

  // cin >> t;

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
int inf = 1e18;
int mod = 1e9 + 7;
// int mod = 998244353;
//.....................................

//.....................................

//.....................................

int dp[5000][5000][2];
void suraj()
{
  int n;
  cin >> n;
  vector<int> v(n);
  for (int &i : v)
    cin >> i;

  // dp[i][j][0] = score of A if he started first in the subarray v[i...j].
  // dp[i][j][1] = score of A if B started first in the subarray v[i...j].

  for (int len = 1; len <= n; len++) // len of the subarray
  {
    for (int index = 0; index < n; index++) // index
    {
      // BASE CASE
      if (len == 1)
      {
        dp[index][index][0] = v[index];
        dp[index][index][1] = 0;
        continue;
      }
      //  TRANSITION
      if (index + len - 1 < n)
      {
        dp[index][index + len - 1][0] = max(dp[index + 1][index + len - 1][1] + v[index], dp[index][index + len - 2][1] + v[index + len - 1]);
        dp[index][index + len - 1][1] = min(dp[index + 1][index + len - 1][0], dp[index][index + len - 2][0]);
      }
    }
  }

  // for (int i = 0; i <= n; i++)
  // {
  //   for (int j = 0; j <= n; j++)
  //   {
  //     cout << dp[i][j][0] << " " << dp[i][j][1] << " , ";
  //   }
  //   cout << endl;
  // }

  cout << dp[0][n - 1][0] << endl;
}
