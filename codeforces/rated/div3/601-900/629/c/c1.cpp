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

//.....................................

void suraj()
{
  int n;
  cin >> n;

  string s;
  cin >> s;

  vector<int> a, b;

  a.pb(1);
  b.pb(1);

  bool flag = false;

  for (int i = 1; i < n; i++)
  {
    if (s[i] == '0')
    {
      a.pb(0);
      b.pb(0);
    }
    else if (s[i] == '1')
    {
      if (flag)
      {
        a.pb(0);
        b.pb(1);
      }
      else
      {
        a.pb(1);
        b.pb(0);
        flag = true;
      }
    }
    else if (s[i] == '2')
    {
      if (flag)
      {
        a.pb(0);
        b.pb(2);
      }
      else
      {
        a.pb(1);
        b.pb(1);
      }
    }
  }

  for (int i : a)
    cout << i;
  cout << endl;
  for (int i : b)
    cout << i;
  cout << endl;
}
