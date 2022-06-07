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

//...............................

//...............................

void suraj()
{
  string s;
  cin >> s;

  int lens = s.size();

  // int l = 0, r = lens;

  // while (l < r)
  // {
  //   int m = l + (r - l) / 2;

  // }
  s = "R" + s;
  int prev = 0;
  int curr = 1;
  int ans = 0;
  for (int i = 1; i <= lens; i++)
  {
    if (s[i] == 'R')
    {
      int diff = i - prev;
      prev = i;
      ans = max(ans, diff);
    }
  }
  ans = max(ans, lens + 1 - prev);
  cout << ans << endl;
}

//................................