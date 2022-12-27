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
  int n, x;
  cin >> n >> x;
  vector<int> ans(n + 1);
  for (int i = 1; i <= n; i++)
  {
    ans[i] = i;
  }
  ans[1] = x;
  ans[n] = 1;

  if (n == x)
  {
    for (int i = 1; i <= n; i++)
      cout << ans[i] << " ";
    cout << endl;
    return;
  }
  // else
  //   ans[x] = n;
  // int evenPos = n / 2;
  // if (n % 2 == 0)
  //   evenPos--;

  // int evenValLeft = n / 2;
  // if (x % 2 == 0)
  //   evenValLeft--;

  // if (evenPos != evenValLeft)
  // {
  //   cout << -1 << endl;
  //   return;
  // }

  if (n % x == 0)
  {
    for (int i = x; i < n; i += x)
    {
      if (i + x <= n)
      {
        ans[i] = i + x;
      }
    }
    for (int i = 1; i <= n; i++)
      cout << ans[i] << " ";
    cout << endl;
  }
  else if (n % x != 0)
  {
    cout << -1 << endl;
  }
}
