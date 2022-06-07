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
  int n, m;
  cin >> n >> m;

  int mx = max(n, m);
  int mn = min(n, m);

  // assume a rectangle.
  // i.e. col no > row no always.
  // viz row=mn and col=mx.

  if (mn == 1)
  {
    if (mx == 1)
      cout << 0 << endl;
    else if (mx == 2)
      cout << 1 << endl;
    else
      cout << -1 << endl;
    return;
  }

  // int ans = mx;

  if (mn == mx)
    cout << (mx - 1) + (mn - 1) << endl;
  else
  {
    if (mx == mn + 1)
      cout << (mx - 1) + (mn - 1) << endl;
    else if (mx - mn >= 2)
    {
      int diff = mx - mn;
      // cout << "diff = " << diff << endl;
      if (diff % 2 == 0)
        cout << (mx - 1) * 2 << endl;
      else
        cout << 2 * (mx - 1) - 1 << endl;
    }
  }

  // initially at (1,1)
  // finally at (nold,mold)
  // move down(row) n , and move right(col) m.

  // int diff = abs(n - m);
  // cout << "n = " << n << " , m = " << m << endl;
  // cout << "diff = " << diff << endl;
  // if (diff == 0)
  // {
  //   cout << n * 2 << endl;
  // }
  // else if (diff == 1)
  // {
  //   cout << n * 2 + 1 << endl;
  // }
  // else
  // {
  //   diff--;
  //   if (diff & 1)
  //     cout << n * 2 + 1 + ((diff / 2) * 4) << endl;
  //   else
  //     cout << n * 2 + 1 + ((diff / 2) * (4)) + 1 << endl;
  // }
}

//................................

// int

// int

// int

// int
