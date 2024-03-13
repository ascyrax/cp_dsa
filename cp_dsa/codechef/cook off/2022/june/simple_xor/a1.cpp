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
//.....................................

//.....................................
void print(int n)
{
  cout << n << " " << n + 1 << " " << n + 2 << " " << n + 3 << endl;
}
//.....................................

//.....................................

void suraj()
{
  int l, r;
  cin >> l >> r;

  int _l = l;

  l = r - 3;

  int val = 1;
  while (l >= 4)
  {
    val = 1;
    while (val < l)
    {
      val *= 2;
    }
    if (val > l)
      val /= 2;
    l %= val;
    // cout << "val = " << val << endl;
    // cout << "l = " << l << endl;
  }

  if (l == 0 || l == 2)
  {
    print(l);
  }
  else if (l == 1 || 3)
  {
    if (_l <= r - 4)
      print(r - 4);
    else
      cout << -1 << endl;
  }
}
