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
bool check(string sa, string sb)
{
  if (sa == sb)
  {
    return true;
  }
  if (sa == "00")
  {
    return false;
  }
  else if (sa == "01")
  {
    if (sb == "10")
      return false;
    else
      return true;
  }
  else if (sa == "10")
  {
    if (sb == "01")
      return false;
    else
      return true;
  }
  else if (sa == "11")
  {
    if (sb == "00")
      return true;
    else
      return false;
  }
}
//.....................................

void suraj()
{
  int n;
  cin >> n;
  string sa, sb;
  cin >> sa >> sb;
  int a0 = 0, a1 = 0, b0 = 0, b1 = 0;
  for (int i = 0; i < n; i++)
  {
    if (sa[i] == '0')
      a0++;
    else
      a1++;
  }
  for (int i = 0; i < n; i++)
  {
    if (sb[i] == '0')
      b0++;
    else
      b1++;
  }
  string la = sa.substr(0, 2);
  string ra = sa.substr(n - 2, 2);
  string lb = sb.substr(0, 2);
  string rb = sb.substr(n - 2, 2);
  if (b1 > 0)
  {
    if (a1 == 0)
      cout << "NO" << endl;
    else
    {
      // all elements of a can be converted into 1 i.e. 11....11
      // b1>0 && a1>0
      if (n == 2)
      {
        if (check(sa, sb))
          cout << "YES" << endl;
        else
          cout << "NO" << endl;
      }
      else if (n == 3)
      {
      }
      else
      {
        for (int i = 0; i < n; i++)
        {
          if (sb[i] == '0')
          {
            if (i + 2 < n)
              ; // ok
            else if (i - 2 >= 0)
              ; // ok
            else
            {
              cout << "NO" << endl;
              return;
            }
          }
        }
        cout << "YES" << endl;
      }
    }
  }
  else if (b1 == 0)
  {
    cout << "YES" << endl;
  }
}
