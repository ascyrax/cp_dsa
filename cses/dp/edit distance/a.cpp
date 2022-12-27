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

void suraj()
{
  string a, b;
  cin >> a >> b;
  int lena = a.size();
  int lenb = b.size();

  vector<vector<int>> dp(lena + 1, vector<int>(lenb + 1, 1e9));
  // 1. state
  // dp[i][j] = min edit distance between a[0...i] and b[0...j]

  // 3. base case
  for (int j = 0; j <= lenb; j++)
    dp[0][j] = min(dp[0][j], j);
  for (int i = 0; i <= lena; i++)
    dp[i][0] = min(dp[i][0], i);
  // 2. transition
  for (int i = 1; i <= lena; i++)
  {
    for (int j = 1; j <= lenb; j++)
    {
      if (a[i - 1] == b[j - 1])
      {
        dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
      }
      else
      {
        dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);     // delete last char of a
        dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);     // delete last char of b
        dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1); // modify last char of a to b or vice-versa
      }
    }
  }

  // for (int i = 0; i <= lena; i++)
  // {
  //   for (int j = 0; j <= lenb; j++)
  //     cout << dp[i][j] << " ";
  //   cout << endl;
  // }

  // 4. final subproblem
  cout << dp[lena][lenb] << endl;
}
