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
int n, q;

vector<int> v;
//.....................................
bool check(int m, vector<int> &v)
{
  int n = v.size();
  int val = q;

  for (int i = n - m; i <= n - 1; i++)
  {
    if (v[i] > val)
    {
      if (val == 0)
      {
        return false;
      }
      else
        val--;
    }
  }
  return true;
}
//.....................................

void suraj()
{
  cin >> n >> q;
  v = vector<int>(n);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }

  int l = 0, r = n;
  int m = l + (r - l) / 2;
  while (l < r)
  {
    m = l + (r - l) / 2;

    if (check(m, v))
    {
      if (r == l + 1)
      {
        if (check(r, v))
        {
          l = r;
          break;
        }
        else
        {
          l = l;
          break;
        }
      }
      else
        l = m;
    }
    else
    {
      r = m - 1;
    }
  }
  vector<int> ans(n, 0);
  for (int i = n - l; i <= n - 1; i++)
    ans[i] = 1;
  for (int i = 0; i < n - l; i++)
  {
    if (v[i] <= q)
      ans[i] = 1;
  }
  for (auto el : ans)
    cout << el;
  cout << endl;
}
