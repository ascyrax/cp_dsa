// @author: ascyrax
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl "\n"
#define ioss                   \
  ios::sync_with_stdio(false); \
  cin.tie(0);
// #define int long long
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
// int inf = 1e18;
int mod = 1e9 + 7;
// int mod = 998244353;
//.....................................

//.....................................

//.....................................

void suraj()
{
  int n, x;
  cin >> n >> x;
  vector<int> prices(n + 1), pages(n + 1);
  for (int i = 0; i < n; i++)
    cin >> prices[i + 1];
  for (int i = 1; i <= n; i++)
    cin >> pages[i];

  vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
  // 1. state : dp[i][j] = max no of pages from the first i books using the price j

  // 2. transition
  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j <= x; j++)
    {
      if (j - prices[i] >= 0)
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - prices[i]] + pages[i]);
      else
        dp[i][j] = dp[i - 1][j];
    }
  }

  // 3. base case
  // all zeros for no of books = 0

  // 4. final subproblem
  cout << dp[n][x] << endl;
}
