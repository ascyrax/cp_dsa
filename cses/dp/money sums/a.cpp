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
void print(vector<bool> dp)
{
  cout << "dp: ";
  for (int i : dp)
    cout << i << " ";
  cout << endl;
}
//.....................................

void suraj()
{
  int n;
  cin >> n;
  vector<int> coins(n + 1);
  int sum = 0;
  for (int i = 1; i <= n; i++)
  {
    cin >> coins[i];
    sum += coins[i];
  }
  // cout << "sum " << sum << endl;

  vector<bool> dp(sum + 1, false);
  dp[0] = true;
  for (int i = 1; i <= n; i++)
  {
    int coin = coins[i];
    // cout << "coin " << coin << endl;
    for (int j = sum; j >= 0; j--)
    {
      // cout << "i " << i << " , j " << j << endl;
      // print(dp);
      // cout << "j - coin " << j - coin << endl;
      if ((j - coin) >= 0)
      {
        // cout << "if a" << endl;
        if (dp[j - coin])
        {
          // cout << "if b" << endl;
          dp[j] = true;
        }
      }
      // print(dp);
    }
  }
  vector<int> ans;
  for (int i = 1; i <= sum; i++)
    if (dp[i])
      ans.pb(i);
  cout << ans.size() << endl;
  for (auto el : ans)
    cout << el << " ";
  cout << endl;
}
