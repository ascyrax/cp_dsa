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
  int n, a, b;
  cin >> n >> a >> b;
  int temp = a ^ b;
  int i = 1;
  int x = 0;
  // cout << "temp: " << temp << endl;
  while (i < (1ll << n))
  {
    if ((i & a) == 0ll && (i & b) == 0ll)
      x += i;
    else if (((i & a) == 0 && (i & b)) == 1)
      x += i;
    else if (((i & a) == 1 && (i & b) == 0))
      x += i;
    i *= 2ll;
  }
  cout << x << endl;
}
