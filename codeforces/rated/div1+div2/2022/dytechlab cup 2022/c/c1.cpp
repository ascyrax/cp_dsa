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
  int n;
  cin >> n;

  int ra, ca, rb, cb, rc, cc;
  cin >> ra >> ca >> rb >> cb >> rc >> cc;

  int x, y;
  cin >> x >> y;

  int xdiff, ydiff;

  int xmid, ymid;

  if (ra == rb)
  {
    if (ca == cc)
    {
      // cout << "if" << endl;
      xmid = ra;
      ymid = ca;
      xdiff = abs(x - ra);
      ydiff = abs(y - ca);
    }
    else if (cb == cc)
    {
      xmid = rb;
      ymid = cb;
      xdiff = abs(x - rb);
      ydiff = abs(y - cb);
    }
  }
  else if (rb == rc)
  {
    if (cb == ca)
    {
      xmid = rb;
      ymid = cb;
      xdiff = abs(x - rb);
      ydiff = abs(y - cb);
    }
    else if (cc == ca)
    {
      xmid = rc;
      ymid = cc;
      xdiff = abs(x - rc);
      ydiff = abs(y - cc);
    }
  }
  else if (ra == rc)
  {
    if (ca == cb)
    {
      xmid = ra;
      ymid = ca;
      xdiff = abs(x - ra);
      ydiff = abs(y - ca);
    }
    else if (cc == cb)
    {
      xmid = rc;
      ymid = cc;
      xdiff = abs(x - rc);
      ydiff = abs(y - cc);
    }
  }

  if (xmid == 1 && ymid == 1)
  {
    if (x == 1 || y == 1)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
    return;
  }
  if (xmid == 1 && ymid == n)
  {
    if (x == 1 || y == n)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
    return;
  }
  if (xmid == n && ymid == n)
  {
    if (x == n || y == n)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
    return;
  }
  if (xmid == n && ymid == 1)
  {
    if (x == n || y == 1)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
    return;
  }

  if (xdiff % 2 == 1 && ydiff % 2 == 1)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
}
