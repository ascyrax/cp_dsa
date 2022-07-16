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
int mod = 1e9 + 7;
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
//.....................................
bool dp[4001][2001][2];
// dp[i][j][0] => is it possible to put j numbers in set A, from the first i numbers. where 0=> ith no is in set A, 1=> ith no is in setB.
//.....................................

//.....................................

void suraj()
{
  int n;
  cin >> n;
  vector<int> v(2 * n + 1);
  for (int i = 1; i <= 2 * n; i++)
  {
    cin >> v[i];
  }
  bool ans = false;
  for (int i = 1; i <= 2 * n; i++)
  {
    for (int j = 0; j <= min(i, 2 * n); j++)
    {

      if (i >= 2) // i.e i-1 >=1
      {
        if (v[i - 1] < v[i])
        {
          // doesnt matter which set the element v[i-1] belongs to
          dp[i][j][0] = dp[i - 1][j - 1][0] || dp[i - 1][j - 1][1];
          dp[i][j][1] = dp[i - 1][j][0] || dp[i - 1][j][1];
        }
        else if (v[i - 1] > v[i])
        {
          // element v[i-1] must belong to the same set as the element v[i] belongs to.
          dp[i][j][0] = dp[i - 1][j - 1][0];
          dp[i][j][1] = dp[i - 1][j][1];
        }
      }

      else if (i == 1)
      {
        if (j == 0)
        {
          dp[1][0][0] = false;
          dp[1][0][1] = true;
        }
        else if (j == 1)
        {
          dp[1][1][0] = true;
          dp[1][1][1] = false;
        }
        // else // since j>i(=1)
        // {
        //   dp[1][j][0] = false;
        //   dp[1][j][1] = false;
        // }
      }
    }
  }

  for (int i = n; i <= 2 * n; i++)
  {
    ans = ans || (dp[i][n][0] || dp[i][n][1]);
  }
  if (ans)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  for (int j = 0; j <= 2 * n; j++)
  {
    cout << dp[1][j][0] << " " << dp[1][j][1] << "   ,   ";
  }
  cout << endl;
  for (int j = 0; j <= 2 * n; j++)
  {
    cout << dp[2][j][0] << " " << dp[2][j][1] << "   ,   ";
  }
  cout << endl;
  for (int j = 0; j <= 2 * n; j++)
  {
    cout << dp[3][j][0] << " " << dp[3][j][1] << "   ,   ";
  }
  cout << endl;
  for (int j = 0; j <= 2 * n; j++)
  {
    cout << dp[4][j][0] << " " << dp[4][j][1] << "   ,   ";
  }
  cout << endl;
}
