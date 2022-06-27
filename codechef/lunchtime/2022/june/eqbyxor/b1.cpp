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

//.....................................

//.....................................

void suraj()
{
  int a, b, n;
  cin >> a >> b >> n;

  if (a == b)
  {
    cout << 0 << endl;
    return;
  }

  vector<int> ans(30, 0ll);
  for (int i = 0; i < 30; i++)
  {
    int bina = (a >> i);
    int binb = (b >> i);
    int xorab = bina ^ binb;
    if (xorab & 1ll) // ie if first(0th) bit is set
    {
      // => xorab has its first bit set to 1.
      // => both have different values at location i
      // => ans[i] = 1. then after the operation a[i] will change
      ans[i] = 1ll;
    }
    else
    {
      // bina and binb ka first bit is same.
      // a[i] and b[i] are same, so a[i] should not change
      // ans[i] = 0
      ans[i] = 0ll;
    }
  }

  int ansVal = 0ll;
  for (int i = 0; i < 30; i++)
  {
    if (ans[i])
    {
      ansVal += (1ll << i);
    }
  }

  // find the max set bit for n.
  int tempa = 1ll;
  while (tempa < n)
  {
    tempa *= 2ll;
  }
  if (tempa > n)
    tempa /= 2;

  // if (ansVal > (tempa + tempa - 1))
  // {
  //   cout << -1ll << endl;
  // }
  // else if ((ansVal <= (tempa + tempa - 1)) && (ansVal >= (n)))
  // {
  //   cout << 2ll << endl;
  // }
  // else if (ansVal < n)
  // {
  //   cout << 1ll << endl;
  // }
  if (tempa == n)
  {
    // ie n is a power of 2
    // 1 to n-1 => 1 to tempa-1
    if (ansVal >= tempa)
    {
      cout << -1 << endl;
    }
    else
    {
      cout << 1 << endl;
    }
  }
  else
  {
    // tempa < n
    //=> we can choose tempa and bits below
    if (ansVal > tempa + tempa - 1)
    {
      cout << -1ll << endl;
    }
    else if ((ansVal <= tempa + tempa - 1) && (ansVal >= n))
    {
      cout << 2 << endl;
    }
    else if (ansVal < n)
    {
      cout << 1ll << endl;
    }
  }
}
