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
  int l, r, x;
  cin >> l >> r >> x;

  int a, b;
  cin >> a >> b;

  int d = abs(a - b);
  if (d == 0)
    cout << 0 << endl;
  else if (d >= x)
    cout << 1 << endl;
  else
  {
    int del = x - d;
    int al = a - l;
    int ar = r - a;
    int bl = b - l;
    int br = r - b;
    int lr = r - l;
    if (bl >= x && br >= x)
    {
      // if(al>=x || ar>=x) // this will always hold
      cout << 2 << endl;
    }
    else if (bl >= x)
    {
      if (al >= x)
        cout << 2 << endl;
      else if (ar >= x)
        cout << 3 << endl;
      else
        cout << -1 << endl;
    }
    else if (br >= x)
    {
      if (ar >= x)
        cout << 2 << endl;
      else if (al >= x)
        cout << 3 << endl;
      else
        cout << -1 << endl;
    }
    else
    {
      cout << -1 << endl;
    }
  }
}
