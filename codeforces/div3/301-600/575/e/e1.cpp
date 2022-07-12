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
//.....................................

//.....................................

//.....................................

void suraj()
{
  int b, w;
  cin >> b >> w;

  int mx = max(b, w);
  int mn = min(b, w);
  vector<pair<int, int>> ans;

  if (mx > 3 * mn + 1)
  {
    cout << "NO" << endl;
    return;
  }
  else if (mn == 1)
  {
    if (mx == 1)
    {
      ans.pb(make_pair(2, 2));
      ans.pb(make_pair(1, 2));
    }
    else if (mx == 2)
    {
      ans.pb(make_pair(2, 2));
      ans.pb(make_pair(1, 2));
      ans.pb(make_pair(2, 1));
    }
    else if (mx == 3)
    {
      ans.pb(make_pair(2, 2));
      ans.pb(make_pair(1, 2));
      ans.pb(make_pair(2, 1));
      ans.pb(make_pair(2, 3));
    }
    else if (mx == 4)
    {
      ans.pb(make_pair(2, 2));
      ans.pb(make_pair(1, 2));
      ans.pb(make_pair(2, 1));
      ans.pb(make_pair(2, 3));
      ans.pb(make_pair(3, 2));
    }
  }
  else if (mn >= 2)
  {
    int q = mx / mn;
    int r = mx % mn;
    for (int i = 0; i < mn; i++)
    {
      ans.pb(make_pair(2 + 2 * i, 2));
      if (q == 1)
      {
        ans.pb(make_pair(2 + 2 * i - 1, 2));
      }
      else if (q == 2)
      {
        ans.pb(make_pair(2 + 2 * i - 1, 2));
        ans.pb(make_pair(2 + 2 * i, 2 - 1));
      }
      else if (q == 3)
      {
        ans.pb(make_pair(2 + 2 * i - 1, 2));
        ans.pb(make_pair(2 + 2 * i, 2 - 1));
        ans.pb(make_pair(2 + 2 * i, 2 + 1));
      }
      if (q == 1 || q == 2)
      {
        if (i < r)
        {
          ans.pb(make_pair(2 + 2 * i, 2 + 1));
        }
      }
      else if (q == 3 && r == 1 && i == mn - 1)
      {
        ans.pb(make_pair(2 + 2 * i + 1, 2));
      }
    }
  }

  cout << "YES" << endl;

  if (b > w)
  {
    for (auto el : ans)
    {
      cout << el.first << " " << el.second << endl;
    }
  }
  else
  {
    for (auto el : ans)
    {
      cout << el.first + 1 << " " << el.second << endl;
    }
  }
}
