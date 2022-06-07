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
  string s;
  cin >> s;
  int lens = s.size();

  if (lens == 1)
  {
    cout << "NO" << endl;
    return;
  }

  char prev = s[0];
  int a = 0, b = 0;
  if (prev == 'a')
    a++;
  else
    b++;
  for (int i = 1; i < lens; i++)
  {
    if (s[i] != prev)
    {
      if (a == 1 || b == 1)
      {
        cout << "NO" << endl;
        return;
      }
      a = 0;
      b = 0;
    }
    if (s[i] == 'a')
      a++;
    else
      b++;
    prev = s[i];
  }
  if (a == 1 || b == 1)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
}
