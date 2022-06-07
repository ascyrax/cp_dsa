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

  // cin >> t;

  for (int i = 1; i <= t; i++)
  {

    // cout<<"Case #"<<i<<": ";

    suraj();
  }

  return 0;
}

int inf = 1e18;
//.....................................

//.....................................
int solve(int l, int r)
{
  int a = 1;
  while (a < l)
    a *= 2;
  if (a > l)
    a /= 2;

  int b = 1;
  while (b < r)
    b *= 2;
  if (b > r)
    b /= 2;

  if (a != b)
  {
    return b ^ (b - 1);
  }
  else
  {
    return solve(l ^ b, r ^ b);
  }
}
//.....................................

//.....................................

void suraj()
{
  int l, r;
  cin >> l >> r;

  if (l == r)
    cout << 0 << endl;
  else
    cout << solve(l, r) << endl;
}
